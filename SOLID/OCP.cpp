//Bad example
#include <iostream>
using namespace std;

class Shape {
public:
    virtual string getType() = 0;
};

class Rectangle : public Shape {
public:
    string getType() override { return "Rectangle"; }
};

class Circle : public Shape {
public:
    string getType() override { return "Circle"; }
};

class AreaCalculator {     // every time we add a new shape we need to modify this and is not easily extensible
public:
    double calculateArea(Shape* shape) {
        if (shape->getType() == "Rectangle") {
            // calculate rectangle area
        } else if (shape->getType() == "Circle") {
            // calculate circle area
        }
        return 0.0;
    }
};
// Good code
#include <iostream>
#include <vector>
using namespace std;

class Shape {
public:
    virtual double area() const = 0;
    virtual ~Shape() = default;
};

class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const override {
        return width * height;
    }
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override {
        return 3.14159 * radius * radius;
    }
};

class AreaCalculator {
public:
    double totalArea(const vector<Shape*>& shapes) {
        double total = 0.0;
        for (auto shape : shapes) {
            total += shape->area(); // Polymorphism in action
        }
        return total;
    }
};
// now if we want to add triangle we can easily add 
class Triangle : public Shape {
    double base, height;
public:
    Triangle(double b, double h) : base(b), height(h) {}
    double area() const override {
        return 0.5 * base * height;
    }
};
