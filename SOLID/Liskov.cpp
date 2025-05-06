class Bird {
public:

    void virtual layeggs()=0;
	//void virtual fly() = 0;        // this is a bad code example  because ostritch cannot
	                               //implement fly properly
};    // so implement a class flying bird  to implement properly
class flyingBird:public Bird {
public:
	void virtual fly() = 0;
};

class sparrow:public flyingBird {
	void layeggs() override;
	void fly() override;
};
class ostritch :public Bird {
	void layeggs() override;
};
// this is a good code example
SOLID.cpp
void sparrow::layeggs()
{
	cout << "sparrow lays eggs" << endl;
}

void sparrow::fly()
{
	cout << "sparrow fly" << endl;
}


void ostritch::layeggs()
{
	cout << "ostritch lays eggs" << endl;
}

//void ostritch::fly()
//{
//	throw logic_error("Ostriches can't fly");
//}
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
#include"SOLID.h"
using namespace std;
using namespace chrono;

int main()
{
    Bird* bird = new ostritch();
    bird->layeggs();
  
    return 0;
}
