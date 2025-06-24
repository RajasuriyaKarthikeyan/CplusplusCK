#include <iostream>
using namespace std;

int main() {
   int var1 = 10;
   int var2 = 20;

   int* ptr = &var1; // ptr points to var1
   cout << "Value pointed by ptr: " << *ptr << endl; 

   ptr = &var2; // Modify ptr to point to var2
   cout << "Value pointed by ptr after modification: " << *ptr << endl;

   // Dynamic memory allocation
   int* dynamicPtr = new int(30);
   ptr = dynamicPtr; // Modify ptr to point to dynamic memory
   cout << "Value pointed by ptr after dynamic allocation: " << *ptr << endl;
   cout << "Value pointed by dynamicPtr after dynamic allocation: " << *dynamicPtr << endl;

   // Clean up dynamic memory
   delete dynamicPtr; 

   return 0;
}