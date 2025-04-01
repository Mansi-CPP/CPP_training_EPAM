#include <iostream>
#include <vector>
#include <typeinfo>
#include<algorithm>
void foo(int&& lr) {
}
void foo1(int&& rr) {
}
int main() {
	int i = 10;       // i is an lvalue
	int& x = i;       // Correct: lvalue reference bound to lvalue

	//int& x1 = 10;     // Incorrect: lvalue reference cannot bind to rvalue (temporary)
	const int& x2 = 10; // Correct: const lvalue reference binds to rvalue
	// Function expecting an lvalue reference

	//foo(10); // Incorrect: rvalue (10) cannot bind to int&
	int a = 10;
	int&& rr=10; 
	foo1(10);//gives no error

}
