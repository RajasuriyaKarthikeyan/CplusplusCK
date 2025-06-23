#include <iostream>
#include <string>

using namespace std;

int main(){
    string s1 = "Hello";
    string s2 = "Barcelona";
    string s3 = s1+" "+s2;
    cout << "s3 string : " << s3 << endl;
    cout << "s3 size : " << s3.size() << endl;
    cout << "s1 Traversing " << endl;
    for(int i=0;i<s1.length();i++){
        cout << s1[i];
    }
    cout << endl;
    cout << "s2 Traversing " << endl;
    for(char c: s2){
        cout << c;
    }
    cout << endl;
    return 0;
}