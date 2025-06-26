#include <iostream>
#include <thread>

int main() {
    std::thread t([](){ 
        std::cout << "Hello from thread\n"; 
    });
    t.join();  // Wait for thread t to finish

    std::cout << "Hello from main\n";

    return 0;
}
