#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    key_t key = ftok("shmfile", 65);     // same key as server
    int shmid = shmget(key, 1024, 0666); // get the same shared memory
    char *str = (char*) shmat(shmid, NULL, 0);        // attach

    printf("Data read from memory: %s\n", str);

    shmdt(str);                          // detach
    shmctl(shmid, IPC_RMID, NULL);       // destroy shared memory
    return 0;
}
