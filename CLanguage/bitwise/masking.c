#include <stdio.h>

int main(){

    int a = 0xadcdef23;   // 4bytes - 32 bits

    int mask = 0xff << 8;
    printf("a(hex) : 0x%x\n", a);
    // 
    printf("mask(<< 8 bits): 0x%x\n", mask); // oxef00
    printf("masked a: 0x%x\n", a & mask); // ef alone retain
    printf("masked a: 0x%x\n", a | mask); // 0xadcdff23 - expected 15-8 bit will set to 1 and rest of things will retain

    int nmask = ~mask;
    printf("nmask: 0x%x\n", nmask); // 0xffff00ff
    printf("masked a: 0x%x\n", a | nmask); // 0xffffefff
    printf("masked a: 0x%x\n", a & nmask); // 0xadcd0023

    int mmask = mask | (mask << 16);
    printf("mask | (mask << 16): 0x%x\n", mmask); // 0xff00ff00d
    printf("masked a: 0x%x\n", a & mmask); // 0xad00ef00
    printf("masked a: 0x%x\n", a | mmask); // 0xffcdff23

    return 0;
}