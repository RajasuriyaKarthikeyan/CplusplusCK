#include <iostream>

using namespace std;

int min(int a, int b){
    return (a > b) ? b : a;
}

int fibonacciSearch(int arr[], int n, int key){
    int offset = -1;
    int fm2 = 0;
    int fm1 = 1;
    int fm = fm1+fm2;
    while (fm < n)
    {
        fm2 = fm1;
        fm1 = fm;
        fm = fm1+fm2;
    }
    while (fm > 1)
    {
        int i = min(offset+fm2 ,n-1);
        if(arr[i] < key){
            fm = fm1;
            fm1 = fm2;
            fm2 = fm - fm1;
            offset = i;
        } else if (arr[i] > key){
            fm = fm2;
            fm1 = fm1 - fm2;
            fm2 = fm - fm1;
        } else{
            return i;
        }
    }
    if(fm1 && arr[offset+1]==key){
        return offset+1;
    }
    return -1;
}

int main(){
    int arr[10] = {6,11,19,24,33,54,67,81,94,99};
    int pos = fibonacciSearch(arr, 10, 54);
    cout << " The element 54 found at " << pos << endl;
    pos = fibonacciSearch(arr, 10, 67);
    cout << " The element 67 found at " << pos << endl;
    pos = fibonacciSearch(arr, 10, 77);
    cout << " The element 77 found at " << pos << endl;
    return 0;
}