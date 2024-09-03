#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
} Node;

Node * createNode(int data) {
    Node *new = (Node *) malloc(sizeof(Node));
    if (!new) {
        printf("Memory allocation error!\n");
    }
    new->prev = NULL;
    new->data = data;
    new->next = NULL;
    return new;
}

void insertAtFront(Node **head, int data) {
    Node *new = createNode(data);
    if (*head == NULL) {
        *head = new;
        return;
    }
    new->next = *head;
    (*head)->prev = new;
    *head = new;
}

void insertAtEnd(Node **head, int data) {
    Node *new = createNode(data);
    if (*head == NULL) {
        *head = new;
        return;
    }
    Node *curr;
    for (curr = *head; curr->next != NULL; curr = curr-> next);
    curr->next = new;
    new->prev = curr;
}

void insertAtPos(Node **head, int pos, int data) {
    if (pos == 0) {
        insertAtFront(head, data);
        return;
    }
    Node *curr = *head, *new = createNode(data);
    for (int i = 0; (curr != NULL) && (i < pos - 1); curr = curr->next, i++);
    if (curr == NULL) {
        printf("Position index out of range!\n");
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
        printf("List is already empty!\n");
        return;
    }
    Node *temp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);
}

void delAtEnd(Node **head) {
    if (*head == NULL) {
        printf("List is already empty!\n");
        return;
    }
    Node *temp = *head;
    if ((*head)->next == NULL) {
        *head = NULL;
        free(temp);
        return;
    }
    Node *curr;
    for (curr = *head; curr->next != NULL; curr = curr-> next);
    curr->prev->next = NULL;
    free(curr);
}

void delAtPos(Node **head, int pos) {
    if (*head == NULL) {
        printf("List is already empty!\n");
        return;
    }
    if (pos == 0) {
        delAtFront(head);
    }
    Node *curr = *head;
    for (int i = 0; (curr != NULL) && (i < pos); curr = curr->next, i++);
    if (curr == NULL) {
        printf("Position index out of range!\n");
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
    for (Node *curr = *head; curr != NULL; curr = curr-> next, ctr++);
    return ctr;
}

void displayFwd(Node **head) {
    for (Node *curr = *head; curr != NULL; curr = curr-> next) {
        printf("%d ", curr->data);
    }
    printf("<END>\n");
}

void displayRev(Node **head) {
    Node *curr;
    for (curr = *head; curr->next != NULL; curr = curr-> next);
    for (; curr != NULL; curr = curr->prev) {
        printf("%d ", curr->data);
    }
    printf("<END>\n");
}

int main() {
    Node *head = NULL;
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 40);
    displayFwd(&head);
    insertAtFront(&head, 10);
    displayFwd(&head);
    insertAtPos(&head, 2, 30);
    printf("No. of elems: %d\n", count(&head));
    displayFwd(&head);
    delAtFront(&head);
    displayFwd(&head);
    delAtEnd(&head);
    displayFwd(&head);
    printf("No. of elems: %d\n", count(&head));
    return 0;
}
