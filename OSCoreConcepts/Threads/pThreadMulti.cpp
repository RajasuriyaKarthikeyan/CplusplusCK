#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 10
#define INCREMENTS_PER_THREAD 100000

int shared_variable = 0;
pthread_mutex_t mutex;

void* increment(void* arg) {
    for (int i = 0; i < INCREMENTS_PER_THREAD; ++i) {
        pthread_mutex_lock(&mutex);
        shared_variable++;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];

    // Initialize the mutex
    if (pthread_mutex_init(&mutex, NULL) != 0) {
        printf("Mutex init failed\n");
        return 1;
    }

    // Create threads
    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_create(&threads[i], NULL, increment, NULL);
    }

    // Join threads
    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }

    // Destroy the mutex
    pthread_mutex_destroy(&mutex);

    // Print final value of shared variable
    printf("Final value of shared_variable: %d\n", shared_variable);

    return 0;
}
