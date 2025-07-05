#include <iostream>

using namespace std;

class A {
    public:
        int a = 10; // accessible anywhere
        A(){
            cout << "Private Value : " << b << endl;
            cout << "Protected Value : " << c << endl;
        }
    private:
        int b = 100; // accessible only within class A    
    protected:
        int c = 1000; // accessible by class A and classes inherit the object

    
};

class B: public A{
    public:
        B(){
            cout << "Protect content of A : " << c << endl;
        }
};


int main(){
    A a;
    cout << "Public specifier : " << a.a << endl;
    B b;
    cout << "Public specifier dervice from a : " << b.a << endl;
    // Fail -> cout << "Private Specifier : " << a.b << endl;
    // Fail -> cout << "Protected Specifier : " << a.c << endl; 
}