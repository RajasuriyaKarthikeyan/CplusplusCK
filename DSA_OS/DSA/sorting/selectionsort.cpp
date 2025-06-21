#include <iostream>

using namespace std;

void selectionSort(int arr[],int size){
    int i,j,temp, minIndex;
    for(i=0;i<size-1;i++){
        minIndex = i;
        for(j=i+1;j<size;j++){
            if(arr[minIndex] > arr[j])
                minIndex = j;
        }
        if(minIndex != i){
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
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
    selectionSort(arr, 10);
    cout << "Array After sorting : ";
    for(int i=0;i<10;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}