#include <stdio.h>

void merge(int arr[], int l, int mid, int r);
void mergeSort(int arr[], int l, int r);
void printArr(int arr[], int n);

int main() {
    int len;
    printf("Enter no. of elements:\n");
    scanf("%d", &len);
    if (len <= 0) {
        printf("Invalid input.\n");
        return 1;
    }
    int arr[100];
    for (int i = 0; i < len; i++) {
        printf("Enter element %d: \n", i);
        scanf("%d", &arr[i]);
    }
    printf("Original array: \n");
    printArr(arr, len);

    mergeSort(arr, 0, len - 1);

    printf("Sorted array: \n");
    printArr(arr, len);

    return 0;
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int mid = l + (r - l) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

void merge(int arr[], int l, int mid, int r) {
    int i, j, k;
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }
    i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
