#include <iostream>

using namespace std;

void merge(int arr[], int mid, int left, int right){
    int i,j,k,n1,n2;
    n1 = mid - left + 1;
    n2 = right - mid;

    int leftArr[n1],rightArr[n2]; 

    for(i=0;i<n1;i++){
        // cout << "For loop1";
        leftArr[i] = arr[left+i];
    }
    for(i=0;i<n2;i++){
        // cout << "For loop 2";
        rightArr[i] = arr[mid+i+1];
    }

    i=0,j=0,k=left;
    while(i<n1 && j<n2){
        // cout << "loop1";
        if(leftArr[i] < rightArr[j]){
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        // cout << "loop 2";
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while(j<n2){
        // cout << "loop3";
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergesort(int arr[], int left, int right){
    if(left < right){
        int mid = left + (right-left) / 2;
        cout << "Left Recurision" << endl;
        mergesort(arr, left, mid);
        cout << "Right Recursion " << endl;
        mergesort(arr, mid+1, right);

        merge(arr,mid,left,right);
    }
}

int main(){
    int arr[10] = { 11, 32, 7, 3, 4 ,2, 4, 6, 7, 8};
    cout << "Array Before sorting : ";
    for(int i=0;i<10;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    mergesort(arr,0,9);
    cout << "Array After sorting : ";
    for(int i=0;i<10;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}