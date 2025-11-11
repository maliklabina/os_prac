#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int counter = 0;               // shared resource
pthread_mutex_t lock;          // mutex lock

void* function(void* arg) {
    pthread_mutex_lock(&lock);     // enter critical section

    for (int i = 0; i < 5; i++) {
        counter++;
        printf("Thread %ld: counter = %d\n", (long)arg, counter);
        sleep(1);
    }

    pthread_mutex_unlock(&lock);   // exit critical section
    return NULL;
}

int main() {
    pthread_t t1, t2;

    pthread_mutex_init(&lock, NULL);     // initialize mutex

    pthread_create(&t1, NULL, function, (void*)1);
    pthread_create(&t2, NULL, function, (void*)2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&lock);        // destroy mutex
    return 0;
}
