#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
} Node;

Node * createNode(int data) {
    Node *new = (Node *) malloc(sizeof(Node));
    new->prev = NULL;
    new->data = data;
    new->next = NULL;
    return new;
}

void insertAtEnd(Node **head, int data) {
    Node *curr;
    for (curr = *head; curr->next != NULL; curr = curr-> next);
    Node *new = createNode(data);
    curr->next = new;
    new->prev = curr;
}

void displayFwd(Node **head) {
    for (Node *curr = *head; curr != NULL; curr = curr-> next) {
        printf("%d ", curr->data);
    }
    printf("Null!\n");
}

void displayRev(Node **head) {
    Node *curr;
    for (curr = *head; curr->next != NULL; curr = curr-> next);
    for (; curr != NULL; curr = curr->prev) {
        printf("%d ", curr->data);
    }
    printf("Null!\n");
}

int main() {
    Node *head = createNode(0);
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    displayFwd(&head);
    insertAtEnd(&head, 40);
    displayRev(&head);
    return 0;
}
