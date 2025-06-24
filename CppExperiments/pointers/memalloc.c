#include <stdio.h>
#include <stdlib.h>

int main(){
    int *p = (int *)malloc(sizeof(int));

    printf("Before: %d\n", *p);
    *p = 4;
    printf("After: %d\n", *p);
    // Before: 0
    // After: 4
    free(p);
    return 0;
}