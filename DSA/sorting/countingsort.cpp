#include <iostream>

using namespace std;

void countingSort(int arr[],int n, int k){
    int counter[k+1] = {0},output[n],i;
    for(i=0;i<n;i++){
        counter[arr[i]]++;
    }
    for(i=1;i<=k;i++){
        counter[i]+=counter[i-1];
    }
    for(i=n-1;i>=0;i--){
        output[counter[arr[i]]-1] = arr[i];
        counter[arr[i]]--;
    }
    for(i=0;i<n;i++){
        arr[i]=output[i];
    }
}

int main(){
    int arr[10] = { 11, 3, 7, 3, 4 ,2, 4, 6, 7, 8};
    cout << "Array Before sorting : ";
    for(int i=0;i<10;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    countingSort(arr, 10,11);
    cout << "Array After sorting : ";
    for(int i=0;i<10;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}