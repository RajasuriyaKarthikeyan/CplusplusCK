#include <iostream>
#include <thread>

using namespace std;

void callings(){
    cout << "Thread called" << endl;
}

void callingsT2(){
    cout << "Thread II called" << endl;
}

int main(){
    thread t1(callings);
    thread t2(callingsT2);

    t1.join();
    t2.join();

    cout << "Thread execution completed"  << endl;
}