#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>

std::atomic<bool> stopFlag(false);

void worker() {
    while (!stopFlag) {
        std::cout << "Working..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    std::cout << "Thread stopping gracefully." << std::endl;
}

int main() {
    std::thread t(worker);

    std::this_thread::sleep_for(std::chrono::seconds(3));
    stopFlag = true;  // Signal the thread to stop

    t.join();
    return 0;
}
