#include <iostream>
#include <thread>
#include <chrono>
#include<future>
#include<mutex>
#include<chrono>
#include<deque>
#include<condition_variable>
#include"semaphores.h"
#include<chrono>
using namespace std;
using namespace chrono;

BinarySemaphore M2T{ 0 }, T2M{ 0 };
void fun() {
    M2T.acquire();//blocks if the sempahore is already zero else will decrese the count of sempahore
    cout << "thread has the signal" << endl;
    this_thread::sleep_for(seconds(3));
    cout << "thread sends signal" << endl;
    T2M.release(); //signal main thread that current thread has released semaphore
}
int main()
{
    thread t1(fun);// thread is created but does not start working until the signal is received
    
    cout << "send signal to thread to start execution" << endl;
    //signal semaphore to start working by releasing the thread
    M2T.release();//increases semaphore count to 1
    //wait until worker thread does the work
    T2M.acquire();
    cout << "Main got the signal" << endl;
    t1.join();
    return 0;
}
//send signal to thread to start execution
//thread has the signal
// thread waits ere to finish wroking
//thread sends signal
//Main got the signal
