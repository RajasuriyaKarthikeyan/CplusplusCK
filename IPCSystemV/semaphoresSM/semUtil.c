#include <sys/sem.h>

union semUtil
{
    int values;
};

void sem_set(int semId, int semNo, int val){
    union semUtil arg;
    arg.values = val;
    semctl(semId, semNo, SETVAL, arg);
}

void sem_wait(int semId, int semNo){
    struct sembuf sb = {semNo, -1, 0};
    semop(semId, &sb, 1);
}

void sem_signal(int semId, int semNo){
    struct sembuf sb = {semNo, 1, 0};
    semop(semId, &sb, 1);
}
