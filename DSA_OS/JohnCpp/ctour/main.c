#include <stdio.h>

void main(){
    int a = 10;
    int *b;
    b = &a;
    printf("b = %d",b);
    printf("*b = %d",*b);
    printf("a = %d",a);
    printf("&a = %d",&a);
    
}