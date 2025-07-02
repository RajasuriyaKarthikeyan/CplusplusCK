#include <iostream>
using namespace std;
int g = 10;
int main(){
    int g = 5;
    cout << g << endl;
    ::g = 10+20;
    cout << g << endl;
    cout << ::g << endl;
    return 0;
}