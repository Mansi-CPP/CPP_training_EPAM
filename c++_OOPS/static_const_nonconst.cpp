#include <iostream>
#include <string>

using namespace std;
class Car {
private:
    string brand;      // Instance variable (separate for each object)
    int speed; // Instance variable (separate for each object)
    
public:    
    static int totalCars;  // Static variable (shared among all objects)
    Car(string b, int s) {
        brand = b;
        speed = s;
        totalCars++;  // Increment static variable
    }
public:

    // Display method
    void display() {
        cout << "Brand: " << brand << ", Speed: " << speed << " km/h" << endl;
    }

    // Static method to get total cars
    static void showTotalCars() {
        cout << "Total Cars: " << totalCars << endl;
    }
};
int Car::totalCars=0;
int main()
{
  Car a("a",90);
  Car b("b",80);
  a.display();
  b.display();
  
  Car::showTotalCars();
  return 0;
}
