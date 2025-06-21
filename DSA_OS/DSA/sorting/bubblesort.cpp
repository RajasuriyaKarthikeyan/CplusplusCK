#include <iostream>

using namespace std;

void bubbleSort(int arr[], int size){
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(arr[j] > arr[i]){
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

int main(){
    int arr[10] = { 11, 32, 7, 3, 4 ,2, 4, 6, 7, 8};
    cout << "Array Before sorting : ";
    for(int i=0;i<10;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    bubbleSort(arr, 10);
    cout << "Array After sorting : ";
    for(int i=0;i<10;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}