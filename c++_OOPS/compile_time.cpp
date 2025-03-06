#include "C_poly.h"

double Bank_account::balance()
{
	return amount;
}

double Bank_account::balance(double rate)
{
	this->rate = rate;
	return amount+((amount*rate*time)/100);
}

#include <iostream>
#include<string >
#include "C_poly.h"
using namespace std;

int main() {
	Bank_account b1;
	b1.amount= 1000;
	b1.time = 1;
	int r = 10;
	cout << "original amount" << b1.balance();
	cout << "interest amount" << b1.balance(r);

	return 0;
}
