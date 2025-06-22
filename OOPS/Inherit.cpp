#include <iostream>

using namespace std;

class Shape{
    protected:
        int length, breadth;

    public:
        // Shape(int l,int b){
        //     length=l;
        //     breadth = b;
        // }

        void setData(int l, int b){
            length = l;
            breadth = b;
        }
        
};

class rectangle: public Shape{
    private:
        int area;
    
    public:
        rectangle(int l, int b){
            setData(l,b);
        }
        int calculateArea(){
            area = length*breadth;
            return length*breadth;
        }
};

int main(){
    rectangle r(10,200);
    cout << "Area(10,200) : "<< r.calculateArea() << endl;
    r.setData(2,34);
    cout << "Area(2,34) : " << r.calculateArea() << endl;
    return 0;
}