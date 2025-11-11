#include <stdio.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[10], bt[10], rt[10];
    for (int i = 0; i < n; i++) {
        printf("Enter Arrival Time and Burst Time for P%d: ", i + 1);
        scanf("%d%d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    int complete = 0, t = 0, shortest;
    float total_wt = 0, total_tat = 0;

    while (complete != n) {
        shortest = -1;
        for (int i = 0; i < n; i++) {
            if (at[i] <= t && rt[i] > 0) {
                if (shortest == -1 || rt[i] < rt[shortest])
                    shortest = i;
            }
        }

        if (shortest == -1) { t++; continue; }

        rt[shortest]--;
        if (rt[shortest] == 0) {
            complete++;
            int finish = t + 1;
            int tat = finish - at[shortest];
            int wt = tat - bt[shortest];
            if (wt < 0) wt = 0;
            total_wt += wt;
            total_tat += tat;
            printf("P%d: WT=%d, TAT=%d\n", shortest + 1, wt, tat);
        }
        t++;
    }

    printf("\nAverage WT=%.2f, Average TAT=%.2f\n", total_wt / n, total_tat / n);
    return 0;
}
