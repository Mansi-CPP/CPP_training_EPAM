#pragma once
class multiply {
public:
	int fact;
public:
	multiply(int f) :fact(f){

	}
	int operator()(int x);
};
class Counter {
    int num;
    int count = 0;

public:
    Counter(int n) : num(n) {}

    void operator()(int x);

    int getCount() const;
};
#include<iostream>
#include "functors.h"
using namespace std;


int multiply::operator()(int x)
{
	return x*fact;
}

void Counter::operator()(int x)
{
    
        if (x == num)
            count++;
    
}

int Counter::getCount() const
{
    return count;
}
include <iostream>
#include <vector>
#include <tuple>
#include<algorithm>
#include "functors.h"

using namespace std;
struct Descending {
    bool operator()(int a, int b) {
        return a > b; // Sort in descending order
    }
};


int main() {
    multiply m(3);
    cout << "hello";
    cout << "3*4  =  " << m(4);

    // use functors in customising sort
    vector<int> vec = { 5, 3, 8, 1, 7 };

    // Sort using functor
    sort(vec.begin(), vec.end(), Descending());
    cout << "hello";
    for (int num : vec) {
        cout << num << " ";
       
    }
    //statefull
    vector<int> numbers = { 1, 2, 3, 4, 2, 2, 5, 6, 2 };

    Counter countTwo(2);
    countTwo = for_each(numbers.begin(), numbers.end(), countTwo);

    cout << "Number 2 appears: " << countTwo.getCount() << " times" << endl;

    return 0;
}
