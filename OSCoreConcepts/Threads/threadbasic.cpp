#include <iostream>
#include <thread>

void printMessage() {
    std::cout << "Hello from thread!" << std::endl;
}

int main() {
    std::thread t(printMessage);  // Create and start thread
    t.join();                     // Wait for the thread to finish
    std::cout << "Hello from main!" << std::endl;
    return 0;
}
