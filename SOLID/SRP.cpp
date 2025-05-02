#pragma once
#include<iostream>
using namespace std;
// Single responsibility
//Bad code
/*class User {
   
	string username;
	string email;
	int age;

	void register_U(string email,string name,int age);
	void welcomeemail();
	int getage();


};SOLID.cpp
#include "SOLID.h"
//
//void User::register_U(string email,string name,int age)
//{
//	this->email = email;
//	this->username = name;
//	this->age = age;
//}
//
//void User::welcomeemail()
//{
//	cout << "welcome";
//}
//
//int User::getage()
//{
//	return this->age;
//}

*/// single class is register displaying as well and welcoming as well
//❌ Problem: Violates SRP
//Right now, your User class :
//
//	Stores user data ✅
//
//	Handles registration logic ❌
//
//	Sends email ❌
//
//	This means it has multiple reasons to change, violating the SRP.
// good code
class User {
    string email;                                 //handles the data setting and displaying
    string username;
    int age;
public:
    User() {}
    User(string email, string username, int age)
        : email(email), username(username), age(age) {
    }

    string getEmail() const { return email; }
    string getUsername() const { return username; }
    int getAge() const { return age; }

    void setEmail(string e) { email = e; }
    void setUsername(string u) { username = u; }
    void setAge(int a) { age = a; }
};

// ---------- UserRegistration Class ----------  creates a user object and return all these 
class UserRegistration {
public:
    User registerUser(string email, string username, int age) {
        return User(email, username, age);  
    }
};

// ---------- EmailService Class ---------- sends email for welcome
class EmailService {
public:
    void sendWelcomeEmail(const User& user) {
        cout << "Welcome, " << user.getUsername()
            << "! A confirmation has been sent to " << user.getEmail() << ".\n";
    }
};
int main() {
    /// create different object for each function
    UserRegistration registrar;
    EmailService emailer;

    User user = registrar.registerUser("john@example.com", "john_doe", 25);
    emailer.sendWelcomeEmail(user);

    return 0;
}