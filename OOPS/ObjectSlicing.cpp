#include <iostream>

class Base {
public:
    int baseValue = 1;
    virtual ~Base() = default;

    virtual void print() {
        std::cout << "Base: " << baseValue << std::endl;
    }
};

class Derived : public Base {
public:
    int derivedValue = 42;

    void print() override {
        std::cout << "Derived: " << derivedValue << std::endl;
    }
};

int main() {
    Derived d;

    // Object slicing: copying Derived object into Base object by value
    Base b = d;  // Only Base part is copied

    std::cout << "After slicing (Base b = d):" << std::endl;
    b.print();  // Calls Base::print(), Derived part is sliced off

    std::cout << "\nUsing reference to avoid slicing:" << std::endl;
    Base& bRef = d;
    bRef.print();  // Calls Derived::print()

    std::cout << "\nUsing pointer to avoid slicing:" << std::endl;
    Base* bPtr = &d;
    bPtr->print(); // Calls Derived::print()

    return 0;
}
