#include <sys/resource.h>
#include <sys/time.h>
#include <iostream>
#include <unistd.h>

using namespace std;

int main(){
    struct rlimit res_limit;
    int resources[3] = {RLIMIT_NOFILE, RLIMIT_NPROC, RLIMIT_STACK};
    int i=0;
    cout << "Details of resource limits for NOFILE, NPROC, STACK are as follows : " << endl;
    while(i<3){
        int retVal = getrlimit(resources[i], &res_limit);
        if(retVal == -1){
            cerr << "getrlimit failure" << endl;
            break;
        }
        cout << "getrlimit Hard limit : " << res_limit.rlim_max << endl;
        cout << "getrlimit Soft limit : " << res_limit.rlim_cur << endl;
        i++;
    }
    int retval = prlimit(getppid(), RLIMIT_CPU, nullptr, &res_limit);
    if(retval == -1){
        cerr << "prlimit failure " << endl;
    } else {
        cout << "prlimit Hard limit : " << res_limit.rlim_max << endl;
        cout << "prlimit Soft limit : " << res_limit.rlim_cur << endl;
    }
    
}