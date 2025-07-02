#include <iostream>
#include <string>

using namespace std;

int main(){

    string name;
    cin >> name;
    cout << "After Reverse : ";
    int l = name.size();
    int i=0, j=l-1;
    while(i < j){
        char c = name[i];
        name[i] = name[j];
        name[j] = c;
        i++;
        j--;
    }
    cout <<name << endl;
    return 0;
}