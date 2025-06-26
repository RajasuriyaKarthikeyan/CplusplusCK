#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

std::mutex mtx;
std::condition_variable cv;
bool data_ready = false;

void producer() {
    std::this_thread::sleep_for(std::chrono::seconds(1)); // Simulate work
    std::lock_guard<std::mutex> lock(mtx);
    data_ready = true;
    std::cout << "Producer: Data is ready.\n";
    cv.notify_one(); // Notify the waiting consumer
}

void consumer() {
    std::unique_lock<std::mutex> lock(mtx);
    std::cout << "Consumer: Waiting for data...\n";
    
    // Wait until data_ready becomes true
    cv.wait(lock, [] { return data_ready; });

    std::cout << "Consumer: Data received. Processing...\n";
}

int main() {
    std::thread t1(producer);
    std::thread t2(consumer);

    t1.join();
    t2.join();

    return 0;
}
