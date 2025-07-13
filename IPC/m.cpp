#include <iostream>
#include <unistd.h>

using namespace std;

int main(){
    int pid = fork();

    if(pid == 0){
        cout << "Child process will over p1 program" << endl;
        execl("./p1", "./p1", nullptr);
        cout << "This part wont print because of overlayed above by p1" << endl;
    } else {
        sleep(3); // for run in sequence
        cout << "Parent process will overlay p2 program" << endl;
        execl("./p2","./p2",nullptr);
        cout << "This part wont print because of overlayed above by p2" << endl;
    }
    return 0;
}