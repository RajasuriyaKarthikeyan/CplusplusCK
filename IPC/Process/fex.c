#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    fork(); // create child process so, execution of same will happen twice 
    fork();
    fork();
    //2 power n times
    printf("Hello guys \n PID = %d\n", getpid());
    return 0;
}