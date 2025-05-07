#include <iostream>
#include <memory>
#include <string>

// 1. Define Abstraction
class IPaymentProcessor {
public:
    virtual void processPayment(double amount) = 0;
    virtual ~IPaymentProcessor() = default;
};

// 2. Implement Concrete Payment Methods
class CreditCard : public IPaymentProcessor {
public:
    void processPayment(double amount) override {
        std::cout << "Processing credit card payment of $" << amount << "\n";
    }
};

class PayPal : public IPaymentProcessor {
public:
    void processPayment(double amount) override {
        std::cout << "Processing PayPal payment of $" << amount << "\n";
    }
};

class Stripe : public IPaymentProcessor {
public:
    void processPayment(double amount) override {
        std::cout << "Processing Stripe payment of $" << amount << "\n";
    }
};

// 3. High-Level Module
class PaymentService {
    std::shared_ptr<IPaymentProcessor> processor;

public:
    PaymentService(std::shared_ptr<IPaymentProcessor> p) : processor(p) {}

    void makePayment(double amount) {
        processor->processPayment(amount);
    }
};

// 4. Usage
int main() {
    std::shared_ptr<IPaymentProcessor> credit = std::make_shared<CreditCard>();
    std::shared_ptr<IPaymentProcessor> paypal = std::make_shared<PayPal>();
    std::shared_ptr<IPaymentProcessor> stripe = std::make_shared<Stripe>();

    PaymentService service1(credit);
    PaymentService service2(paypal);
    PaymentService service3(stripe);

    service1.makePayment(100.50);
    service2.makePayment(250.75);
    service3.makePayment(320.00);

    return 0;
}
