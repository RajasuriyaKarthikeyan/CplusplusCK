#include <stdio.h>
#include <unistd.h>

int main(){
    int pipefds1[2] = {-1,-1}; // parent write , child read
    int pipefds2[2] = {-1,-1}; // parent read , child write 
    int pid, returnStatus;
    char writeMessagefromParent[30] = "Get in there Lewis";
    char writeMessagefromChild[30] = "Simply lovely";
    char readMessage[30];

    returnStatus = pipe(pipefds1);
    if(returnStatus == -1){
        printf("failure in creating pipe1");
        return -1;
    }
    returnStatus = pipe(pipefds2);
    if(returnStatus == -1){
        printf("failure in creating pipe2");
        return -1;
    }

    pid = fork();
    if(pid == 0){
        close(pipefds1[1]);
        close(pipefds2[0]);
        read(pipefds1[0], readMessage, sizeof(readMessage));
        printf("Read from pipe 1 message from parent process : %s\n", readMessage);
        printf("Writing on pile 2 with child process : %s\n", writeMessagefromChild);
        write(pipefds2[1], writeMessagefromChild, sizeof(writeMessagefromChild));
    } else {
        close(pipefds1[0]);
        close(pipefds2[1]);
        printf("Writing into pipe 1 with parent process : %s\n", writeMessagefromParent);
        write(pipefds1[1], writeMessagefromParent, sizeof(writeMessagefromParent));
        read(pipefds2[0], readMessage, sizeof(readMessage));
        printf("Read from pipe 2 message from child process : %s\n", readMessage);
    }
    
}