#include <stdio.h>

void main(){

    int i = 0xAA;
    char c = 3;

    int x;
    char *cptr;

    printf("\n");
    printf("&c=%p \n", &c);
    printf("(garbage) x = %d \n", x);
    printf("(garbage) cptr = %p \n", cptr);
    printf("(garbage) cptr = 0x%llx \n\n", (long long unsigned int)cptr);

    /*1. Use of & before the variable in non-pointer assignment*/
    x = i &c;
    printf("x = i &c   --> %d \n\n", x);

    /*2. Use of & before the variable in non-pointer assignment*/
    cptr = &c;
    // x = i & cptr; Doesn't work Invalid operand - error: invalid operands to binary & (have ‘int’ and ‘char *’)
    // printf("x = i & &c --> %d \n\n", x); 
    // x = i & &cptr; Doesn't work Invalid operand - error: invalid operands to binary & (have ‘int’ and ‘char **’)
    // printf("x = i & &c --> %d \n\n", x);

    // i = 0xff;
    // x = i & (int)(&c); //converting the address to int so both operand is int and it will compile with or without bracket to (&c)
    // printf("x = i & (int)(&c)  --> %x \n\n", x);

    /* 3. Assign ptr to a valid address*/
    // cptr = &c;
    // printf("cptr = %p, &c = %p \n\n", cptr, &c);


    /* 4. The use of * with a pointer variable */
    // i = 2;
    // x = i * cptr;  Doesn't work - error: invalid operands to binary * (have ‘int’ and ‘char *’)
    // printf("x = i * cptr --> %d\n\n", x);

    /* 5. the use of * with a pointer variable*/
    cptr = &c;
    printf("cptr = %p, &c = %p \n\n", cptr, &c);
    i = 2;
    x = i ** cptr; // * is multiply and second * is go to the address cptr is pointing too basically it is equal to i * (*ptr)
    printf("x = i ** cptr --> %d \n\n", x);

    // /*6. Use of * with a pointer variable*/  --> same as above
    x = i * (*cptr);
    printf("x = i * (*cptr) --> %d \n\n", x);
    return;
}