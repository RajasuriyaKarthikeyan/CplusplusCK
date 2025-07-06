#include <iostream>

using namespace std;

class Sample{
        
    public:
        int *data;
        Sample(int val){
            data = new int(val);
        }

        
        // Sample(const Sample& other){ // Shallow copy copy
        //     data = other.data;
        // }
        
        Sample(const Sample& other){ // Deep copy
            data = new int(*other.data);
        }

        void show(){
            cout << "Data : " << *data << "Address : " << data << endl;
        }
        
        ~Sample(){
            // will cause issue due to shallow copy (Core dump)
            delete data;
            cout << "Destructor called" << endl;
        }
};

int main(){
    Sample s1(10);
    s1.show();
    Sample s2 = s1; // Deep copy happens here with default copy constructor
    s2.show();
    cout << "Update s2 value " << endl;
    *s2.data = 100;
    s2.show();
    cout << "Check s1 value " << endl;
    s1.show();
    Sample s3(s1); // Deep copy happens here with custom copy constructor
    s3.show();
    
}
