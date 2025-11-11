#include <stdio.h>

int main() {
    int n, tq, time = 0, done = 0;
    int at[10], bt[10], rt[10];
    float avgwt = 0, avgtt = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Arrival Time and Burst Time:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d Arrival: ", i + 1);
        scanf("%d", &at[i]);
        printf("P%d Burst: ", i + 1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    printf("\nProcess\tTurnaround\tWaiting\n");
    while (done < n) {
        int found = 0;
        for (int i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] > 0) {
                found = 1;
                if (rt[i] > tq) {
                    rt[i] -= tq;
                    time += tq;
                } else {
                    time += rt[i];
                    printf("P%d\t%d\t\t%d\n", i + 1, time - at[i], time - at[i] - bt[i]);
                    avgtt += time - at[i];
                    avgwt += time - at[i] - bt[i];
                    rt[i] = 0;
                    done++;
                }
            }
        }
        if (!found) time++; // if no process is ready, move time forward
    }

    printf("\nAverage Waiting Time: %.2f", avgwt / n);
    printf("\nAverage Turnaround Time: %.2f\n", avgtt / n);
    return 0;
}
