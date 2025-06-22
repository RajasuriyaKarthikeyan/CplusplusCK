#include<iostream>
using namespace std;

// Abstract class
class Shape {
  public: virtual void draw() = 0; // Pure virtual function
  virtual~Shape() {} // Virtual destructor
};

// Derived class: Circle
class Circle: public Shape {
  public: void draw() override {
    cout << "Drawing Circle" << endl;
  }
};

// Derived class: Rectangle
class Rectangle: public Shape {
  public: void draw() override {
    cout << "Drawing Rectangle" << endl;
  }
};

// Derived class: Triangle
class Triangle: public Shape {
  public: void draw() override {
    cout << "Drawing Triangle" << endl;
  }
};

int main() {
  Shape * shapes[] = {
    new Circle(),
    new Rectangle(),
    new Triangle()
  };

  // Draw all shapes
  for (Shape * shape: shapes) {
    shape -> draw();
  }

  // Cleanup
  for (Shape * shape: shapes) {
    delete shape;
  }

  return 0;
}