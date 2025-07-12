#include <iostream>
#include <unistd.h>

using namespace std;

int main(){
    pid_t pid = fork();

    if(pid == 0){
        cout << "Child process running with id " << getpid() << " and parent " << getppid() << endl;
    } else if(pid > 0) {
        cout << "Parent Process running with id " << getpid() << " and parenr process " << getppid() << endl;
    } else {
        cout << "Fork Failed" << endl;
    }
}