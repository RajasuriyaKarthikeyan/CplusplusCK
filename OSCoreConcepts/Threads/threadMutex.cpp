#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;  // global mutex
int counter = 0;

void incrementCounter() {
    for (int i = 0; i < 1000; ++i) {
        mtx.lock();       // lock before accessing shared resource
        ++counter;
        mtx.unlock();     // unlock after done
    }
}

int main() {
    std::thread t1(incrementCounter);
    std::thread t2(incrementCounter);

    t1.join();
    t2.join();

    std::cout << "Final counter value: " << counter << std::endl;
    return 0;
}
