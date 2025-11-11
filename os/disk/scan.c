#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, head, total = 0;
    int req[50], temp;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request sequence: ");
    for (i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    // Assume head moves towards higher end
    req[n] = head;
    req[n + 1] = 199;  // end of disk
    n += 2;

    // Sort requests
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (req[i] > req[j]) {
                temp = req[i];
                req[i] = req[j];
                req[j] = temp;
            }

    // Find position of head
    int index;
    for (i = 0; i < n; i++)
        if (req[i] == head)
            index = i;

    printf("\nDisk movement order:\n");

    // Move towards higher tracks first
    for (i = index; i < n; i++)
        printf("%d ", req[i]);
    for (i = index - 1; i >= 0; i--)
        printf("%d ", req[i]);

    // Calculate total head movement
    total = abs(head - 199) + abs(199 - req[0]);
    printf("\n\nTotal Head Movement = %d\n", total);

    return 0;
}
