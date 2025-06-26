#include <iostream>
#include <thread>
#include <future>
#include <chrono>

void computeSum(std::promise<int> prom, int a, int b) {
    std::this_thread::sleep_for(std::chrono::seconds(2)); // simulate work
    int result = a + b;
    prom.set_value(result); // send result to future
}

int main() {
    std::promise<int> prom;          // create promise
    std::future<int> fut = prom.get_future();  // get associated future

    std::cout << "Starting thread...\n";
    std::thread t(computeSum, std::move(prom), 10, 20);  // pass promise to thread

    std::cout << "Waiting for result...\n";
    int sum = fut.get();  // blocks until promise sets value
    std::cout << "Result from thread: " << sum << std::endl;

    t.join();  // join the thread
    return 0;
}
