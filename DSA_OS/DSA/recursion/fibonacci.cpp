#include <iostream>

using namespace std;

int fibonacci(int n){
    if(n == 0 || n == 1)
        return n;
    return fibonacci(n-1)+fibonacci(n-2);
}

int main(){
    cout << "Fibonacci for size 8 : ";
    for(int i=0;i<8;i++){
        cout << fibonacci(i) << " ";
    }
}