#include <iostream>
#include <sys/wait.h>
#include <sys/types.h>

using namespace std;

int main(){
    int pid;
    int process[3];
    int status;
    int proc_count = 0, maxproc = 3;
    siginfo_t sinfo;
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
P_PID − Wait for any child process whose process ID is equal to that of id.

P_PGID − Wait for any child process, whose process group ID is equal to that of id.

P_ALL − Wait for any child process and id is ignored.

The options argument is to specify which state changes and this can be formed with bitwise OR operation with the below-mentioned flags −

WCONTINUED − Returns the status of any child that was stopped and has been continued.

WEXITED − Waits for the process to exit.

WNOHANG − Returns immediately.

WSTOPPED − Waits for the process of any child that has stopped, upon receipt of the signal and returns the status.
*/
    waitid(P_PID, process[0], &sinfo, WEXITED);
    if(status == -1){
        cerr << "waitid error" <<endl;
        return 1;
    }
    cout << "PID of child: " << sinfo.si_pid <<", real user id of child: " << sinfo.si_uid << endl; 
    return 0;
}


