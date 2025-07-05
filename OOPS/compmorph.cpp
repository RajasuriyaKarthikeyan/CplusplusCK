#include <iostream>
using namespace std;

//Function overloading
class Print {
public:
    void show(int i) {
        cout << "Integer: " << i << endl;
    }
    void show(double d) {
        cout << "Double: " << d << endl;
    }
    void show(string s) {
        cout << "String: " << s << endl;
    }
};

//Operator Overloading
class Ops{
    public:
        void printVal(){
            cout << " x : "<< x << " y : "  << y << endl;
        }
        void operator+(Ops &other){
            x=x+other.x;
            y=y+other.y;
        }
        void operator-(Ops &other){
            y-=other.y;
            x-=other.x;
        }
        // Ops operator+(const Ops &obj1){
        //     x=10+obj1.x;
        //     y=10+obj1.y;
        //     return *this;
        // }

        Ops(int valX,int valY): x{valX}, y{valY}{

        }

    private:
        int x,y;

};

int main() {
    Print obj;
    obj.show(10);
    obj.show(3.14);
    obj.show("Hello");
    Ops o1(10,20);
    o1.printVal();
    Ops o2(11,22);
    o2.printVal();
    o1+o2;
    o1.printVal();
    o2-o1;
    o2.printVal();
    o2+o1;
    o2.printVal();
    // Ops o3 = o1+o2;
    return 0;
}
