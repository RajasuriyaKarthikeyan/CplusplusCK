#include <iostream>

using namespace std;

inline int calculateSum(int a, int b){
    return a+b;
}
int main(){
    cout << "Calling Inline Calculate Sum : " << calculateSum(10,20) << endl;
    // the compiler places a copy of the code of that function at each point
    return 0;
}