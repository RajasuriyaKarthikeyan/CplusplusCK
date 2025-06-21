#include <stdio.h>

void main(){
    int i = 10;

    printf("i: %d, &i: %p, *&i:%d, *&*&i:%d, *&*&*&i:%d\n", i, &i, *&i, *&*&i, *&*&*&i);
        // i: 10, &i: 0x7fff4fb4d714, *&i:10, *&*&i:10, *&*&*&i:10
    
    *&*&*&i = 20;
    printf("i: %d, &i: %p, *&i:%d, *&*&i:%d, *&*&*&i:%d\n", i, &i, *&i, *&*&i, *&*&*&i);
    // i: 20, &i: 0x7fff4fb4d714, *&i:20, *&*&i:20, *&*&*&i:20

}