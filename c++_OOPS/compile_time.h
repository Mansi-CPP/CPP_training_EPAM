#pragma once
#include<iostream>
#include<string>
using namespace std;
//compile time fu
class Bank_account{
public:
	double amount;
	double rate;
	double time;
public:
	double balance();
	double balance(double rate);
	//int balance(double rate); cannot overload by just return type
};
