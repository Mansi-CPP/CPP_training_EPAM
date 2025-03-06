#pragma once
#include<iostream>
#include <string>
#include<vector>

using  namespace std;

class Address {
public:
	string street;
	string city;

	Address(string s, string c) : street(s), city(c) {}
};
class student {
public:
	string name;
	string dept;
	Address address;
	//vector<int> marks;

	//double salary
public:
	//student();  cannot call when constant variable
	//student(const string& n, int m) : name(n), marks(m) {
	//	// name is initialized via the constructor initialization list
	//}
	//student(string n, string d, int exp) : name(n), dept(d), marks(exp) {};
	//student(string n,string dept,vector<int> s) :name(n),dept(dept), marks(s) { initialisation efficency
		// The vector is initialized directly in the initialization list
	//default
	student(string n, string d, string street, string city) : name(n), dept(d), address(street, city) {
		// address is initialized via the initialization list
	}
	~student();
	void display();
};
