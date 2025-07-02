#include <stdio.h>

int main(){
    int b[5]= {11,22,33,44,55};
    int a[5]={1,2,3,4,5};
    int c[5]={11,222,3333,44444,55555};

    printf("sizeof a[]:%ld\n", sizeof(a));

    for(int i=0;i<5;i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}