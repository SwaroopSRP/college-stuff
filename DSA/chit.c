#include <stdio.h>
#include <stdlib.h>

void printArr(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertionSort(int arr[], int len) {
    for (int i = 1, j, x; i < len; i++) {
        x = arr[i];
        for (j = i - 1; j >= 0 && arr[j] > x; j--) {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = x;
    }
}

void bubbleSort(int arr[], int len) {
    for (int i = 0, j, temp, swapped; i < len - 1; i++) { // for no. of passes
        swapped = 0;
        for (j = 0; j < len - i - 1; j++) { // actual adjacent comparison
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

void selectionSort(int arr[], int len) {
    for (int i = 0, j, min, temp; i < len - 1; i++) {
        for (j = i + 1, min = i; j < len; j++) { // finding min
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        if (min != i) { // swapping
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

int binSearch(int arr[], int len, int key) {
    int low = 0, high = len - 1, mid; // initials
    while (low <= high) { // prevent post-convergence
        mid = (low + high) / 2;
        if (key == arr[mid]) {
            return mid;
        } else if (key > arr[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

typedef struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
} Node;

Node * createNode(int data) {
    Node *new = (Node *) malloc(sizeof(Node));
    if (!new) {
        printf("Mem Alloc Error!\n");
        return NULL;
    }
    new->prev = NULL;
    new->next = NULL;
    new->data = data;
    return new;
}

void insertAtFront(Node **head, int value) {
    Node *new = createNode(value);
    if (*head == NULL) {
        *head = new;
        return;
    }
    new->next = *head;
    (*head)->prev =new;
    *head = new;
}

void insertAtEnd(Node **head, int value) {
    Node *new = createNode(value);
    if (*head == NULL) {
        *head = new;
        return;
    }
    Node *curr;
    for (curr = *head; curr->next != NULL; curr = curr->next);
    new->prev = curr;
    curr->next = new;
}

void insertAtPos(Node **head, int pos, int value) {
    if (pos == 0) {
        insertAtFront(head, value);
        return;
    }
    Node *curr = *head, *new = createNode(value);
    for (int i = 0; (i < pos - 1) && (curr != NULL); curr = curr->next, i++);
    if (curr == NULL) {
        printf("Index out of range!\n");
        return;
    }
    Node *upcom = curr->next;
    curr->next = new;
    new->prev = curr;
    new->next = upcom;
    if (upcom != NULL) {
        upcom->prev = new;
    }
}

void delAtFront(Node **head) {
    if (*head == NULL) {
        printf("List already empty!\n");
    }
    Node *temp = (*head);
    *head = (*head)->next;
    free(temp);
}

void delAtEnd(Node **head) {
    if (*head == NULL) {
        printf("List already empty!\n");
    }
    Node *temp = *head;
    if ((*head)->next == NULL) {
        *head = NULL;
        free(temp);
        return;
    }
    Node *curr;
    for (curr = *head; curr->next != NULL; curr = curr->next);
    curr->prev->next = NULL;
    free(curr);
}

void delAtPos(Node **head, int pos) {
    if (*head == NULL) {
        printf("List already empty!\n");
    }
    if (pos == 0) {
        delAtFront(head);
    }
    Node *curr = *head;
    for (int i = 0; (curr != NULL) && (i < pos); curr->next, i++);
    if (curr == NULL) {
        printf("Index out of range!\n");
        return;
    }
    if (curr->next != NULL) {
        curr->next->prev = curr->prev;
    }
    if (curr->prev != NULL) {
        curr->prev->next = curr->next;
    }
    free(curr);
}

int count(Node **head) {
    int ctr = 0;
    for (Node *curr = *head; curr != NULL; curr = curr->next, ctr++);
    return ctr;
}

void display(Node **head) {
    for (Node *curr = *head; curr != NULL; curr = curr->next) {
        printf("%d ", curr->data);
    }
    printf("\n");
}

int main() {
    // int arr[] = {5, 3, 8, 2, 1, 4, 6, 7};
    // int n = sizeof(arr) / sizeof(arr[0]);
    //
    // printf("Original array: ");
    // printArr(arr, n);
    //
    // printf("Sorted array (Insertion Sort): ");
    // selectionSort(arr, n);
    // printArr(arr, n);
    Node *n1 = createNode(10);
    Node **head = &n1;
    insertAtEnd(head, 20);
    insertAtEnd(head, 40);
    display(head);
    insertAtFront(head, 10);
    display(head);
    insertAtPos(head, 2, 30);
    printf("No. of elems: %d\n", count(head));
    display(head);
    delAtFront(head);
    display(head);
    delAtEnd(head);
    display(head);
    printf("No. of elems: %d\n", count(head));
    return 0;
}
