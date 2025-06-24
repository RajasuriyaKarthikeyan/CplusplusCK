#include <stdio.h>

void main(){
    int p = 10;
    int *p1 =&p;
    int **pp1 = &p1;
    int ***ppp1 = &pp1;

    printf("p=%p, p1=%p, pp1=%p, ppp1=%p\n", &p, p1, pp1, ppp1);
    //  p=0x7ffce1fd71cc, p1=0x7ffce1fd71cc, pp1=0x7ffce1fd71d0, ppp1=0x7ffce1fd71d8
    //   p address        p address          p1 address          pp1 address
    printf("p=%d, p1=%d, pp1=%d, ppp1=%d\n", p, *p1, **pp1, ***ppp1);
    //  p=10, p1=10, pp1=10, ppp1=10 --> value will be same
}