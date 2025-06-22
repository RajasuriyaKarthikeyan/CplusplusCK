#include <iostream>

using namespace std;

class Box{
    private:
        int length, breadth, height;
    
    public:
        void setdata(int l, int b, int h){
            this->length=l;
            this->breadth=b;
            this->height=h;
        }
        friend void printdata(Box b); //Always remember to pass the object to access private and protected data
};

void printdata(Box b){
    cout << " Height : " << b.height << " Length : " << b.length << " Breadth : " << b.breadth << endl;
}

int main(){
    Box b1;
    b1.setdata(10,10,20);
    printdata(b1);
    return 0;
}