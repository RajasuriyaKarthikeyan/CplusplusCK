#include <iostream>
#include <future>
#include <chrono>
#include <thread> // ✅ Needed for std::this_thread::sleep_for

// A function that simulates some heavy work
int slowAdd(int a, int b) {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    return a + b;
}

int main() {
    std::cout << "Launching async task..." << std::endl;

    // Launch slowAdd asynchronously
    std::future<int> result = std::async(std::launch::async, slowAdd, 10, 20);

    std::cout << "Doing something else while waiting...\n";

    // Do other work here if needed...

    // Block and get result
    int sum = result.get();
    std::cout << "Result: " << sum << std::endl;

    return 0;
}
