#include <stdio.h>

void main(){
    /* Both are Equivalent*/
    char *name_ptr = "SURIYA";
    char name_arr[] = "suriya";

    /*1. similarity bw arr and ptr*/
    printf("name_ptr: %s, name_ptr: %p, *name_ptr: %c\n", name_ptr, name_ptr, *name_ptr);
    //      name_ptr: SURIYA, name_ptr: 0x5a95ae6a6008, *name_ptr: S 
    printf("name_arr: %s, name_arr: %p, *name_arr: %c\n", name_arr, name_arr, *name_arr);
    //      name_arr: suriya, name_arr: 0x7ffda4fd07a1, *name_arr: s

    /*2. Difference between array and pointers*/
    printf("sizeof(nameptr): %lu, sizeof(namearr): %lu\n", sizeof(name_ptr), sizeof(name_arr));
    //      sizeof(nameptr): 8, sizeof(namearr): 7 suriya\0

    int x[] = {10, 11, 12};
    int *xptr = x;
    printf("sizeof(xptr): %lu, sizeof(x): %lu\n", sizeof(xptr), sizeof(x));
    //      sizeof(xptr): 8, sizeof(x): 12

    /* 3. Array cannot be ressigned but ptr can be*/
    int a[]= {1,2,3};
    // a = x; // not possible to re-assign array -> error: assignment to expression with array type
    int *aptr = a;

}