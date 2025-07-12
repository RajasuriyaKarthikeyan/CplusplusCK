#include <sys/types.h>
#include <unistd.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
    int mypid, myppid;
    cout << "Printing Information of PID and PPID " << endl;
    mypid = getpid();
    myppid = getppid();
    cout << "Process ID : " << mypid << endl;
    cout << "Parent Process ID: " << myppid << endl;
    cout << "Verify in process table" << endl;
    system("ps -af");
    return 0;
}