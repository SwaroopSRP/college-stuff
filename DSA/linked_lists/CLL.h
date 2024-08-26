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
        printf("\nCircular Singly Linked List Operations Menu:\n");
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
    Node* new_node = (Node*) malloc(sizeof(Node));
    if (!new_node) {
        printf("Memory allocation error!\n");
        return NULL;
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void display(Node **head_inst) {
    if (*head_inst == NULL) {
        printf("The list is empty!\n");
        return;
    }
    Node *curr = *head_inst;
    do {
        printf("%d ", curr->data);
        curr = curr->next;
    } while(curr != *head_inst);
    printf("\n");
}

void insertAtBegin(Node **head_inst, int data) {
    Node *new_node = newNode(data);
    if (*head_inst == NULL) {
        *head_inst = new_node;
        new_node->next = new_node;
    } else {
        Node *curr = *head_inst;
        while(curr->next != *head_inst) {
            curr = curr->next;
        }
        new_node->next = *head_inst;
        curr->next = new_node;
        *head_inst = new_node;
    }
}

void insertAtEnd(Node **head_inst, int data) {
    Node *new_node = newNode(data);
    if (*head_inst == NULL) {
        *head_inst = new_node;
        new_node->next = new_node;
    } else {
        Node *curr = *head_inst;
        while(curr->next != *head_inst) {
            curr = curr->next;
        }
        curr->next = new_node;
        new_node->next = *head_inst;
    }
}

void insertAtPos(Node **head_inst, int index, int data) {
    if (index == 0) {
        insertAtBegin(head_inst, data);
    } else {
        Node *new_node = newNode(data);
        Node *curr = *head_inst;
        int i;
        for (i = 0; i < index - 1; i++) {
            curr = curr->next;
            if (curr == *head_inst) {
                printf("Index out of range!\n");
                return;
            }
        }
        new_node->next = curr->next;
        curr->next = new_node;
    }
}

void delAtBegin(Node **head_inst) {
    if (*head_inst == NULL) {
        printf("The list is empty!\n");
        return;
    }
    Node *temp = *head_inst;
    if ((*head_inst)->next == *head_inst) {
        *head_inst = NULL;
    } else {
        Node *curr = *head_inst;
        while(curr->next != *head_inst) {
            curr = curr->next;
        }
        *head_inst = (*head_inst)->next;
        curr->next = *head_inst;
    }
    free(temp);
}

void delAtEnd(Node **head_inst) {
    if (*head_inst == NULL) {
        printf("The list is empty!\n");
        return;
    }
    if ((*head_inst)->next == *head_inst) {
        *head_inst = NULL;
    } else {
        Node *curr = *head_inst;
        Node *prev;
        while(curr->next != *head_inst) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = *head_inst;
        free(curr);
    }
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
    int i;
    for (i = 0; i < index - 1; i++) {
        curr = curr->next;
        if (curr == *head_inst) {
            printf("Index out of range!\n");
            return;
        }
    }
    Node *temp = curr->next;
    if (temp == *head_inst) {
        delAtBegin(head_inst);
        return;
    }
    curr->next = temp->next;
    free(temp);
}

int traverse(Node **head_inst, int index) {
    if (*head_inst == NULL) {
        printf("The list is empty!\n");
        return -1;
    }
    Node* curr = *head_inst;
    int i;
    for (i = 0; i < index; i++) {
        curr = curr->next;
        if (curr == *head_inst) {
            printf("Index out of range\n");
            return -1;
        }
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
    do {
        ctr++;
        curr = curr->next;
    } while(curr != *head);
    return ctr;
}