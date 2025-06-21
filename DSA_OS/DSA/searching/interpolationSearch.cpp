#include <iostream>

using namespace std;

void interPolationSearch(int arr[], int low, int high, int key){
    int mid = low + (((high-low)*(key-arr[low]))/(arr[high]-arr[low]));
    if(low<=high){
        if(arr[mid] == key){
            cout << "Element found at index : " << mid << endl;
        } else if(arr[mid] < key){
            interPolationSearch(arr, mid+1, high, key);
        } else if(arr[mid] > key){
            interPolationSearch(arr, low, mid-1, key);
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
    interPolationSearch(arr, low, high, key);
    key = 56;
    interPolationSearch(arr, low, high, key);
    return 0;
}