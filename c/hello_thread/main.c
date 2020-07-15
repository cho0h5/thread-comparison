#include <stdio.h>
#include <pthread.h>

void *thread(void *arg) {
    printf("Hello, thread!\n");
}

int main() {
    pthread_t t;

    pthread_create(&t, NULL, thread, NULL);

    pthread_join(t, NULL);

    return 0;
}
