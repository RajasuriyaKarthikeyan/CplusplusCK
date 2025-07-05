#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>


using namespace std;

class Student {
private:
    int age;

public:
    Student(int age) {
        if (age < 0)
            throw invalid_argument("Age cannot be negative");
        this->age = age;
    }

    void display() {
        cout << "Age: " << age << endl;
    }
};

class Account {
private:
    double balance;

public:
    Account(double amount = 0.0) : balance(amount) {}

    void withdraw(double amount) {
        if (amount > balance)
            throw runtime_error("Insufficient funds");
        balance -= amount;
    }

    void showBalance() {
        cout << "Balance: " << balance << endl;
    }
};

class Suriya : public exception{
    private:
        string s = "";
    public:
        Suriya(string name){
            s=name;
        }
/*
| Part            | Meaning                                                  |
| --------------- | -------------------------------------------------------- |
| `const char*`   | Return type: C-style string (null-terminated)            |
| `what()`        | Function that returns an error message                   |
| `const`         | Means this function does **not** modify the object       |
| `noexcept`      | Guarantees this function won't throw exceptions          |
| `override`      | This overrides the `what()` method from `std::exception` |
| `s.c_str()` | Returns the internal `std::string` as a C-style string   |
*/
        const char* what() const noexcept override 
        {
            return s.c_str();
        }
};

int main(){
    try {
        try {
            throw Suriya("Suriya exception");
        } catch (const Suriya& ex) {
            std::string newMsg {"rethrow: "};
            newMsg += ex.what();
            std::cout << ex.what() << "\n";
            throw Suriya(newMsg.c_str());
        }
    } catch (const Suriya& ex) {
        std::cout << ex.what() << "\n";
    }

    try {
        Student s(-5);  // Throws exception
        s.display();
    } catch (const exception& e) {
        cout << "Exception: " << e.what() << endl;
    }

    Account a(1000);
    try {
        a.withdraw(1200);  // Throws
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}
