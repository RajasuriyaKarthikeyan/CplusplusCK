#include <iostream>

using namespace std;

class Box {
    private:
        int length, breadth, height;
    public:
        void setdata(int l, int b, int h){
            this->breadth = b;
            this->height = h;
            this->length = l;
        }

        void getdata(){
            cout << "Length " << this->length << endl;
            cout << "Breadth " << this->breadth << endl;
            cout << "Height " << this->height << endl;
        }

};

int main(){
    Box *b1 = new Box();
    b1->setdata(10,2,7);
    b1->getdata();
    delete b1;
    return 0;
}