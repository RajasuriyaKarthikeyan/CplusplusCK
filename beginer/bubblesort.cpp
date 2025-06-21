#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cout << "Enter Size : " ;
    cin >> n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int no;
        cin >> no;
        v.push_back(no);
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(v[i] > v[j]){
                int temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }

    cout << "After Bubble Sorting: ";
    for(auto ele: v){
        cout << ele << " ";
    }
    return 0;
}