#include<iostream>
using namespace std;

class shape {
  public: 
    virtual void draw() { // Virtual function
    cout << "Creating a shape!" << endl;
  }
    void dummy(){
      cout <<" Calling dummy from shape object" << endl;
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
  shape S;
  S.draw();
  c.draw();
  c.dummy();
  s.draw();

  shapePtr = & c; // Pointing to circle object
  shapePtr -> draw(); // Calls circle's draw() method
  shapePtr->dummy(); // Calls dummy function

  shapePtr = & s; // Pointing to square object
  shapePtr -> draw(); // Calls square's draw() method

  return 0;
}