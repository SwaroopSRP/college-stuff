#include <stdio.h>
#include <stdlib.h> 

struct Node {
    int data;
    struct Node *next;
};

void insert_at_begg(struct Node** head, int data) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

void insert_at_end(struct Node** head, int data) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last = *head;
    new_node->data = data;
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

void insert_at(struct Node** head, int data, int pos) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = *head;
    new_node->data = data;
    new_node->next = NULL;
    if (pos == 0) {
        new_node->next = *head;
        *head = new_node;
        return;
    }
    for (int i = 0; i < pos - 1; i++) {
        if (temp->next == NULL) {
            printf("Position out of bounds\n");
            return;
        }
        temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

void delete_at_begg(struct Node** head) {
    struct Node *temp = *head;
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    *head = temp->next;
    free(temp);
}

void delete_at_end(struct Node** head) {
    struct Node *temp = *head;
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (temp->next == NULL) {
        *head = NULL;
        free(temp);
        return;
    }
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void delete_at(struct Node** head, int pos) {
    struct Node *temp = *head;
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (pos == 0) {
        *head = temp->next;
        free(temp);
        return;
    }
    for (int i = 0; i < pos - 1; i++) {
        if (temp->next == NULL) {
            printf("Position out of bounds\n");
            return;
        }
        temp = temp->next;
    }
    struct Node *next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

void display(struct Node* head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void count(struct Node* head) {
    struct Node *temp = head;
    int count = 0;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("No. of elements: %d\n", count);
}

int main() {
    struct Node *head = NULL;
    insert_at_begg(&head, 10);
    display(head);
    insert_at_end(&head, 30);
    display(head);
    insert_at_end(&head, 40);
    display(head);
    insert_at(&head, 20, 1);
    display(head);
    insert_at(&head, 25, 2);
    display(head);
    count(head);
    delete_at_begg(&head);
    display(head);
    delete_at_end(&head);
    display(head);
    delete_at(&head, 1);
    display(head);

    return 0;
}
