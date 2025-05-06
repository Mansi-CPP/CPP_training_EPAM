#pragma once
#include<iostream>
using namespace std;
//ISP
// bad code
//class Payment {
//public:
//
//	void virtual payonline() = 0;
//	void virtual authenticate() = 0;
//	void virtual cash() = 0;
//};
//
//class Creditcard :public Payment{
//	void payonline() override;
//	void authenticate() override;
//	void cash() override;             // unnecesarily client has to implement cash when not needed 
//};
//Good code


// Interface for online payments
class OnlinePayable {
public:
	virtual void payOnline(double amount) = 0;
	virtual ~OnlinePayable() = default;
};

// Interface for methods that require authentication (e.g., credit card, UPI)
class Authenticatable {
public:
	virtual void authenticate() = 0;
	virtual ~Authenticatable() = default;
};

// Interface for cash-based methods (e.g., Cash on Delivery)
class CashCollectable {
public:
	virtual void collectCash(double amount) = 0;
	virtual ~CashCollectable() = default;
};

class CreditCardPayment : public OnlinePayable, public Authenticatable {
public:
    void authenticate() override {
        std::cout << "Authenticating Credit Card...\n";
    }

    void payOnline(double amount) override {
        std::cout << "Paid ₹" << amount << " via Credit Card.\n";
    }
};

// UPI Payment
class UPIPayment : public OnlinePayable, public Authenticatable {
public:
    void authenticate() override {
        std::cout << "Authenticating UPI PIN...\n";
    }

    void payOnline(double amount) override {
        std::cout << "Paid ₹" << amount << " via UPI.\n";
    }
};

// PayPal Payment
class PayPalPayment : public OnlinePayable, public Authenticatable {
public:
    void authenticate() override {
        std::cout << "Authenticating PayPal account...\n";
    }

    void payOnline(double amount) override {
        std::cout << "Paid ₹" << amount << " via PayPal.\n";
    }
};

// Cash on Delivery
class CashOnDelivery : public CashCollectable {
public:
    void collectCash(double amount) override {
        std::cout << "Collect ₹" << amount << " in cash on delivery.\n";
    }
};// all classes implemented in their own way
