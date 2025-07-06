#include <iostream>
#include <memory>

using namespace std;

class Sample{
    public:
        Sample(){
            cout << "Constructor called" << endl;
        }

        void owner(string name){
            cout << "Called by " << name << endl;
        }

        ~Sample(){
            cout << "Destructor called " << endl;
        }
};

int main(){
    unique_ptr<Sample> u1 = make_unique<Sample>();
    u1->owner("u1");
    // unique_ptr<Sample> u2 = u1;  Can't copy
    cout << "Changing ownership u1 -> u3" << endl;
    unique_ptr<Sample> u3 = move(u1);
    u3->owner("u3");
    if(!u1){
        cout << "u1 is null" << endl;
    }
    cout << "Changing ownership u3 -> u1" << endl;
    u1 = move(u3);
    if(!u3){
        cout << "u3 is null" << endl;
    }
    u1->owner("u1");
    

    shared_ptr<Sample> s1 = make_shared<Sample>();
    s1->owner("s1");
    shared_ptr<Sample> s2 = s1;
    weak_ptr<Sample> w1 = s1; // doesn't increase ref count
    s2->owner("s2");
    cout << "Shared object count : " << s2.use_count() << endl;


}