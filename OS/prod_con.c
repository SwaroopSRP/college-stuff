#include <stdio.h>
#include <stdlib.h>

int mutex = 1, full = 0, empty = 3, item = 0;

void wait(int *s) { (*s)--; }
void signal(int *s) { (*s)++; }

void producer() {
    wait(&empty);
    wait(&mutex);
    printf("Producer produced item %d\n", ++item);
    signal(&mutex);
    signal(&full);
}

void consumer() {
    wait(&full);
    wait(&mutex);
    printf("Consumer consumed item %d\n", item--);
    signal(&mutex);
    signal(&empty);
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Producer\n2. Consumer\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1 && empty > 0) producer();
        else if (choice == 2 && full > 0) consumer();
        else if (choice == 3) exit(0);
        else printf("Operation not possible!\n");
    }
    return 0;
}
