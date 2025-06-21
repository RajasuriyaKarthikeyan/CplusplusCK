#include <iostream>
#include <cstdlib>
#include <pthread.h>

#define THREADCOUNT 6

using namespace std;

//Multithreading concept

void *PrintHello(void *tId){
    long tid;
    tid = (long)tId;
    cout << "Hello World! Thread ID : " << tid << endl;
    pthread_exit(NULL);
}

struct ThreadData
{
    int thread_id;
    char *msg;
    /* data */
};


void *PrintDetails(void *threadarg){
    struct ThreadData *myData;
    myData = (struct ThreadData *)threadarg;
    cout << "Thread ID : " << myData->thread_id << endl;
    cout << "Message : " << myData->msg << endl;
    pthread_exit(NULL);
}

int main(){
    pthread_t threads[THREADCOUNT];
    struct ThreadData td[THREADCOUNT];
    int rc, i;
    for(i=0;i<THREADCOUNT;i++){
        cout << "Main() : Creating thread " << i << endl;
        td[i].thread_id = i;
        td[i].msg = "This is message";
        rc = pthread_create(&threads[i], NULL, PrintDetails, (void *)&td[i]);

        if(rc){
            cout << "Error: unable to create thread" << rc << endl;
            break;
        }
    }
    pthread_exit(NULL);
}