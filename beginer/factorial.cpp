#include <iostream>

using namespace std;

long factorial(int n){
    if(n==0 || n==1){
        return 1;
    } else {
        return factorial(n-1)*n;
    }
}

int main(){
    cout << "Input Number: ";

    int num;
    cin >> num;

    long fact = factorial(num);
    cout << "Factorial : " << fact << endl;
    return 0;
}
