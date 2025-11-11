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

    // Add head position
    req[n] = head;
    n++;

    // Sort all requests
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (req[i] > req[j]) {
                temp = req[i];
                req[i] = req[j];
                req[j] = temp;
            }

    // Find index of current head
    int index;
    for (i = 0; i < n; i++)
        if (req[i] == head)
            index = i;

    printf("\nDisk movement order:\n");

    // Move from head towards higher tracks first
    for (i = index; i < n; i++)
        printf("%d ", req[i]);

    // Then jump back to lowest request and continue
    for (i = 0; i < index; i++)
        printf("%d ", req[i]);

    // Calculate total head movement
    total = (req[n - 1] - head) + (req[n - 1] - req[0]);

    printf("\n\nTotal Head Movement = %d\n", total);
    return 0;
}
