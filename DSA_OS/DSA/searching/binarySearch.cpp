#include <iostream>

using namespace std;

void binary_search(int arr[], int low, int high, int key){
    int mid = (low+high)/2;
    if(low <=high){
        if(arr[mid] == key){
            cout << "Element found at index : " << mid << endl;
        } else if(arr[mid] < key){
            binary_search(arr, mid+1, high, key);
        } else if(arr[mid] > key){
            binary_search(arr, low, mid-1, key);
        }
    } else {
        cout << "Element not found " << endl;
    }
}

int main(){
    int n = 7;
    int low = 0, high = n-1;
    int key = 22;
    int arr[7] = {11,22,33,44,55,66,77};
    binary_search(arr, low, high, key);
    key = 56;
    binary_search(arr, low, high, key);
    return 0;
}