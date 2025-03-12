#include <stdio.h>

int main() {
    int n, burst_time[100], waiting_time[100] = {0}, completion_time[100] = {0}, remaining_time[100], time_quantum;
    float total_wt = 0, total_ct = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter burst time for Process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
        remaining_time[i] = burst_time[i];
    }

    printf("Enter time quantum: ");
    scanf("%d", &time_quantum);

    int time = 0, remaining = n;

    while (remaining > 0) {
        for (int i = 0; i < n; i++) {
            if (remaining_time[i] > 0) {
                if (remaining_time[i] > time_quantum) {
                    time += time_quantum;
                    remaining_time[i] -= time_quantum;
                } else {
                    time += remaining_time[i];
                    waiting_time[i] = time - burst_time[i];
                    remaining_time[i] = 0;
                    completion_time[i] = time;
                    remaining--;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        total_wt += waiting_time[i];
        total_ct += completion_time[i];
    }

    printf("\nAverage Waiting Time: %.2f", total_wt / n);
    printf("\nAverage Completion Time: %.2f\n", total_ct / n);

    return 0;
}
