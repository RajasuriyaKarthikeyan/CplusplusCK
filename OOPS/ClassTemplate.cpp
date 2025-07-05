#include <iostream>

using namespace std;

template<class T>
class A{
    private:
        T input;
    public:
        A(T val){
            input = val;
        }
        void PrintData(){
            cout << " InpuT Data : " << input << endl;
        }
};

template<class X, class Y>
class Pairing
{
    public:
        X p1;
        Y p2;
        Pairing(X x1, Y y1) : p1(x1), p2(y1){}
        void PrintPairs(){
            cout << "p1 : " << p1 << " p2 : " << p2 << endl;
        }
};



int main(){
    A<int> b1(199);
    A<string> b2("Suriya");
    b1.PrintData();
    b2.PrintData();
    Pairing<int,int> P1(44,77);
    Pairing<string, string> P2("Suriya", "Games");
    P1.PrintPairs();
    P2.PrintPairs();
    return 0;
}



// template <class T>
// class Printer {
// public:
//     void print(T val) {
//         cout << "Value: " << val << endl;
//     }
// };

// // Specialization for bool
// template <>
// class Printer<bool> {
// public:
//     void print(bool val) {
//         cout << (val ? "True" : "False") << endl;
//     }
// };
