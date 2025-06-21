#include <stdio.h>

void main(){
    int a = 0x45, b = 0x07;
    // int c = a & b;
    printf("a & b : %x\n", a & b);
    printf("a | b : %x\n", a | b);
    printf("a ^ b : %x\n", a ^ b);
    printf("~a : %x\n", ~a);
    printf("~b : %x\n", ~b);
    printf("Shift 1 << 2: %x\n", 1 << 2);
    printf("Shift 0xf0 << 2: %x\n", 0xf0 << 2);
    printf("Shift 1 >> 2: %x\n", 1 >> 2);
    printf("Shift 0xf0 >> 2: %x\n", 0xf0 >> 2);
    return;
}