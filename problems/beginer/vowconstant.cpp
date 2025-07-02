#include <iostream>
#include <string>

using namespace std;

int main(){
    string name;
    cin >> name;

    int vc = 0, cc = 0;
    for(auto c: name){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
            vc++;
        } else {
            cc++;
        }
    }
    cout << "Vowels Count : " << vc << endl;
    cout << "Consonants Count : " << cc << endl;

    return 0;
}
