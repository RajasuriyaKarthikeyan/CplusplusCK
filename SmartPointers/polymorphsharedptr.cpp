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
    // Create a shared_ptr to a Derived object but typed as shared_ptr<Base>
    std::shared_ptr<Base> ptr = std::make_shared<Derived>();

    ptr->speak();  // Calls Derived::speak()

    // Multiple shared_ptrs can share ownership
    std::shared_ptr<Base> ptr2 = ptr;

    std::cout << "Use count: " << ptr.use_count() << std::endl;

    // When the last shared_ptr goes out of scope, the Derived and Base destructors are called
}
