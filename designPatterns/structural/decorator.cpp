#include <iostream>
#include <string>
using namespace std;

/*The Decorator Pattern is a structural design pattern that lets you dynamically add behavior or responsibilities to objects 
without modifying their code.*/

// 1. Component interface
class Beverage {
public:
    virtual string getDescription() = 0;
    virtual double getCost() = 0;
    virtual ~Beverage() = default;
};

// 2. Concrete Component
class Coffee : public Beverage {
public:
    string getDescription() override {
        return "Plain Coffee";
    }
    double getCost() override {
        return 2.0;
    }
};

// 3. Decorator Base Class
class BeverageDecorator : public Beverage {
protected:
    Beverage* beverage;
public:
    BeverageDecorator(Beverage* b) : beverage(b) {}
};

// 4. Concrete Decorators
class MilkDecorator : public BeverageDecorator {
public:
    MilkDecorator(Beverage* b) : BeverageDecorator(b) {}

    string getDescription() override {
        return beverage->getDescription() + ", Milk";
    }

    double getCost() override {
        return beverage->getCost() + 0.5;
    }
};

class SugarDecorator : public BeverageDecorator {
public:
    SugarDecorator(Beverage* b) : BeverageDecorator(b) {}

    string getDescription() override {
        return beverage->getDescription() + ", Sugar";
    }

    double getCost() override {
        return beverage->getCost() + 0.2;
    }
};

// 5. Client Code
int main() {
    Beverage* coffee = new Coffee();
    coffee = new MilkDecorator(coffee);   // Add milk
    coffee = new SugarDecorator(coffee);  // Add sugar

    Beverage* kaffee = new Coffee();
    kaffee = new MilkDecorator(kaffee);
    cout << "Order: " << kaffee->getDescription() << endl;
    cout << "Cost: $" << kaffee->getCost() << endl;


    cout << "Order: " << coffee->getDescription() << endl;
    cout << "Cost: $" << coffee->getCost() << endl;

    delete coffee; // Clean-up (note: real app should manage inner objects too)
    delete kaffee;
    return 0;
}
