#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* newNode(int data);
void insertAtBegin(Node **head_inst, int data);
void insertAtEnd(Node **head_inst, int data);
void insertAtPos(Node **head_inst, int index, int data);
void delAtBegin(Node **head_inst);
void delAtEnd(Node **head_inst);
void delAtPos(Node **head_inst, int index);
int traverse(Node **head_inst, int index);
int count(Node **head_inst);
void display(Node **head_inst);

int main() {
    Node *head = NULL;
    int choice, data, index;

    do {
        printf("\nSingly Linked List Operations Menu:\n");
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
                insertAtBegin(&head, data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("Enter position to insert: ");
                scanf("%d", &index);
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtPos(&head, index, data);
                break;
            case 4:
                delAtBegin(&head);
                break;
            case 5:
                delAtEnd(&head);
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &index);
                delAtPos(&head, index);
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

void insertAtBegin(Node **head_inst, int data) {
    Node *new = newNode(data);
    if (*head_inst != NULL) {
        new->next = *head_inst;
    }
    *head_inst = new;
}

void insertAtEnd(Node **head_inst, int data) {
    Node *new = newNode(data);
    if (*head_inst == NULL) {
        *head_inst = new;
    } else {
        Node *curr = *head_inst;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = new;
    }
}

void insertAtPos(Node **head_inst, int index, int data) {
    if (index == 0) {
        insertAtBegin(head_inst, data);
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
        new->next = curr->next;
        curr->next = new;
    }
}

void delAtBegin(Node **head_inst) {
    if (*head_inst == NULL) {
        printf("The list is empty!\n");
        return;
    }
    Node *temp = *head_inst;
    *head_inst = (*head_inst)->next;
    free(temp);
}

void delAtEnd(Node **head_inst) {
    if (*head_inst == NULL) {
        printf("The list is empty!\n");
        return;
    }
    if ((*head_inst)->next == NULL) {
        delAtBegin(head_inst);
        return;
    }
    Node *curr = *head_inst;
    while (curr->next->next != NULL) {
        curr = curr->next;
    }
    Node *temp = curr->next;
    curr->next = NULL;
    free(temp);
}

void delAtPos(Node **head_inst, int index) {
    if (*head_inst == NULL) {
        printf("The list is empty!\n");
        return;
    }
    if (index == 0) {
        delAtBegin(head_inst);
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
    Node *temp = curr-> next;
    curr->next = curr->next->next;
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
