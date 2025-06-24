#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    printf("PID of ex1.c = %d\n", getpid());
    char *args[] = {"Hello", "Guys", "Amigos", NULL};
    execv("./ex2", args); 
    //while calling 2nd prgm , the process id will be same as the content of ex2 will get replaced here in this line of system call
    //but controll has to return back here, or subsequent line wont get executed
    printf("back to ex1.c");
    return 0;
}