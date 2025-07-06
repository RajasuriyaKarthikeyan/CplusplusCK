#include <iostream>

using namespace std;

int main(){
    int *a = new int(); // default initialize with zero
    *a = 10;
    cout << "a : " << *a << endl;
    int *b = new int[10]; // Default initialize with zero
    cout << "b : " << *b << endl;
    delete a;
    delete[] b;

    int *c = (int*)malloc(sizeof(int)); // Initialize garbage value
    cout << "c : " << *c << endl;
    free(c);

}