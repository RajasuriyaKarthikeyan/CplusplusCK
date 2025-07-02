#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> number;
    int value;
    for(int i=0;i<5;i++){
        cin >> value;
        number.push_back(value);
    }
    sort(number.begin(),number.end());
    cout << "Sorted order " <<endl;
    for(int num:number){
        cout << num << endl; 
    }
    return 0;
}