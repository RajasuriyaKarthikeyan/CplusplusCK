#include <iostream>
#include <csignal>

using namespace std;

void signalInterupt(int sigNo){
    cout << "Interupt Signal (" << sigNo <<") received." << endl;
    exit(sigNo); 
}

int main(){
    signal(SIGINT, signalInterupt);
    int count = 0;
    while(1){
        if(count == 5){
            raise(SIGINT);
        } else {
            cout << "Going to sleep...." << endl;
            sleep(1);
            count++;
        }
    }
    return 0;
}