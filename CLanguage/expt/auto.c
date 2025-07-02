#include <stdio.h>

extern int a;

extern void func();

void bar(){
    static char b = 3;
    b = b+1;
    printf("Bar : %d\n", b);
}

void main(){
    // {
    //     auto int a = 10;
    // }
    // auto int a = 10;
    printf("a=%d\n", a);
    a= a+1;

    printf("a=%d\n", a);
    func();
    printf("after func--> a=%d\n", a);

    printf("Bar calling ---> 0 \n");
    bar();
    printf("Bar calling ---> 1 \n");
    bar();
    printf("Bar calling ---> 2 \n");
    bar();
    


    // register int r = 100;

    // r=r+1;

    return;
}