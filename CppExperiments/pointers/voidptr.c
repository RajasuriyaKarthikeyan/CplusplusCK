#include <stdio.h>

int main(){
    int i = 10;

    void *pi = &i;

    printf("pi: %p, &i: %p\n", pi, &i); //pi: 0x7ffc6319297c, &i: 0x7ffc6319297c
    // printf("*pi=%d", *pi); // error: invalid use of void expression

    printf("%p, 0x%llx\n", NULL, (long long unsigned int)NULL);
    // (nil), 0x0

    int *p = NULL;
    // printf("*p=%d\n", *p);
    // Segmentation fault (core dumped) -> when tried to defernce , it value is zero but when during dereference
    return 0;
}