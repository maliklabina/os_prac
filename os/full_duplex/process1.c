#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    char msg[100], result[200];
    int fd1, fd2;

    mkfifo("fifo1", 0666);
    mkfifo("fifo2", 0666);

    printf("Enter a sentence: ");
    fgets(msg, sizeof(msg), stdin);

    fd1 = open("fifo1", O_WRONLY);
    write(fd1, msg, strlen(msg) + 1);
    close(fd1);

    fd2 = open("fifo2", O_RDONLY);
    read(fd2, result, sizeof(result));
    close(fd2);

    printf("\nFrom Process 2:\n%s\n", result);
    return 0;
}
