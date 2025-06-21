#include <iostream>

using namespace std;

int partition(int arr[], int low, int high){
    int pivotIndex = high;
    int i=low;
    for(int j=low;j<=high;j++){
        if(arr[j]<arr[pivotIndex]){
            swap(arr[i],arr[j]);
            i++;
        }
    }
    swap(arr[i],arr[high]);
    return i;
}

void quickSort(int arr[],int low,int high){
    if(low < high){
        int pivot = partition(arr,low,high);
        quickSort(arr,low,pivot-1);
        quickSort(arr,pivot+1,high);
    }
}


int main(){
    int arr[10] = { 11, 32, 7, 3, 4 ,2, 4, 6, 7, 8};
    cout << "Array Before sorting : ";
    for(int i=0;i<10;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    quickSort(arr,0,9);
    cout << "Array After sorting : ";
    for(int i=0;i<10;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}