is a relationship is inheritance achieved in derived class
class account {
public:
	int accnumber;
protected:
	double balance;
public:
	string name;
	account(int n, double b, string na) :accnumber(n), balance(b), name(na) {
        cout << "base constructor" << endl;
	}
    void deposit(int amount);
    void withdraw(int amount);
    void display() {
        cout << "account number" << accnumber << endl;
        cout << "name" << name << endl;
        cout << "balance" << balance << endl;
    }
    ~account() {
        cout << "base destructor"<<endl;
    }
};
class SavingsAccount : public account {
private:
    double interestRate;  // Additional feature in SavingsAccount

public:
    /*SavingsAccount(int accNum, double bal, string accName, double rate)
        : account(accNum, bal, accName), interestRate(rate) {
        cout << "derived constructor"<<endl;
    }*/
    SavingsAccount(int n, double b, string na) :account(accnumber, balance, name) {
        cout << "const using base class";
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
    ~SavingsAccount() {
        cout << "destructed derived"<<endl;
    }
};

has a relationship is when one class object is member of another class
#include <iostream>
using namespace std;

class Engine {
private:
    int horsepower;
protected:
    string type;
public:
    Engine() : horsepower(120), type("Petrol") {} // ✅ Default constructor
    Engine(int hp, string fuelType) : horsepower(hp), type(fuelType) {} // ✅ Parameterized constructor

    void showDetails() {
        cout << "Engine HP: " << horsepower << ", Type: " << type << endl;
    }
    //access private members and protected members
    int getHorsepower() { return horsepower; }  // Getter function
    void setHorsepower(int hp) { horsepower = hp; }
};

class Car {
private:
    Engine engine; // "Car has an Engine"
public:
    Car(int hp, string fuelType) : engine(hp, fuelType) {};
    void showEngineDetails() {
        engine.showDetails(); // Allowed: Accessing public method of Engine
        cout << "Horsepower via getter: " << engine.getHorsepower() << endl;
        int num = engine.getHorsepower();
        // cout << engine.horsepower; ❌ Error: Private members cannot be accessed directly
        // cout << engine.type; ❌ Error: Protected members cannot be accessed directly
        //to access

    }
   
};
 aggregation
#include <iostream>
using namespace std;

class Engine {
public:
    void start() {
        cout << "Engine starts." << endl;
    }
};

class Car {
private:
    Engine* engine;  // Car has an Engine (but it is independent)
public:
    Car(Engine* e) : engine(e) {}
    void drive() {
        engine->start();
        cout << "Car is moving." << endl;
    }
};

int main() {
    Engine e;  // Engine object created separately
    Car c(&e); // Car uses Engine
    c.drive();
    return 0;
}


