#include <iostream>
#include <string>
using namespace std;

/*
Prototype Pattern is a creational design pattern used to clone objects, especially when creating new objects is expensive or complex.

Instead of building an object from scratch, you copy an existing one — like making a duplicate key from the original.g

*/

// 1. Prototype interface
class Shape {
public:
    virtual Shape* clone() const = 0;  // Pure virtual clone method
    virtual void draw() const = 0;
    virtual ~Shape() = default;
};

// 2. Concrete Prototype
class Circle : public Shape {
    int radius;
public:
    Circle(int r) : radius(r) {}

    // Override clone
    Shape* clone() const override {
        return new Circle(*this); // copy constructor
    }

    void draw() const override {
        cout << "Drawing Circle with radius " << radius << endl;
    }
};

class Rectangle : public Shape {
    int width, height;
public:
    Rectangle(int w, int h) : width(w), height(h) {}

    Shape* clone() const override {
        return new Rectangle(*this);
    }

    void draw() const override {
        cout << "Drawing Rectangle (" << width << " x " << height << ")\n";
    }
};

// 3. Client code
int main() {
    Shape* originalCircle = new Circle(10);
    Shape* copyCircle = originalCircle->clone(); // clone the circle

    Shape* originalRect = new Rectangle(4, 6);
    Shape* copyRect = originalRect->clone();

    // Use objects
    originalCircle->draw();
    copyCircle->draw();

    originalRect->draw();
    copyRect->draw();

    // Clean up
    delete originalCircle;
    delete copyCircle;
    delete originalRect;
    delete copyRect;

    return 0;
}
