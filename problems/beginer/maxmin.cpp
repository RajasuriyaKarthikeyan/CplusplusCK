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

    int maxNo = v[0], minNo = v[0];
    for(int i=1;i<n;i++){
        if(v[i]>maxNo){
            maxNo = v[i];
        }
        if(v[i]<minNo){
            minNo = v[i];
        }
    }
    cout << "Max no : " << maxNo << endl;
    cout << "Min no : " << minNo << endl;
    return 0;
}