#include <stdio.h>

void insertion_sort(int arr[], int len) {
    int i, j, key;
    for (i = 1; i < len; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = key;
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

    insertion_sort(arr, len);

    printf("Sorted array: \n");
    print_arr(arr, len);

    return 0;
}
