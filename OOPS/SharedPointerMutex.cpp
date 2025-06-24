#include <iostream>
#include <thread>
#include <vector>
#include <memory>
#include <mutex>

class Account {
public:
    Account() : balance(0) {}

    void deposit(int amount) {
        std::lock_guard<std::mutex> lock(m);
        balance += amount;
    }

    int getBalance() const {
        std::lock_guard<std::mutex> lock(m);
        return balance;
    }

private:
    int balance;
    mutable std::mutex m;
};

void addMoney(std::shared_ptr<Account> acc) {
    for (int i = 0; i < 1000; ++i) {
        acc->deposit(1);
    }
}

int main() {
    auto account = std::make_shared<Account>();
    std::vector<std::thread> threads;

    for (int i = 0; i < 5; ++i) {
        threads.emplace_back(addMoney, account);
    }

    for (auto& t : threads) {
        t.join();
    }

    std::cout << "Final balance: " << account->getBalance() << std::endl;
    return 0;
}
