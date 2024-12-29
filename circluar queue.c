#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int rear = -1, front = -1;
int q[SIZE];

// Insert an element into the circular queue
void insert(int item) {
    if ((rear + 1) % SIZE == front) {
        printf("Queue is full\n");
    } else if (front == -1 && rear == -1) { // First insertion
        front = 0;
        rear = 0;
        q[rear] = item;
    } else {
        rear = (rear + 1) % SIZE;
        q[rear] = item;
    }
}

// Delete an element from the circular queue
void dequeue() {
    if (front == -1 && rear == -1) { // Empty queue
        printf("Queue is empty\n");
    } else if (front == rear) { // Single element left
        printf("Deleted item is %d\n", q[front]);
        front = -1;
        rear = -1;
    } else { // Normal case
        printf("Deleted item is %d\n", q[front]);
        front = (front + 1) % SIZE;
    }
}

// Display elements in the circular queue
void display() {
    if (front == -1 && rear == -1) { // Empty queue
        printf("Queue is empty\n");
    } else {
        printf("Queue elements are:\n");
        int i = front;
        while (i != rear) {
            printf("%d\t", q[i]);
            i = (i + 1) % SIZE;
        }
        printf("%d\t", q[rear]);
        printf("\n");
    }
}

int main() {
    int choice, item;
    while (1) { // Infinite loop for menu-driven program
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter item to insert: ");
                scanf("%d", &item);
                insert(item);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
