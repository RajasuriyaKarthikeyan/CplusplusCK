#include <iostream>

using namespace std;

int main()
{
    int arr[10] = {};
    int ele;
    cout << "Array Elememts : ";
    for(int i=0;i<10;i++){
        cout << arr[i] << " ";
    }
    cout << "Inserting an element: " << endl;
    for(int i=0;i<10;i++){
        cin >>arr[i];
    }
    cout << "Find the element Index : ";
    cin >> ele;
    for(int i=0;i<10;i++){
        if(ele == arr[i]){
            cout << "Element Index : " << i << endl;
            break;
        } else if(i==9){
            cout << "Element is not present";
        }
    }
    cout << "Sorting the elements : " << endl;
    for(int i=0;i<9;i++){
        for(int j=i+1;j<10;j++){
            if(arr[i] > arr[j]){
                ele = arr[i];
                arr[i] = arr[j];
                arr[j] = ele;
            }
        }
    }
    cout << "Sorted order of the array : ";
    for(int i=0;i<10;i++){
        cout << arr[i] << " ";
    }
    return 0;
}