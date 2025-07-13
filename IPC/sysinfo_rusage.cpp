#include <iostream>
#include <sys/resource.h>
#include <sys/time.h>

using namespace std;

int main(){
    struct rusage res_usage;
    int retval;
    retval = getrusage(RUSAGE_SELF, &res_usage);
    if(retval == -1){
        cerr << "getrusage error" << endl;
        return 1;
    }
    cout << "Details of getrusage:"<< endl;
    cout << "User CPU time (seconds) is " << (int)res_usage.ru_utime.tv_sec<< endl;
    cout << "User CPU time (micro seconds) is " << (int)res_usage.ru_utime.tv_usec<< endl;
    cout << "Maximum size of resident set (kb) is " <<  res_usage.ru_maxrss<< endl;
    cout << "Soft page faults (I/O not required) is " << res_usage.ru_minflt<< endl;
    cout << "Hard page faults (I/O not required) is " << res_usage.ru_majflt<< endl;
    cout << "Block input operations via file system is " << res_usage.ru_inblock<< endl;
    cout << "Block output operations via file system is " << res_usage.ru_oublock<< endl;
    cout << "Voluntary context switches are " << res_usage.ru_nvcsw<< endl;
    cout << "Involuntary context switches are " << res_usage.ru_nivcsw<< endl;
}