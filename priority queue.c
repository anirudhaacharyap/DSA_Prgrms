#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int rear = -1, front = -1;
int q[SIZE];

// Insert an element into the priority queue
void insert(int item) {
    if (rear == SIZE - 1) {
        printf("Queue is full\n");
        return;
    }
    
    int pos = rear;
    rear++;
    
    // Shift elements to maintain sorted order
    while (pos >= front && q[pos] >= item) {
        q[pos + 1] = q[pos];
        pos--;
    }
    
    q[pos + 1] = item; // Insert the new element
    
    // Update front if the queue was initially empty
    if (front == -1) {
        front = 0;
    }
    printf("Inserted %d into the queue\n", item);
}

// Delete the highest-priority element (front of the queue)
void delete() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    int del = q[front];
    printf("Deleted item is %d\n", del);

    if (front == rear) {
        // Reset pointers if queue becomes empty
        front = -1;
        rear = -1;
    } else {
        front++; // Move front pointer
    }
}

// Display the elements in the queue
void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements are:\n");
    for (int i = front; i <= rear; i++) {
        printf("%d\t", q[i]);
    }
    printf("\n");
}

int main() {
    int ch, item;

    while (1) { // Infinite loop for menu-driven program
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter item to insert: ");
                scanf("%d", &item);
                insert(item);
                break;

            case 2:
                delete();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
