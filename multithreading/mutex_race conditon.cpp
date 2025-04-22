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

#include <iostream>
#include <thread>
#include <chrono>
#include<mutex>

using namespace std;
int count1 = 0;
int count2 = 0;
mutex m1;
mutex m2;
void task1() {
    for (int i = 0; i < 19000000; ++i) {
        if (m1.try_lock()) {
            count1++;
            m1.unlock();
        }
    }
}

void task2() {
    for (int i = 0; i < 19000000; ++i) {
        m2.lock();
        count2++;
        m2.unlock();
    }
}

int main() {
    thread t1(task1);
    thread t2(task2);
    t1.join();
    t2.join();
    cout << count1 << endl;
    cout << count2 << endl;
    return 0;
}
