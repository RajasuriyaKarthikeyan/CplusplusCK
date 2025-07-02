#include <stdio.h> 

struct pixel
{
    int l;
    unsigned char r;
    unsigned char g;
    unsigned char b;
    int f;
    
} __attribute__((packed));

union mypixel
{
    /* data */
    int a;
    long f;
};

enum days_t{
    sunday,
    monday,
    tuesday,
};


void main(){
    struct pixel p;
    printf("%ld\n",sizeof(p));
    union mypixel up;
    printf("%ld\n", sizeof(up));
    enum days_t d = sunday;
    printf("day = %ld\n", d);
    
}
