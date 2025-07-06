#include <iostream>
#include <string>

/*
The Builder Pattern is a creational design pattern used to construct complex objects step by step. 
It separates object construction from its representation, allowing the same construction process to create different representations.
*/
using namespace std;

// 1. Product
class Computer {
public:
    string cpu;
    string gpu;
    string ram;
    string storage;

    void show() {
        cout << "CPU: " << cpu << "\n"
             << "GPU: " << gpu << "\n"
             << "RAM: " << ram << "\n"
             << "Storage: " << storage << "\n";
    }
};

// 2. Abstract Builder
class ComputerBuilder {
public:
    virtual void buildCPU() = 0;
    virtual void buildGPU() = 0;
    virtual void buildRAM() = 0;
    virtual void buildStorage() = 0;
    virtual Computer* getComputer() = 0;
    virtual ~ComputerBuilder() {}
};

// 3. Concrete Builder
class GamingComputerBuilder : public ComputerBuilder {
private:
    Computer* computer;

public:
    GamingComputerBuilder() {
        computer = new Computer();
    }

    void buildCPU() override {
        computer->cpu = "Intel i9";
    }

    void buildGPU() override {
        computer->gpu = "NVIDIA RTX 4090";
    }

    void buildRAM() override {
        computer->ram = "32GB DDR5";
    }

    void buildStorage() override {
        computer->storage = "2TB SSD";
    }

    Computer* getComputer() override {
        return computer;
    }
};

// 4. Director (optional)
class Director {
public:
    void construct(ComputerBuilder* builder) {
        builder->buildCPU();
        builder->buildGPU();
        builder->buildRAM();
        builder->buildStorage();
    }
};

// 5. Client
int main() {
    GamingComputerBuilder builder;
    Director director;

    director.construct(&builder);
    Computer* pc = builder.getComputer();

    cout << "Gaming PC Configuration:\n";
    pc->show();

    delete pc;
    return 0;
}
