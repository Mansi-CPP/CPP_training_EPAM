#include <iostream>
#include <thread>
#include <chrono>
#include<future>
#include<mutex>
#include<chrono>
#include<condition_variable>
using namespace std;
using namespace chrono;
int EvenNosFind(int begin, int end)
{
    cout << this_thread::get_id()<<endl;
    int evenNo = 0;
    for (int i = begin; i <= end; i++) {
        if (i % 2 == 0) {
            evenNo += 1;
        }
    }
    this_thread::sleep_for(seconds(10));
   // return;  exception thrown 
    return evenNo;
   
}

// driver code
int main()
{
    int begin = 0, end = 1000;
    cout << this_thread::get_id()<<endl;
    cout << "My thread is created when ID is launch::async" << endl;
    future<int> evenFuture = async(launch::async, EvenNosFind,begin ,end);//to wait  for the value
    
    cout << "Waiting..........." << endl;

    // getting the data
    cout << "The no. of even numbers are : " << evenFuture.get() << endl;
    cout << "My thread is created when ID is launch::deferred" << endl;
    future<int> evenfuture = async(launch::async, EvenNosFind, begin, end);//to wait  for the value

    cout << "Waiting..........." << endl;

    // getting the data
    cout << "The no. of even numbers are : " << evenfuture.get() << endl;
   
    return 0;
}
//20676
//My thread is created when ID is launch::async // *immediately starts
//                                                 **thread is created so thread id is different
//Waiting...........
//16892
//The no.of even numbers are : 501                     
//My thread is created when ID is launch::deferred
//Waiting...........
//16892                                 //*only starts when get is called 
//                                         * no thread created so thread id is same
//The no.of even numbers are : 501
