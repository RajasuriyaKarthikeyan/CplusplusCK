#include <stdio.h>
#include <malloc.h>

void main(){
    char *p[10];

    printf("p: %p\n", p);

    for(int i=0;i<10;i++){
        p[i] = (char *)malloc(sizeof(char));
        *p[i] = 10 -i;
        printf("p[%d]: %p, *p[%d]: %d\n", i, p[i], i, *p[i]);
    }
    /*p: 0x7ffc7c4bb770
        p[0]: 0x615610e906b0, *p[0]: 10
        p[1]: 0x615610e906d0, *p[1]: 9
        p[2]: 0x615610e906f0, *p[2]: 8
        p[3]: 0x615610e90710, *p[3]: 7
        p[4]: 0x615610e90730, *p[4]: 6
        p[5]: 0x615610e90750, *p[5]: 5
        p[6]: 0x615610e90770, *p[6]: 4
        p[7]: 0x615610e90790, *p[7]: 3
        p[8]: 0x615610e907b0, *p[8]: 2
        p[9]: 0x615610e907d0, *p[9]: 1*/

    for(int i=0;i<10;i++){
        free(p[i]);
    }
}