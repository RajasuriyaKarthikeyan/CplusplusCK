#include <iostream>
#include <typeinfo>
using namespace std;

class Base {
public:
    virtual void func() {}
};

class Derived : public Base {};

int main() {
    Base* b = new Derived();

    cout << "Type: " << typeid(*b).name() << endl; // typeid(*b) returns the dynamic type (Derived)
    cout << "Type: " << typeid(b).name() << endl; // typeid(b) returns the static type (Base)
    delete b;
}
