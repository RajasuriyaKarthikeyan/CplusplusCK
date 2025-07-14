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

    sem_set(semid, SEM_A, 1); // A starts
    sem_set(semid, SEM_B, 0); // B waits

    char *shm = (char*)shmat(shmid, NULL, 0);
    for(int i=0;i<5;i++){
        sem_wait(semid, SEM_A);

        sprintf(shm, "hello from A : %d", i+1);
        printf("A: written ->  %s\n", shm);

        sem_signal(semid, SEM_B);
        sem_wait(semid, SEM_A);

        printf("A: read from B -> %s\n",shm);
        sem_signal(semid, SEM_B);
    }
    shmdt(shm);
    shmctl(shmid, IPC_RMID, NULL);
    semctl(semid, 2, IPC_RMID);
    return 0;
    
}