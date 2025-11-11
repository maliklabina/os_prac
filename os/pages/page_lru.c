#include <stdio.h>

int main() {
    int pages[30], frame[10], time[10];
    int n, f, i, j, k, pos, page_fault = 0, count = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter page numbers: ");
    for (i = 0; i < n; i++)
        scanf("%d", &pages[i]);
    printf("Enter number of frames: ");
    scanf("%d", &f);

    for (i = 0; i < f; i++) {
        frame[i] = -1;
        time[i] = 0;
    }

    printf("\nPage\tFrames\n");

    for (i = 0; i < n; i++) {
        int found = 0;

        // Check if page already exists
        for (j = 0; j < f; j++) {
            if (frame[j] == pages[i]) {
                found = 1;
                time[j] = ++count;
                break;
            }
        }

        // If not found → page fault
        if (!found) {
            int least = 0;
            for (k = 1; k < f; k++)
                if (time[k] < time[least])
                    least = k;

            frame[least] = pages[i];
            time[least] = ++count;
            page_fault++;
        }

        // Display frames
        printf("%d\t", pages[i]);
        for (j = 0; j < f; j++)
            if (frame[j] != -1) printf("%d ", frame[j]);
            else printf("- ");
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", page_fault);
    return 0;
}
