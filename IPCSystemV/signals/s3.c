#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handleSignals(int num){
    switch (num)
    {
    case SIGINT:
        printf("Ignoring the SIGINT");
        break;

    case SIGQUIT:
        printf("Pressed the ctrl+\\ -> Ignoring");
        break;
    
    default:
        break;
    }
}

int main(){
    void (*signalHandlerInterrupt)(int);
    void (*signalHandlerQuit)(int);
    void (*signalReturn)(int);
    signalHandlerInterrupt = signalHandlerQuit = handleSignals;
    signalReturn = signal(SIGINT, signalHandlerInterrupt);
    if(signalReturn == SIG_ERR){
        perror("Signal Error: ");
        return 1;
    }
    signalReturn = signal(SIGQUIT, signalHandlerQuit);
    if(signalReturn == SIG_ERR){
        perror("Signal Error: ");
        return 1;
    }

    while (1) {
      printf("\nTo terminate this program, perform the following: \n");
      printf("1. Open another terminal\n");
      printf("2. Issue command: kill %d or issue CTRL+C 2 times (second time it terminates)\n", getpid());
      sleep(10);
    }

    return 0;
}