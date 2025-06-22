#include<iostream>
using namespace std;

class shape {
  public: virtual void draw() { // Virtual function
    cout << "Creating a shape!" << endl;
  }
};

class circle: public shape {
  public: void draw() { // Overriding virtual function
    cout << "Creating a Circle!" << endl;
  }
};

class square: public shape {
  public: void draw() { // Overriding virtual function
    cout << "Creating a Square!" << endl;
  }
};

int main() {
  shape * shapePtr; // Base class pointer
  circle c;
  square s;

  shapePtr = & c; // Pointing to circle object
  shapePtr -> draw(); // Calls circle's draw() method

  shapePtr = & s; // Pointing to square object
  shapePtr -> draw(); // Calls square's draw() method

  return 0;
}