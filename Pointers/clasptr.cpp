#include <iostream>
#include <string>

using namespace std;

class CS{
    public:
        int area = 10;
        string name = "suriya";
        
        void printName(){
            cout << name << endl;
        }

        int returnArea(int x){
            if(x > area){
                return x;
            } else {
                return area;
            }
        }
    
};

int main(){
    CS obj ;
    CS *c1 = &obj;
    c1->printName();
    cout << "c1 area : " << c1->returnArea(11) << endl;
    void (CS::*printptr)() = &CS::printName;
    (obj.*printptr)();
    int (CS::*ReturnAREA)(int) = &CS::returnArea;
    cout << "Area : " << (obj.*ReturnAREA)(100) << endl;
    return 0;
}