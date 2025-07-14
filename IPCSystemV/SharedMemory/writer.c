#include <stdio.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <string.h>

#define SHM_KEY 0x1234  // Shared memory key
#define SHM_SIZE 1024   // Size of shared memory

int main(){
    int shmid = shmget(SHM_KEY, SHM_SIZE, 0666 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget");
        return 1;
    }

    char *data = (char*)shmat(shmid, NULL, 0);
    if(data == (char*)(-1)){
        perror("shmat");
        return 1;
    }

    const char *msg = "Hello from system v writer\n";
    strncpy(data, msg, SHM_SIZE);
    printf("Writer: wrote message.\n");

    shmdt(data);
}