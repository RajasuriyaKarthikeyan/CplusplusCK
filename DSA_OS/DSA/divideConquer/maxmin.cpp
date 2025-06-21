#include <iostream>

using namespace std;

struct Pair{
    int max, min;
};

Pair maxmin(int arr[],int start, int end){
    Pair result, left, right;
    if(start == end){
        result.max = arr[start];
        result.min = arr[start];
        return result;
    }

    if(start+1 == end){
        if(arr[start]>arr[end]){
            result.max = arr[start];
            result.min = arr[end];
        } else {
            result.max = arr[end];
            result.min = arr[start];
        }
        return result;
    }

    int mid = (start+end)/2;
    left = maxmin(arr, start, mid);
    right = maxmin(arr, mid+1, end);

    if(left.max > right.max){
        result.max = left.max;
    } else {
        result.max = right.max;
    }

    if(left.min < right.min){
        result.min = left.min;
    } else {
        result.min = right.min;
    }

    return result;
}

void printArray(int arr[], int size){
    for(int i=0;i<size;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {35, 21, 19, 34, 99, 23, 44, 97};
    Pair result = maxmin(arr, 0, 7);
    cout << "Array Element : ";
    printArray(arr,8);
    cout << "Max element : " << result.max << endl;
    cout << "Min element : " << result.min << endl;
    return 0;
}