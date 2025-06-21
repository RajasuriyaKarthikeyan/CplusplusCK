#include <iostream>
using namespace std;

class NumberOperation{
    private:
        int a,b;

    public:
        void initialize(int x, int y){
            a=x;
            b=y;
            cout << "a = " << a << endl;
            cout << "b = " << b << endl;
        }
        int add(){
            return a+b;
        }
        int powerOperation(){
            return a^b;
        }
};

int main(){
    NumberOperation num1;
    num1.initialize(2,10);
    int addResult = num1.add();
    int powerResult = num1.powerOperation();
    cout << "Addition Result of Initialized values " << addResult << endl;
    cout << "Power Result of Initialized values " << powerResult << endl;
    return 0;
}