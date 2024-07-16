#include <stdio.h>

void selection_sort(int arr[], int len) {
    int i, j, min_idx, tmp;
    for (i = 0; i < len - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < len; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        tmp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = tmp;
    }
}

void print_arr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int len;
    printf("Enter no. of elements:\n");
    scanf("%d", &len);
    int arr[len];
    for (int i = 0; i < len; i++) {
        printf("Enter element %d: \n", i);
        scanf("%d ", &arr[i]);
    }

    printf("Original array: \n");
    print_arr(arr, len);

    selection_sort(arr, len);

    printf("Sorted array: \n");
    print_arr(arr, len);

    return 0;
}
