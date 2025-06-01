#include<iostream>
#include<memory>

using namespace std;
//Product
class transport {
public:
	virtual void start() = 0;
	virtual void stop() = 0;
	virtual ~transport() = default;
};
//Product concrete 
class car :public transport {
public:
	void start() override {
		cout << "starting car" << endl;
	}
	void stop() override {
		cout << "stop car" << endl;
	}
	~car() override {
		cout << "destroyed  car" << endl;
	}
};
class truck :public transport {
public:
	void start() override {
		cout << "starting truck" << endl;
	}
	void stop() override {
		cout << "stop truck" << endl;
	}
	~truck() override {
		cout << "destroyed truck" << endl;
	}
};
class bike :public transport {
public:

	void start() override {
		cout << "starting bike" << endl;
	}
	void stop() override {
		cout << "stop bike" << endl;
	}
	~bike() override {
		cout << "destroyed truck" << endl;
	}
};
enum Vehicle { Car = 1, Truck = 2, Bike = 3 };
//factory
class factory {
public:
	static shared_ptr<transport> startVehicle(Vehicle type) {
		if (type == Vehicle::Car) {
			return make_shared<car>();
		}
		else if (type == Vehicle::Truck) {
			return make_shared<truck>();
		}
		else if (type == Vehicle::Bike) {
			return make_shared<bike>();
		}
		else {
			cout << "Invalid"<<endl;
			return nullptr;
		}
	}
};

int main() {
    int choice;
    cout << "Choose a vehicle (1: Car, 2: Truck, 3: Bike): ";
    cin >> choice;

    if (choice < 1 || choice > 3) {
        cout << "Invalid choice!" << endl;
        return 1;
    }

    shared_ptr<transport> vehicle = factory::startVehicle(static_cast<Vehicle>(choice));

    if (vehicle) {
        vehicle->start();
        vehicle->stop();
    }

    // shared_ptr automatically destroys the object
    return 0;


}