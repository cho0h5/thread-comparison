#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define THREAD_NUMBER 10000
#define REPEAT_COUNT 100

sem_t sem;

void *thread(void *arg) {
    // Increase count
    for(int i = 0; i < REPEAT_COUNT; i++) {
        sem_wait(&sem);
        (*(int *)arg)++;
        sem_post(&sem);
    }
}

int main() {
    int count = 0;

    pthread_t t[THREAD_NUMBER];

    // Initialize semaphore
    sem_init(&sem, 0, 1);

    // Create threads
    for(int i = 0; i < THREAD_NUMBER; i++)
        pthread_create(&t[i], NULL, thread, &count);

    // Join threads
    for(int i = 0; i < THREAD_NUMBER; i++)
        pthread_join(t[i], NULL);

    //Destroy semaphore
    sem_destroy(&sem);

    // Desired count
    printf("Desired count: %d\n", THREAD_NUMBER * REPEAT_COUNT);
    // Actual count
    printf("Actual count: %d\n", count);

    return 0;
}
