#include <iostream>

using namespace std;

int main(){
   int x = 5, y = 10;

// 1. Pointer to constant
const int* a = &x;   // a can point to another int, but cannot modify *a

// 2. Constant pointer
int* const b = &x;   // b cannot point elsewhere, but *b can be modified

// 3. Constant pointer to constant
const int* const c = &x;  // c cannot point elsewhere, and *c cannot be modified
 
}