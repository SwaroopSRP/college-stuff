#include <stdio.h>

int lin_search(int arr[], int len, int key) {
    for (int i = 0; i < len; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    int len;
    printf("Enter the number of elements:\n");
    scanf("%d", &len);
    int arr[len];
    for (int i = 0; i < len; i++) {
        printf("Enter element %d:\n", i);
        scanf("%d", &arr[i]);
    }
    printf("Enter the key to search:\n");
    int key;
    scanf("%d", &key);
    int idx = lin_search(arr, len, key);
    if (idx != -1) {
        printf("%d exists at index: %d\n", key, idx);
    } else {
        printf("%d does not exist in the array\n", key);
    }

    return 0;
}