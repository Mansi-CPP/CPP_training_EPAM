#include <iostream>
#include <string>
#include <sstream>
#include<thread>
#include<chrono>

using namespace std;
using namespace std::chrono;
void sum(int n) {
	int ans = 0;
	for (int i = 0;i < n;i++) {
		ans += i;
	}
	cout<< ans<<endl;
}
void prod(int n) {
	int prod = 1;
	for (int i = 1;i < n;i++) {
		prod *= i;
	}
	cout << prod<<endl;
}
int main() {
	auto start = high_resolution_clock::now();
	sum(19000000000);
	prod(19000000000);
	auto stop = high_resolution_clock::now();
	auto dur = duration_cast<microseconds>(stop-start);
	cout << "time without threads" << dur.count() / 1000000<<endl;
	auto start2 = high_resolution_clock::now();
	thread t1(sum, 19000000000);//using function pointers to create thread
	thread t2(prod, 19000000000);
	t1.join();
	t2.join();// join ensures the thread completes the execution
	auto stop2 = high_resolution_clock::now();
	auto dur2 = duration_cast<microseconds>(stop2 - start2);
	cout << "time with threads" << dur2.count() / 1000000<<endl;
	return 0;
}

// wuth threads execution was faster
//1338212608
//0
//time without threads3
//0
//1338212608     
//time with threads1