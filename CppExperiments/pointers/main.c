#include <stdio.h>

void main(){
    printf("Hello World \n");
    char c = 'A';
    char *p1=&c;
    // char *   p2 =   &  c;   spaces doesn't matter
    

    printf("c=%c, &c=%p\n", c, &c);
    printf("*p1=%c, p1=%p\n", *p1, p1);
    printf("&p1=%p\n", &p1);
    return;
}