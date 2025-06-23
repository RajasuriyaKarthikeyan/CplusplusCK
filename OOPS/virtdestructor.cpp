#include <iostream>

class Base {
public:
    virtual ~Base() { std::cout << "Base destructor\n"; }
};

class Derived : public Base {
public:
    ~Derived() { std::cout << "Derived destructor\n"; }
};

int main() {
    Base* obj = new Derived();
    delete obj;  // Both destructors are called because ~Base is virtual
}
