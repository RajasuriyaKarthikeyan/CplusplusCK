#include <iostream>
using namespace std;

class A {
private:
    int x = 100;

public:
    A() {
        cout << "A() constructor called : x = " << x << endl;
    }

    A(int a, int b = 20) {  // Fixed: default parameter on the right
        cout << "A(int a, int b=20) constructor called : a = " << a <<" b = " << b << endl;
        x = a + b;
    }

    A(A &other) {
        x = other.x;
        cout << "Copy Constructor: updated x value = " << x << endl;
    }
    A(A &&other){
        x = other.x;
        other.x = 2000;
        cout << "Move constructor called" << endl;

    }

    void show(){
        cout << " X value : " << x << endl;
    }

    ~A() {
        cout << "~A() destructor called" << endl;
    }
};

int main() {
    A* a1 = new A();  // Calls default constructor
    a1->show();
    A a2(10,100);
    a2.show(); // Parametrized const
    A a3 = a2; // copy construcor
    a3.show();
    A a4 = move(a3); // move constructor
    a4.show();
    cout << " a3 show after move" << endl;
    a3.show();
    delete a1;        // Free memory; destructor is called

    return 0;
}
