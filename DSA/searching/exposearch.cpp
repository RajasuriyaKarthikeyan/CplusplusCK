#include <iostream>
#include <cmath>

using namespace std;


int ExpoSearch(int arr[], int n, int key){
    int i=1, m, low = 0, high = n-1, mid;
    m=pow(2,i);
    if(arr[0] == key){
        return 0;
    } else {
        while(arr[m]<=key && m<n){
            i++;
            m = pow(2,i);
            while(low<=high){
                mid = (low+high)/2;
                if(arr[mid] == key)
                    return mid;
                else if(arr[mid] < key)
                    low = mid+1;
                else 
                    high = mid-1;
            }
        }
    }
    return -1;
}

int main(){
    int n=12;
    int arr[12] = {0,6,12,14,19,22,48,66,79,88,104,126};
    int find;
    find = ExpoSearch(arr,n,48);
    cout << "Element index : " << find << endl;
    find = ExpoSearch(arr,n,66);
    cout << "Element index : " << find << endl;
    find = ExpoSearch(arr,n,47);
    cout << "Element index : " << find << endl;
    return 0;
}