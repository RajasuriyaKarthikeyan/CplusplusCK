#include <iostream>
#include <unistd.h>

using namespace std;

void ExitFunction(){
    cout << "Program is exiting with ExitFunction() using exit call" << endl;
}

int main(){
    atexit(ExitFunction); // called on exit
    cout << "Hello from exitCall.cpp file" << endl;
    exit(0);
}