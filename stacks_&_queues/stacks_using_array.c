#include <stdio.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    int arr[MAX];
    int top;
} Stack;

void init(Stack *Stk) {
    Stk->top = -1;
}

bool isEmpty(Stack *Stk) {
    return (Stk->top == -1);
}

bool isFull(Stack *Stk) {
    return (Stk->top == MAX - 1);
}

void push(Stack *Stk, int elem) {
    if (isFull(Stk)) {
        printf("Stack Overflow!\n");
        return;
    }
    Stk->arr[++(Stk->top)] = elem;
    printf("%d pushed onto the stack!\n", elem);
}

int pop(Stack *Stk) {
    if (isEmpty(Stk)) {
        printf("Stack Underflow!\n");
        return -1;
    }
    int popped = Stk->arr[Stk->top];
    Stk->top--;
    printf("%d popped from the stack!\n", popped);
    return popped;
}

int peek(Stack *Stk) {
    if (isEmpty(Stk)) {
        printf("Stack Underflow!\n");
        return (int) NULL;
    }
    int up = Stk->arr[Stk->top];
    printf("%d is on top of the stack!\n", up);
    return up;
}

void display(Stack *Stk) {
    if (isEmpty(Stk)) {
        printf("Stack is empty!\n");
        return;
    }
    for (int i = 0; i < MAX; i++) {
        printf("%d ", Stk->arr[i]);
    }
    printf("\n");
}

int main() {
    Stack s1;
    push(&s1, 10);
    push(&s1, 20);
    push(&s1, 30);
    push(&s1, 40);
    push(&s1, 50);
    display(&s1);
    pop(&s1);
    peek(&s1);
    
    return 0;
}
