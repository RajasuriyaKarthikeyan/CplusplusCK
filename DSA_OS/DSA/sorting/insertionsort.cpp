#include <iostream>

using namespace std;

void insertionSort(int arr[],int size){
    int key, j;
    for(int i=1;i<size;i++){
        key = arr[i];
        j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main(){
    int arr[10] = { 11, 32, 7, 3, 4 ,2, 4, 6, 7, 8};
    cout << "Array Before sorting : ";
    for(int i=0;i<10;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    insertionSort(arr, 10);
    cout << "Array After sorting : ";
    for(int i=0;i<10;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}