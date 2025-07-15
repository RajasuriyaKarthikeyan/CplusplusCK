#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void interuptSignals(int signo){
    if(signo==SIGINT){
        printf("Received Interrupt Signal : %d\n", signo);
        exit(0);
    }
}

int main(){
    signal(SIGINT, interuptSignals);
    while(1){
        printf("Ctrl+C \n");
        sleep(1);
    }
    return 0;
}