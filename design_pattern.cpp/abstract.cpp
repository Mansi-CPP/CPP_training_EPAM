#include <iostream>
#include <memory>
using namespace std;

// Product
class car {
public:
    virtual void name() = 0;
    virtual ~car() = default;
};

// Concrete Products
class honda : public car {
public:
    void name() override {
        cout << "honda" << endl;
    }
    ~honda() {
        cout << "honda destructed" << endl;
    }
};

class BMW : public car {
public:
    void name() override {
        cout << "BMW" << endl;
    }
    ~BMW() {
        cout << "BMW destructed" << endl;
    }
};

class toyata : public car {
public:
    void name() override {
        cout << "toyota" << endl;
    }
    ~toyata() {
        cout << "toyota destructed" << endl;
    }
};

// Enum for brand
enum Brand { honda_Brand = 1, BMW_brand = 2, toyata_brand = 3 };

// Abstract Factory
class carfactory {
public:
    virtual shared_ptr<car> createcar() = 0;
    virtual ~carfactory() = default;
    static shared_ptr<carfactory> CreateCarFactory(Brand choice);
};

// Concrete Factories
class hondafactory : public carfactory {
public:
    shared_ptr<car> createcar() override {
        return make_shared<honda>();
    }
    ~hondafactory() = default;
};

class BMWfactory : public carfactory {
public:
    shared_ptr<car> createcar() override {
        return make_shared<BMW>();
    }
    ~BMWfactory() = default;
};

class toyatafactory : public carfactory {
public:
    shared_ptr<car> createcar() override {
        return make_shared<toyata>();
    }
    ~toyatafactory() = default;
};

// Static factory method implementation
shared_ptr<carfactory> carfactory::CreateCarFactory(Brand choice) {
    if (choice == honda_Brand) {
        return make_shared<hondafactory>();
    } else if (choice == BMW_brand) {
        return make_shared<BMWfactory>();
    } else if (choice == toyata_brand) {
        return make_shared<toyatafactory>();
    } else {
        return nullptr;
    }
}

// Main function
int main() {
    int choice;
    cout << "Choose a car brand (1: Honda, 2: BMW, 3: Toyota): ";
    cin >> choice;

    if (choice < 1 || choice > 3) {
        cout << "Invalid choice!" << endl;
        return 1;
    }

    shared_ptr<carfactory> factory = carfactory::CreateCarFactory(static_cast<Brand>(choice));
    if (factory) {
        shared_ptr<car> vehicle = factory->createcar();
        vehicle->name();
    }

    // shared_ptr automatically destroys the object and prints destructor message
    return 0;
}
#include<iostream>
using namespace std;
//
class button {
public:
    virtual void press() = 0;
    virtual ~button()=default;
};
class checkbox {
public:
    virtual void select() = 0;
    virtual ~checkbox() = default;
};
//concrete Product
class windowsbutton :public button {
public:
    void press() override {
        cout << "windows" << endl;

    }
    ~windowsbutton(){
        cout << "windows destructed" << endl;
    }
};
class macbutton :public button {
public:
    void press() override {
        cout << "mac" << endl;

    }
    ~macbutton() {
        cout << "mac destructed" << endl;
    }
};
class windowscheckbox :public checkbox {
public:
    void select() override {
        cout << "windows" << endl;

    }
    ~windowscheckbox() {
        cout << "windows destructed" << endl;
    }
};
class maccheckbox :public checkbox {
public:
    void select() override {
        cout << "mac" << endl;

    }
    ~maccheckbox() {
        cout << "windows destructed" << endl;
    }
};
//abstract factory
class UIfactory {
public:
    virtual button* createButton() = 0;
    virtual checkbox* createCheckbox() = 0;
    virtual ~UIfactory() = default;

};
//concrete factory
class windowUIfactory:public UIfactory {
    button* createButton() override {
        return new windowsbutton();
    };
    checkbox* createCheckbox()override {
        return new windowscheckbox();
    };

};
class macUIfactory :public UIfactory {
    button* createButton() override {
        return new macbutton();
    };
    checkbox* createCheckbox()override {
        return new maccheckbox();
    };

};
