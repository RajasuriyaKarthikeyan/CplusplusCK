#include <iostream>
#include <typeinfo>
using namespace std;

class Base {
public:
    virtual void show() {}
};

class Derived : public Base {
public:
    void specific() {
        cout << "Derived-specific function\n";
    }
};

int main() {
    Base* b = new Derived();
    b->show();
    Derived* d = dynamic_cast<Derived*>(b); // Safe downcast

    if (d) {
        d->specific();  // works
    } else {
        cout << "Invalid cast\n";
    }

    delete b;
}
