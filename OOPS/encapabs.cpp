#include <iostream>
using namespace std;

// Abstract class (interface for BankAccount)
class BankAccount {
public:
    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
    virtual void displayBalance() = 0;
    virtual ~BankAccount() {}  // Virtual destructor
};

// Concrete class that encapsulates data
class SavingsAccount : public BankAccount {
private:
    double balance;  // 🔐 Encapsulated data

public:
    SavingsAccount(double initialBalance) {
        balance = initialBalance;
    }

    // Abstraction: only expose deposit, withdraw, display
    void deposit(double amount) override {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << endl;
        }
    }

    void withdraw(double amount) override {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }

    void displayBalance() override {
        cout << "Current Balance: " << balance << endl;
    }
};

int main() {
    // Interface pointer (abstraction)
    BankAccount* account = new SavingsAccount(1000.0);
    SavingsAccount saccount(200.00);
    account->deposit(500.0);
    account->withdraw(300.0);
    account->displayBalance();
    saccount.deposit(100.00);
    saccount.displayBalance();
    delete account;  // Clean up
    return 0;
}
