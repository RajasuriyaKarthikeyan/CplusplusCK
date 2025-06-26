#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <chrono>

std::mutex mtx;
std::condition_variable cv;
std::queue<int> data_queue;
bool done = false;

void producer() {
    for (int i = 1; i <= 5; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Simulate work
        {
            std::lock_guard<std::mutex> lock(mtx);
            data_queue.push(i);
            std::cout << "Producer: produced " << i << "\n";
        }
        cv.notify_one(); // Notify the consumer
    }

    {
        std::lock_guard<std::mutex> lock(mtx);
        done = true;
    }
    cv.notify_one(); // Let consumer know we're done
}

void consumer() {
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] { return !data_queue.empty() || done; });

        while (!data_queue.empty()) {
            int value = data_queue.front();
            data_queue.pop();
            std::cout << "Consumer: consumed " << value << "\n";
        }

        if (done) break;
    }
}

int main() {
    std::thread prod(producer);
    std::thread cons(consumer);

    prod.join();
    cons.join();

    std::cout << "All work done.\n";
    return 0;
}
