#include <iostream>
using namespace std;

/*
an interface for creating families of related objects without specifying their concrete classes.
It’s useful when your application needs to be platform-independent or when working with interchangeable product families
Create objects without specifying their concrete class — and group related objects together.
*/

// 1. Abstract Products
class Button {
public:
    virtual void render() = 0;
    virtual ~Button() = default;
};

class Checkbox {
public:
    virtual void check() = 0;
    virtual ~Checkbox() = default;
};

// 2. Concrete Products for Windows
class WindowsButton : public Button {
public:
    void render() override {
        cout << "Render Windows Button\n";
    }
};

class WindowsCheckbox : public Checkbox {
public:
    void check() override {
        cout << "Check Windows Checkbox\n";
    }
};

// 3. Concrete Products for Mac
class MacButton : public Button {
public:
    void render() override {
        cout << "Render Mac Button\n";
    }
};

class MacCheckbox : public Checkbox {
public:
    void check() override {
        cout << "Check Mac Checkbox\n";
    }
};

// 4. Abstract Factory
class GUIFactory {
public:
    virtual Button* createButton() = 0;
    virtual Checkbox* createCheckbox() = 0;
    virtual ~GUIFactory() = default;
};

// 5. Concrete Factories
class WindowsFactory : public GUIFactory {
public:
    Button* createButton() override {
        return new WindowsButton();
    }
    Checkbox* createCheckbox() override {
        return new WindowsCheckbox();
    }
};

class MacFactory : public GUIFactory {
public:
    Button* createButton() override {
        return new MacButton();
    }
    Checkbox* createCheckbox() override {
        return new MacCheckbox();
    }
};

// 6. Client Code
void createUI(GUIFactory* factory) {
    Button* btn = factory->createButton();
    Checkbox* cb = factory->createCheckbox();

    btn->render();
    cb->check();

    delete btn;
    delete cb;
}

int main() {
    GUIFactory* factory;

    // Switch easily by platform
    factory = new WindowsFactory();
    createUI(factory);
    delete factory;

    factory = new MacFactory();
    createUI(factory);
    delete factory;

    return 0;
}
