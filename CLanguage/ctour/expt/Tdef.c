#include <stdio.h>

typedef unsigned long rajasck;

void main(){
    rajasck a  = 10;
    printf("%d\n", a);
    int size = sizeof(a);
    printf("%d\n",size);
}