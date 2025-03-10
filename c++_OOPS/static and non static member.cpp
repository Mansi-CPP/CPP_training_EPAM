#include <iostream>
using namespace std;

class Car {
private:
    string brand;      // Instance variable (separate for each object)
    int speed;         // Instance variable (separate for each object)
    
public:
    static int totalCars;  // Static variable (shared among all objects)

    // Constructor
    Car(string b, int s) {
        brand = b;
        speed = s;
        totalCars++;  // Increment static variable
    }

    // Display method
    void display() {
        cout << "Brand: " << brand << ", Speed: " << speed << " km/h" << endl;
    }

    // Static method to get total cars
    static void showTotalCars() {
        cout << "Total Cars: " << totalCars << endl;
    }
};

// **Definition of static variable outside the class**
int Car::totalCars = 0;

int main() {
    Car car1("Toyota", 120);
    Car car2("BMW", 150);

    car1.display();  
    car2.display();

    // Accessing static variable using the class name
    Car::showTotalCars();  // Output: Total Cars: 2

    return 0;
}
// static variable do not belong to an object they belong to class so same for all the variables example here the count for toatalcars
