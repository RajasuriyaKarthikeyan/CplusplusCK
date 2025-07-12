#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
    int pid;
    int status;
    pid = fork();
    if(pid == 0){
        system("ps -ef");
        sleep(10);
        system("ps -ef");
        return 3;
    } else {
        sleep(3);
        wait(&status);
        cout << "parent process exit status from child is " << status << endl;
    }
//  exit status of 3 is stored in the higher order byte, so it is stored in hexadecimal format as 0X0300, which is 768 in decimal
    return 0;
}