#include <iostream>
#include <memory>

class MyClass {
public:
    MyClass(int val) : value(val) {
        std::cout << "MyClass(" << value << ") constructed.\n";
    }
    ~MyClass() {
        std::cout << "MyClass(" << value << ") destroyed.\n";
    }
    void display() const {
        std::cout << "Value: " << value << "\n";
    }

private:
    int value;
};

int main() {
    std::cout << "=== unique_ptr Example ===\n";
    {
        std::unique_ptr<MyClass> uniqPtr = std::make_unique<MyClass>(10);
        uniqPtr->display();
        // Ownership ends here; MyClass is destroyed automatically
    }

    std::cout << "\n=== shared_ptr Example ===\n";
    std::shared_ptr<MyClass> sharedPtr1;
    {
        std::shared_ptr<MyClass> sharedPtr2 = std::make_shared<MyClass>(20);
        sharedPtr1 = sharedPtr2; // shared ownership
        sharedPtr1->display();
        std::cout << "sharedPtr2 use count: " << sharedPtr2.use_count() << "\n";
    } // sharedPtr2 goes out of scope, but sharedPtr1 still owns it
    std::cout << "sharedPtr1 use count: " << sharedPtr1.use_count() << "\n";

    std::cout << "\n=== weak_ptr Example ===\n";
    std::weak_ptr<MyClass> weakPtr = sharedPtr1;
    std::cout << "weakPtr expired? " << (weakPtr.expired() ? "Yes" : "No") << "\n";

    if (auto tempShared = weakPtr.lock()) {
        tempShared->display();
    } else {
        std::cout << "Object already destroyed.\n";
    }

    sharedPtr1.reset(); // Last shared_ptr is reset, object is destroyed

    std::cout << "After sharedPtr1.reset():\n";
    std::cout << "weakPtr expired? " << (weakPtr.expired() ? "Yes" : "No") << "\n";

    return 0;
}
