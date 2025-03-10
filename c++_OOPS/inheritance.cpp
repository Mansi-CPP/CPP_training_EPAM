#include<iostream>
#include<string>
using namespace std;

class account {
public:
	int accnumber;
	double balance;
	string name;
	account(int n, double b, string na) :accnumber(n), balance(b), name(na) {

	}
    void deposit(int amount);
    void withdraw(int amount);
    void display() {
        cout << "account number" << accnumber << endl;
        cout << "name" << name << endl;
        cout << "balance" << balance << endl;
    }
};
class SavingsAccount : public account {
private:
    double interestRate;  // Additional feature in SavingsAccount

public:
    SavingsAccount(int accNum, double bal, string accName, double rate)
        : account(accNum, bal, accName), interestRate(rate) {
    }
    void addInterest() {
        double interest = balance * (interestRate / 100);
        balance += interest;
        cout << "Interest Added: $" << interest << ". New Balance: $" << balance << endl;
    }
    void displayAccount() {
        cout << "Savings Account Details:" << endl;
        display();// account.display(); is wrong as it is member  // Calling base class function
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};

#include"inheritance.h""


void account::deposit(int amount) {
	balance += amount;
	cout << "new balance" << balance;
}
void account::withdraw(int amount) {
	if (amount > balance) {
		cout << "balance insufficicent" << endl;

	}
	else {
		balance -= amount;
		cout << "balance left" << balance << endl;
	}
}

#include <iostream>
#include<string >
#include "inheritance.h"
using namespace std;

int main() {
    
    SavingsAccount sa(1001, 5000, "John Doe", 5.0);
    sa.displayAccount();
    sa.deposit(2000);
    sa.withdraw(1000);
    sa.addInterest();
    sa.displayAccount();

	return 0;
}


