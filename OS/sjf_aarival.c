#include <stdio.h>

int main() {
    int n, arrival_time[100], burst_time[100], waiting_time[100] = {0}, completion_time[100] = {0}, remaining[100];
    int completed[100] = {0}, total_wt = 0, total_ct = 0, time = 0, count = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
  
    for (int i = 0; i < n; i++) {
        printf("Enter Arrival Time and Burst Time for Process %d: ", i + 1);
        scanf("%d %d", &arrival_time[i], &burst_time[i]);
        remaining[i] = burst_time[i];
    }

    while (count < n) {
        int shortest = -1, min_bt = 1e9;

        for (int i = 0; i < n; i++) {
            if (arrival_time[i] <= time && !completed[i] && burst_time[i] < min_bt) {
                min_bt = burst_time[i];
                shortest = i;
            }
        }

        if (shortest == -1) {
            time++;
            continue;
        }

        waiting_time[shortest] = time - arrival_time[shortest];
        completion_time[shortest] = time + burst_time[shortest];
        
        total_wt += waiting_time[shortest];
        total_ct += completion_time[shortest];

        time += burst_time[shortest];
        completed[shortest] = 1;
        count++;
    }

    printf("\nAverage Waiting Time: %.2f", (float)total_wt / n);
    printf("\nAverage Completion Time: %.2f\n", (float)total_ct / n);

    return 0;
}
