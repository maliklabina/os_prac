#include <stdio.h>

int main() {
    int pages[30], frame[10], n, f, i, j, k, page_fault = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for (i = 0; i < f; i++)
        frame[i] = -1;  // initialize frames as empty

    j = 0; // points to the next frame to replace

    printf("\nPage\tFrames\n");
    for (i = 0; i < n; i++) {
        int found = 0;

        // Check if page is already present
        for (k = 0; k < f; k++) {
            if (frame[k] == pages[i]) {
                found = 1;
                break;
            }
        }

        // If page not found → page fault
        if (found == 0) {
            frame[j] = pages[i];
            j = (j + 1) % f;
            page_fault++;

            // Print current frame status
            printf("%d\t", pages[i]);
            for (k = 0; k < f; k++) {
                if (frame[k] != -1)
                    printf("%d ", frame[k]);
                else
                    printf("- ");
            }
            printf("\n");
        }
    }

    printf("\nTotal Page Faults = %d\n", page_fault);
    return 0;
}
