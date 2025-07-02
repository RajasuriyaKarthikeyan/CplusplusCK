#include <iostream>

using namespace std;

void PrimeNoCheck(int n){
    for(int i=2;i<n;i++){
        if(n%i==0){
            cout << "Not a Prime Number " << endl;
            return;
        }
    }
    cout << "Prime Number" << endl;
}

int main(){
    cout << "Input Number to check if its prime : ";
    int no;
    cin >> no;
    PrimeNoCheck(no);
    return 0;
}