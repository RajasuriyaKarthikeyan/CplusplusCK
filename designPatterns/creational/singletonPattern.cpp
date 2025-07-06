#include <iostream>

/*
A singleton pattern is a design pattern that ensures that only one instance of a class can exist in the entire program.
This means that if you try to create another instance of the class, it will return the same instance that was created earlier.
*/

using namespace std;

class Singleton{
    public:
        static Singleton& getInstance(){
            if(!instance){
                instance = new Singleton();
            }
            return *instance;
        }

        void PerformOperation(){
            cout << " Performing Operation in Singleton " << endl;
        }

        Singleton(const Singleton&) = delete;
        Singleton& operator=(const Singleton&) = delete;

    private:
        Singleton(){
            cout << "Singleton constructor called" << endl;
        }
        ~Singleton(){
            cout << "Singleton destructor called" << endl;
        }

        static Singleton *instance;
};

Singleton* Singleton::instance = nullptr;

int main(){
    Singleton& single = Singleton::getInstance();
    single.PerformOperation();
    Singleton& another = Singleton::getInstance();
    another.PerformOperation();
    single.PerformOperation();
    return 0;
}


