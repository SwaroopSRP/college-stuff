#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node* newNode(int data);
void insertAtBegin(Node **head_inst, Node **tail_inst, int data);
void insertAtEnd(Node **head_inst, Node **tail_inst, int data);
void insertAtPos(Node **head_inst, Node **tail_inst, int index, int data);
void delAtBegin(Node **head_inst, Node **tail_inst);
void delAtEnd(Node **head_inst, Node **tail_inst);
void delAtPos(Node **head_inst, Node **tail_inst, int index);
int traverse(Node **head_inst, int index);
int count(Node **head_inst);
void display(Node **head_inst);

int main() {
    Node *head = NULL;
    Node *tail = NULL;
    int choice, data, index;

    do {
        printf("\nDoubly Linked List Operations Menu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at End\n");
        printf("6. Delete at Position\n");
        printf("7. Traverse at Position\n");
        printf("8. Count Nodes\n");
        printf("9. Display List\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insertAtBegin(&head, &tail, data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(&head, &tail, data);
                break;
            case 3:
                printf("Enter position to insert: ");
                scanf("%d", &index);
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtPos(&head, &tail, index, data);
                break;
            case 4:
                delAtBegin(&head, &tail);
                break;
            case 5:
                delAtEnd(&head, &tail);
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &index);
                delAtPos(&head, &tail, index);
                break;
            case 7:
                printf("Enter position to traverse: ");
                scanf("%d", &index);
                data = traverse(&head, index);
                if (data != -1) {
                    printf("Data at position %d is %d\n", index, data);
                }
                break;
            case 8:
                printf("Total nodes: %d\n", count(&head));
                break;
            case 9:
                display(&head);
                break;
            case 0:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

Node* newNode(int data) {
    Node* new = (Node*) malloc(sizeof(Node));
    if (!new) {
        printf("Memory allocation error!\n");
        return NULL;
    }
    new->data = data;
    new->next = NULL;
    new->prev = NULL;
    return new;
}

void display(Node **head_inst) {
    if (*head_inst == NULL) {
        printf("The list is empty!\n");
        return;
    }
    Node *curr = *head_inst;
    while(curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

void insertAtBegin(Node **head_inst, Node **tail_inst, int data) {
    Node *new = newNode(data);
    if (*head_inst == NULL) {
        *head_inst = new;
        *tail_inst = new;
    } else {
        new->next = *head_inst;
        (*head_inst)->prev = new;
        *head_inst = new;
    }
}

void insertAtEnd(Node **head_inst, Node **tail_inst, int data) {
    Node *new = newNode(data);
    if (*head_inst == NULL) {
        *head_inst = new;
        *tail_inst = new;
    } else {
        new->prev = *tail_inst;
        (*tail_inst)->next = new;
        *tail_inst = new;
    }
}

void insertAtPos(Node **head_inst, Node **tail_inst, int index, int data) {
    if (index == 0) {
        insertAtBegin(head_inst, tail_inst, data);
    } else {
        Node *new = newNode(data);
        Node *curr = *head_inst;
        for (int i = 0; i < index - 1; i++) {
            if (curr == NULL || curr->next == NULL) {
                printf("Index out of range!\n");
                return;
            }
            curr = curr->next;
        }
        if (curr->next == NULL) {
            insertAtEnd(head_inst, tail_inst, data);
            return;
        }
        new->next = curr->next;
        new->prev = curr;
        curr->next->prev = new;
        curr->next = new;
    }
}

void delAtBegin(Node **head_inst, Node **tail_inst) {
    if (*head_inst == NULL) {
        printf("The list is empty!\n");
        return;
    }
    Node *temp = *head_inst;
    if (*head_inst == *tail_inst) {
        *head_inst = NULL;
        *tail_inst = NULL;
    } else {
        *head_inst = (*head_inst)->next;
        (*head_inst)->prev = NULL;
    }
    free(temp);
}

void delAtEnd(Node **head_inst, Node **tail_inst) {
    if (*head_inst == NULL) {
        printf("The list is empty!\n");
        return;
    }
    Node *temp = *tail_inst;
    if (*head_inst == *tail_inst) {
        *head_inst = NULL;
        *tail_inst = NULL;
    } else {
        *tail_inst = (*tail_inst)->prev;
        (*tail_inst)->next = NULL;
    }
    free(temp);
}

void delAtPos(Node **head_inst, Node **tail_inst, int index) {
    if (*head_inst == NULL) {
        printf("The list is empty!\n");
        return;
    }
    if (index == 0) {
        delAtBegin(head_inst, tail_inst);
        return;
    }
    Node *curr = *head_inst;
    for (int i = 0; i < index - 1; i++) {
        if (curr == NULL || curr->next == NULL) {
            printf("Index out of range!\n");
            return;
        }
        curr = curr->next;
    }
    if (curr->next == NULL) {
        printf("Index out of range!\n");
        return;
    }
    Node *temp = curr->next;
    if (curr->next == *tail_inst) {
        delAtEnd(head_inst, tail_inst);
        return;
    }
    curr->next = curr->next->next;
    curr->next->prev = curr;
    free(temp);
}

int traverse(Node **head_inst, int index) {
    if (*head_inst == NULL) {
        printf("The list is empty!\n");
        return -1;
    }
    Node* curr = *head_inst;
    for (int i = 0; i < index; i++) {
        if (curr == NULL) {
            printf("Index out of range\n");
            return -1;
        }
        curr = curr->next;
    }
    if (curr != NULL) {
        return curr->data;
    }
    printf("Index out of range\n");
    return -1;
}

int count(Node **head) {
    if (*head == NULL) {
        return 0;
    }
    Node *curr = *head;
    int ctr = 0;
    while(curr != NULL) {
        ctr++;
        curr = curr->next;
    }
    return ctr;
}