#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    char msg[100], out[200];
    int fd1, fd2, i, chars = 0, words = 1, lines = 1;

    fd1 = open("fifo1", O_RDONLY);
    read(fd1, msg, sizeof(msg));
    close(fd1);

    for (i = 0; msg[i] != '\0'; i++) {
        if (msg[i] != ' ' && msg[i] != '\n') chars++;
        if (msg[i] == ' ') words++;
        if (msg[i] == '\n') lines++;
    }

    sprintf(out, "Chars: %d\nWords: %d\nLines: %d\n", chars, words, lines);

    fd2 = open("fifo2", O_WRONLY);
    write(fd2, out, strlen(out) + 1);
    close(fd2);

    return 0;
}
