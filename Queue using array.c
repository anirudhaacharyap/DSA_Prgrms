#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

struct queue {
    int front, rear;
    int data[SIZE];
};

// Initialize the queue
void initializeQueue(struct queue *q) {
    q->front = -1;
    q->rear = -1;
}

void insert(struct queue *q, int item) {
    if (q->rear == SIZE - 1) {
        printf("Queue is full\n");
    } else {
        q->rear++;
        q->data[q->rear] = item;
        if (q->front == -1)
            q->front = 0;
    }
}

void delet(struct queue *q) {
    if (q->front == -1) {
        printf("Queue is empty\n");
    } else {
        int del = q->data[q->front];
        printf("Deleted item is %d\n", del);
        if (q->front == q->rear) {
            q->front = -1;
            q->rear = -1;
        } else {
            q->front++;
        }
    }
}

void display(struct queue *q) {
    if (q->front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements are:\n");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d\t", q->data[i]);
        }
        printf("\n");
    }
}

int main() {
    struct queue q; // Declare a queue
    initializeQueue(&q); // Initialize the queue

    int ch, item;
    for (;;) { // Infinite loop
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter item: ");
                scanf("%d", &item);
                insert(&q, item);
                break;
            case 2:
                delet(&q);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
