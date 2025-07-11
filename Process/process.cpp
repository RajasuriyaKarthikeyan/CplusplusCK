#include <iostream>
#include <unistd.h>

using namespace std;

int main(){
    pid_t pid = fork();

    if(pid == 0){
        cout << "Child process running " << getpid() << endl;
    } else if(pid > 0) {
        cout << "Parent Process running " << getpid() << endl;
    } else {
        cout << "Fork Failed" << endl;
    }
}