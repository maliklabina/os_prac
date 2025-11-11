#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

int buffer = 0;              // shared resource
sem_t empty, full;           // counting semaphores
pthread_mutex_t mutex;       // for mutual exclusion

void* producer(void* arg) {
    while (1) {
        sem_wait(&empty);             // wait for empty space
        pthread_mutex_lock(&mutex);   // lock critical section

        buffer++;
        printf("Produced: %d\n", buffer);

        pthread_mutex_unlock(&mutex); // unlock
        sem_post(&full);              // signal item produced
        sleep(1);
    }
}

void* consumer(void* arg) {
    while (1) {
        sem_wait(&full);              // wait for item
        pthread_mutex_lock(&mutex);   // lock critical section

        printf("Consumed: %d\n", buffer);
        buffer--;

        pthread_mutex_unlock(&mutex); // unlock
        sem_post(&empty);             // signal space empty
        sleep(1);
    }
}

int main() {
    pthread_t p, c;

    sem_init(&empty, 0, 1);  // initially 1 empty slot
    sem_init(&full, 0, 0);   // no items initially
    pthread_mutex_init(&mutex, NULL);

    pthread_create(&p, NULL, producer, NULL);
    pthread_create(&c, NULL, consumer, NULL);

    pthread_join(p, NULL);
    pthread_join(c, NULL);

    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);

    return 0;
}
