#include <iostream>
#include <memory>

class Base {
public:
    virtual ~Base() { std::cout << "Base destructor\n"; }
    virtual void speak() const { std::cout << "Base speaking\n"; }
};

class Derived : public Base {
public:
    ~Derived() override { std::cout << "Derived destructor\n"; }
    void speak() const override { std::cout << "Derived speaking\n"; }
};

int main() {
    // unique_ptr to base managing a Derived instance
    std::unique_ptr<Base> ptr = std::make_unique<Derived>();

    ptr->speak();  // Calls Derived::speak()

    // When ptr goes out of scope, destructors for Derived and Base run properly
}
