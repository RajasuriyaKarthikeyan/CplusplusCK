#include <iostream>

using namespace std;

int main(){
    int a,b;
    cout << "Input A: ";
    cin >> a;
    cout << "Input B: ";
    cin >> b;

    a = a - b;
    b = a + b;
    a = b - a;

    cout << "After Swapping , a : " << a << " ,b : " << b << endl;
    return 0;
}