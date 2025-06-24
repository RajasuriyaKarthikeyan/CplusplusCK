#include <stdio.h>


struct mystruct
{
    int a;
    float f;
    long int l;
};

void main(){
    struct mystruct s1;
    s1.a = 10;
    s1.f = 1.0;
    s1.l = 100;
    
    printf("s1.a: %d, s1.f: %f, s1.l:%ld \n", s1.a, s1.f, s1.l);
    struct mystruct *ptr = &s1;

    ptr->a = ptr->a+1;
    ptr->f = ptr->f+1;
    ptr->l = ptr->l+1;

    printf("ptr->a: %d, ptr->f: %f, ptr->l:%ld \n", ptr->a, ptr->f, ptr->l);
}