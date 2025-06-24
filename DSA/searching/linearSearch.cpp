#include <iostream>

using namespace std;

int linear_Search(int arr[], int n ,int element){
    int index = -1;
    int i;
    for(i=0;i<n;i++){
        if(arr[i] == element){
            index = i;
            break;
        }
    }
    return index;
}

int main(){
    int arr[6] = {20,31,22,34,45,23};
    int element = 34;
    int index = linear_Search(arr, 6, element);
    if(index != -1){
        cout << "Element found at the index : " << index << endl;
    } else{
        cout << "Element not found in the array" << endl;
    }
    return 0;
}