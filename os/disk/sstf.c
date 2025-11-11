#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, i, j, min, diff, pos, total = 0;
    int visited[50] = {0}, req[50];

    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    printf("Enter the request sequence: ");
    for (i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("\nDisk movement order:\n");

    for (i = 0; i < n; i++) {
        min = 9999;
        pos = -1;

        // Find the nearest request not yet served
        for (j = 0; j < n; j++) {
            if (!visited[j]) {
                diff = abs(req[j] - head);
                if (diff < min) {
                    min = diff;
                    pos = j;
                }
            }
        }

        visited[pos] = 1;
        total += min;
        head = req[pos];

        printf("%d ", head);
    }

    printf("\n\nTotal Head Movement = %d\n", total);
    return 0;
}
