#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
int number = 1;
const int MAX_NUMBER = 20;
bool is_even_turn = false; // false means odd thread starts first

void print_odd() {
    while (number <= MAX_NUMBER) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] { return !is_even_turn; });

        if (number <= MAX_NUMBER && number % 2 == 1) {
            std::cout << "Odd: " << number << std::endl;
            number++;
            is_even_turn = true;
        }

        cv.notify_all();
    }
}

void print_even() {
    while (number <= MAX_NUMBER) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] { return is_even_turn; });

        if (number <= MAX_NUMBER && number % 2 == 0) {
            std::cout << "Even: " << number << std::endl;
            number++;
            is_even_turn = false;
        }

        cv.notify_all();
    }
}

int main() {
    std::thread t1(print_odd);
    std::thread t2(print_even);

    t1.join();
    t2.join();

    return 0;
}
