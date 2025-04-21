#include <iostream>
#include <string>
#include <sstream>
#include<thread>
#include<chrono>
#include<mutex>
 
using namespace std;
int balance = 0;
mutex m;
//race condition
void add() {
	for (int i = 0; i < 1000000; i++) {
		balance++;
	}
} 
int balance2 = 0;
void add2() {
	//critical section
	m.lock();
	for (int i = 0; i < 1000000; i++) {
		balance2++;
	}
	m.unlock();
}
int main() {
	thread t1(add);
	thread t2(add);  
	t1.join();
	t2.join();
	cout << "balance" << balance<<endl;
	// with mutex
	thread t3(add2);
	thread t4(add2);  
	t3.join();
	t4.join();
	cout << "balance" << balance2 << endl;
	return 0;
}
//output 1
//balance1449902 without mutex
//balance2000000 with mutex
// 
//output 2
//balance1333417
//balance2000000
