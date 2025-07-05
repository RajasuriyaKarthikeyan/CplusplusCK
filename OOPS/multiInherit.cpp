#include <iostream>

using namespace std;

class A{
    public:
        A(){
            cout << "A called" << endl;
        }
        ~A(){
            cout << "A destroyed" << endl;
        }
};

class B: public A{
    public:
        B(){
            cout << "B called" << endl;
        }
        ~B(){
            cout << "B destroyed" << endl;
        }
};

class C: public B{
    public:
        C(){
            cout << "C called constructor" << endl;
        }
        ~C(){
            cout << "C destroyed" << endl;
        }
};

// destroy order of beloew object is reverse of creation order

int main(){
    cout << "A object creating" << endl;
    A a;
    cout << "B object creating" << endl;
    B b;
    cout << "C object creating" << endl;
    C c;
    return 0;
}