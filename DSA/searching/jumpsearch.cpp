#include <iostream>
#include <cmath>

using namespace std;

int JumpSearch(int arr[], int n, int key){
    int i, j, m, k;
   i = 0;
   m = sqrt(n);
   k = m;
   while(arr[m] <= key && m < n) {
      i = m;
      m += k;
      if(m > n - 1)
         return -1;
   }

   // linear search on the block
   for(j = i; j<m; j++) {
      if(arr[j] == key)
         return j;
   }
   return -1;
}

int main(){
    int n=12;
    int arr[12] = {0,6,12,14,19,22,48,66,79,88,104,126};
    int find;
    find = JumpSearch(arr,n,48);
    cout << "Element index : " << find << endl;
    find = JumpSearch(arr,n,66);
    cout << "Element index : " << find << endl;
    find = JumpSearch(arr,n,47);
    cout << "Element index : " << find << endl;
    return 0;
}