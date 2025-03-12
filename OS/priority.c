#include <stdio.h>

int main() {
    int n, burst_time[100], priority[100], waiting_time[100], completion_time[100], total_wt = 0, total_ct = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter burst time and priority for Process %d: ", i + 1);
        scanf("%d %d", &burst_time[i], &priority[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (priority[j] < priority[i]) {
                int temp = priority[i];
                priority[i] = priority[j];
                priority[j] = temp;
                temp = burst_time[i];
                burst_time[i] = burst_time[j];
                burst_time[j] = temp;
            }
        }
    }


    waiting_time[0] = 0;
    completion_time[0] = burst_time[0];

    for (int i = 1; i < n; i++) {
        waiting_time[i] = waiting_time[i - 1] + burst_time[i - 1];
        completion_time[i] = waiting_time[i] + burst_time[i];
    }

    for (int i = 0; i < n; i++) {
        total_wt += waiting_time[i];
        total_ct += completion_time[i];
    }

    printf("\nAverage Waiting Time: %.2f", (float)total_wt / n);
    printf("\nAverage Completion Time: %.2f\n", (float)total_ct / n);

    return 0;
}
