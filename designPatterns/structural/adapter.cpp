#include <iostream>
using namespace std;

/*The Adapter Pattern is a structural design pattern that allows incompatible interfaces to work together 
by wrapping an existing class with a new interface.*/

// 1. Target interface
class ModernPrinter {
public:
    virtual void printDocument() = 0;
    virtual ~ModernPrinter() {}
};

// 2. Adaptee (existing legacy class)
class LegacyPrinter {
public:
    void oldPrint() {
        cout << "Printing using legacy printer...\n";
    }
};

// 3. Adapter class
class PrinterAdapter : public ModernPrinter {
    LegacyPrinter* legacy;
public:
    PrinterAdapter(LegacyPrinter* lp) : legacy(lp) {}

    void printDocument() override {
        legacy->oldPrint(); // adapt the call
    }
};

// 4. Client code
int main() {
    LegacyPrinter* oldPrinter = new LegacyPrinter();
    ModernPrinter* printer = new PrinterAdapter(oldPrinter);

    printer->printDocument();  // Client uses modern interface

    delete oldPrinter;
    delete printer;
    return 0;
}
