#include <iostream>
#include <unistd.h>

using namespace std;

void ExitFunction(){
    cout << "Program is exiting with ExitFunction() using _exit call" << endl;
}

int main(){
    atexit(ExitFunction); // wont be called on _exit
    cout << "Hello from exitCall.cpp file" << endl;
    _exit(0);
}