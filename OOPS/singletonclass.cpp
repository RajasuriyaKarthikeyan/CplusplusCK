#include <iostream>

class Singleton {
private:
    // Private constructor to prevent instancing
    Singleton() {
        std::cout << "Singleton instance created\n";
    }

    // Delete copy and assignment
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

public:
    // Static method to access the instance
    static Singleton& getInstance() {
        static Singleton instance;  // Initialized on first call, thread-safe in C++11+
        return instance;
    }

    void doSomething() {
        std::cout << "Doing something with Singleton\n";
    }
};

int main() {
    Singleton& s1 = Singleton::getInstance();
    s1.doSomething();

    Singleton& s2 = Singleton::getInstance();
    s2.doSomething();

    // s1 and s2 are the same instance
}
