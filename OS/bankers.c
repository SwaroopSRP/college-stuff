#include <stdio.h>

int main() {
    int np, nr, alloc[10][10], max[10][10], avail[10], need[10][10];
    int finish[10] = {0}, work[10], safeseq[10], count = 0;

    printf("Enter the number of Processes and Resources: ");
    scanf("%d %d", &np, &nr);

    // Input Allocation, Maximum Requirement, and Available Resources
    printf("Enter Allocation Matrix:\n");
    for (int i = 0; i < np; i++)
        for (int j = 0; j < nr; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter Maximum Resource Matrix:\n");
    for (int i = 0; i < np; i++)
        for (int j = 0; j < nr; j++)
            scanf("%d", &max[i][j]);

    printf("Enter Available Resources: ");
    for (int i = 0; i < nr; i++)
        scanf("%d", &avail[i]);

    // Compute Need Matrix
    printf("\nNeed Matrix:\n");
    for (int i = 0; i < np; i++) {
        for (int j = 0; j < nr; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }

    // Copy available resources to work array
    for (int i = 0; i < nr; i++)
        work[i] = avail[i];

    // Find Safe Sequence using Banker's Algorithm
    while (count < np) {
        int found = 0;
        for (int i = 0; i < np; i++) {
            if (!finish[i]) {
                int j;
                for (j = 0; j < nr; j++)
                    if (need[i][j] > work[j])
                        break;

                if (j == nr) { // If all needs can be satisfied
                    for (j = 0; j < nr; j++)
                        work[j] += alloc[i][j];

                    safeseq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if (!found) {
            printf("\nNo safe sequence exists! System is in an unsafe state.\n");
            return 1;
        }
    }

    // Display Safe Sequence
    printf("\nSafe Sequence: ");
    for (int i = 0; i < np; i++)
        printf("P%d ", safeseq[i]);
    printf("\n");

    return 0;
}
