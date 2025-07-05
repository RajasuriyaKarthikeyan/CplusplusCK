#include <iostream>

using namespace std;

class Box{
    private:
        int length, breadth, height;
        int volume;
    public:
        void setdata(int l, int b, int h){
            this->length=l;
            this->breadth=b;
            this->height=h;
        }
        friend void printdata(Box b); //Always remember to pass the object to access private and protected data
        friend void FindVolume(Box b);
};

void printdata(Box b){
    cout << " Height : " << b.height << " Length : " << b.length << " Breadth : " << b.breadth << endl;
}

void FindVolume(Box b){
    b.volume = b.breadth*b.length*b.height;
    cout << "Volume : " << b.volume << endl;;
}

class B;

class A{
    private:
        int balance = 100;
    public:
        friend int ReturnTotalBalance(A, B);
};

class B{
    private:
        int balance = 200;
    public:
        friend int ReturnTotalBalance(A, B);
};

int ReturnTotalBalance(A a, B b){
    return a.balance +b.balance;
}


int main(){
    Box b1;
    b1.setdata(10,10,20);
    printdata(b1);
    FindVolume(b1);
    A aobj;
    B bobj;
    cout << "Total Balance of All classes : " << ReturnTotalBalance(aobj, bobj) << endl;
    return 0;
}