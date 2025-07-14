#include <stdio.h>
#include <stdlib.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include "common.h"

void sem_set(int,int,int);
void sem_wait(int,int);
void sem_signal(int,int);

int main(){
    int shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    int semid = semget(SEM_KEY, 2, IPC_CREAT | 0666);

    char *msg = (char*)shmat(shmid, NULL, 0);
    
    for(int i=0;i<5;i++){
        sem_wait(semid, SEM_B);

        printf("B: read msg from A -> : %s\n", msg);

        sprintf(msg, "hello from B : %d", i+1);
        printf("B Written : %s\n", msg);

        sem_signal(semid, SEM_A);
    }
    shmdt(msg);

    return 0;
}