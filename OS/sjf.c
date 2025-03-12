#include <stdio.h>

int main() {
    int n, burst_time[100], waiting_time[100], completion_time[100], total_wt = 0, total_ct = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input burst times
    for (int i = 0; i < n; i++) {
        printf("Enter burst time for Process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
    }

    // Sorting burst times (SJF - Non-preemptive)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (burst_time[j] < burst_time[i]) {
                int temp = burst_time[i];
                burst_time[i] = burst_time[j];
                burst_time[j] = temp;
            }
        }
    }

    // Calculate waiting times and completion times
    waiting_time[0] = 0;
    completion_time[0] = burst_time[0];

    for (int i = 1; i < n; i++) {
        waiting_time[i] = waiting_time[i - 1] + burst_time[i - 1];
        completion_time[i] = waiting_time[i] + burst_time[i];
    }

    // Calculate total waiting time and total completion time
    for (int i = 0; i < n; i++) {
        total_wt += waiting_time[i];
        total_ct += completion_time[i];
    }

    // Calculate averages
    float avg_wt = (float)total_wt / n;
    float avg_ct = (float)total_ct / n;

    // Display results
    printf("\nAverage Waiting Time: %.2f", avg_wt);
    printf("\nAverage Completion Time: %.2f\n", avg_ct);

    return 0;
}
