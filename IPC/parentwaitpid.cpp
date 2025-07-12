#include <iostream>
#include <sys/wait.h>
#include <sys/types.h>

using namespace std;

int main(){
    int pid;
    int process[3];
    int status;
    int proc_count = 0, maxproc = 3;
    while(proc_count < maxproc){
        pid = fork();
        if(pid == 0){
            cout << "In child proces : process id is " << getpid() << endl;
            sleep(5);
            return 4;
        } else {
            process[proc_count]=pid;
            proc_count++;
            cout << "In parent process : created process no -> " << pid << " count -> " << proc_count << endl;
        }
    }

    /*
    < -1 − Wait for any child process whose process group ID is equal to the absolute value of pid.

    -1 − Wait for any child process, which equals to that of wait() system call.

    0 − Wait for any child process whose process group ID is equal to that of the calling process.

    >0 − Wait for any child process whose process ID is equal to the value of pid.
    */
    waitpid(process[0], &status, 0);
    if(WIFEXITED(status) != 0){
        cout << "Process exited normally : " << process[0] << endl;
        cout << "Child Process exit status : " << WEXITSTATUS(status) << endl;
    } else {
        cout << "Process not exited normally : " << process[0] << endl;
    }
    return 0;
}


