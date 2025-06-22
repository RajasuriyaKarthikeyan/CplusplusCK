#include <iostream>

using namespace std;

class Box {
    private:
        int length, breadth, height;
    public:
        static int Objcount;  // To Keep count of Object created

        Box(){
            Objcount++; // Incrementing object count
        }
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

        int getvolume(){
            return length*breadth*height;
        }

        static int getObjectCount(){
            return Objcount;
        }

};

int Box::Objcount = 0; // Initialissing the static member 
//Call it with class name ->better option

int main(){
    cout << "Object Count: " << Box::getObjectCount() << endl; // can be called if no object even created
    Box *b1 = new Box();
    b1->setdata(10,2,7);
    b1->getdata();
    cout << "Object Count: " << Box::getObjectCount() << endl;
    Box *b2 = new Box();
    b2->setdata(1,3,2);
    b2->getdata();
    cout << "Volume of box b1 : " << b1->getvolume() << endl;
    cout << "Volume of box b2 : " << b2->getvolume() << endl;
    cout << "Object Count: " << Box::getObjectCount() << endl;  // Box::Objcount works, b1->objcount, Box::getobjectcount too
    delete b2;
    delete b1;
    return 0;
}