#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main() {
    key_t key = ftok("shmfile", 65);     // generate unique key
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);  // create shared memory
    char *str = (char*) shmat(shmid, NULL, 0);        // attach to memory

    printf("Enter message to write to shared memory: ");
    fgets(str, 100, stdin);              // write message

    printf("Data written in memory: %s\n", str);

    shmdt(str);                          // detach from shared memory
    return 0;
}
