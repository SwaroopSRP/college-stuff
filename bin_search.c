#include <stdio.h>

int bin_search(int arr[], int len, int key) {
  int low = 0, high = len - 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (arr[mid] == key) {
      return mid;
    }
    if (arr[mid] < key) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return -1;
}

int main(void) {
  int len;
  printf("Enter elements (in ascending order):\n");
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
  int idx = bin_search(arr, len, key);
  if (idx != -1) {
    printf("%d exists at index: %d\n", key, idx);
  } else {
    printf("%d does not exist in the array\n", key);
  }

  return 0;
}