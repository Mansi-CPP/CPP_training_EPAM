#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void task1() {
    for (int i = 0; i < 5; ++i) {
        cout << "Task 1: " << i << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

void task2() {
    for (int i = 0; i < 5; ++i) {
        cout << "Task 2: " << i << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

int main() {
    thread t1(task1);
    thread t2(task2);
    t1.join();
    t2.join();
    return 0;
}
//Task 2: 0
//Task 1 : 0
//Task 1 : Task 2 : 1
//1
//Task 2 : 2Task 1 : 2
//
//Task 1 : 3Task 2 : 3
//
//Task 1 : 4
//Task 2 : 4
