#include<iostream>
#include<exception>
#include<array>
using namespace std;
//int divide(int a, int b) {
//	try {
//		if (b == 0) {
//			throw invalid_argument("division by zero");
//		}
//	}
//	catch (const invalid_argument& e) {
//		cout << "divide"<<e.what() << endl;
//		throw;
//	}
//}
class invaliddeposit :public exception {
	const char* what() const noexcept  override{
		return "Invalid deposit";
	}
};
class myexception {
public:
	const char* what() const {
		return "myexception custom";
	}
};
class atm {
	int amount = 8000;
public:
	void deposit(int a) {
		if (a < 0) {
			throw myexception();
	    }
		amount += a;
	}
};
int main() {
	try {
		//divide(2, 0);
		atm a;
		a.deposit(-10);
	}
	catch (const myexception& e) {
		cout <<"Main"<< e.what() << endl;
	}
	return 0;

}
