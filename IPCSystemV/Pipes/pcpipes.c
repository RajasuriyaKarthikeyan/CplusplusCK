#include <stdio.h>
#include <unistd.h>

int main(){
    int pipefds[2] = {-1,-1}; //read,write
    char writeMessages[2][20] = {"hello", "Simply Lovely"};
    char readMessages[20];
    int returnStatus = pipe(pipefds);
    if(returnStatus==-1){
        printf("Failed in creating pipes");
        return -1;
    }
    int pid = fork();
    if(pid==0){
        read(pipefds[0], readMessages, sizeof(readMessages));
        printf("Reading msg 1 from child process : %s\n\n", readMessages);
        read(pipefds[0], readMessages, sizeof(readMessages));
        printf("Reading msg 2 from child process : %s\n\n", readMessages);
    } else {
        printf("Writing msg 1 from parent process : %s\n\n", writeMessages[0]);
        write(pipefds[1], writeMessages[0], sizeof(writeMessages[0]));
        printf("Writing msg 2 from parent process : %s\n\n", writeMessages[1]);
        write(pipefds[1], writeMessages[1], sizeof(writeMessages[1]));
    }
    return 0;
}