#include <iostream>
#include <string>

using namespace std;

int main(){
    string name;
    cin >> name;

    string reverse_name = name; // Now initialized after input
    int i = 0, j = reverse_name.size() - 1;

    while(i < j){
        char c = reverse_name[i];
        reverse_name[i] = reverse_name[j];
        reverse_name[j] = c;
        i++;
        j--;
    }

    cout << "After Reverse : " << reverse_name << endl;

    if(name == reverse_name){
        cout << "Palindrome String" << endl;
    } else {
        cout << "Not a Palindrome String" << endl;
    }

    return 0;
}
