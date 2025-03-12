#include <stdio.h>

int main() {
    int n, arrival_time[100], burst_time[100], waiting_time[100], completion_time[100], start_time[100], total_wt = 0, total_ct = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter Arrival Time and Burst Time for Process %d: ", i + 1);
        scanf("%d %d", &arrival_time[i], &burst_time[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arrival_time[j] < arrival_time[i]) {
                int temp;

                temp = arrival_time[i];
                arrival_time[i] = arrival_time[j];
                arrival_time[j] = temp;

                temp = burst_time[i];
                burst_time[i] = burst_time[j];
                burst_time[j] = temp;
            }
        }
    }

    start_time[0] = arrival_time[0];
    completion_time[0] = start_time[0] + burst_time[0];
    waiting_time[0] = 0;

    for (int i = 1; i < n; i++) {
        start_time[i] = (completion_time[i - 1] < arrival_time[i]) ? arrival_time[i] : completion_time[i - 1];
        waiting_time[i] = start_time[i] - arrival_time[i];
        completion_time[i] = start_time[i] + burst_time[i];
    }

    for (int i = 0; i < n; i++) {
        total_wt += waiting_time[i];
        total_ct += completion_time[i];
    }

    printf("\nAverage Waiting Time: %.2f", (float)total_wt / n);
    printf("\nAverage Completion Time: %.2f\n", (float)total_ct / n);

    return 0;
}
