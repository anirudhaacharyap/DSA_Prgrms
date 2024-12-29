#include <stdio.h>
#include <stdlib.h>

// Define the structure for the node of a circular singly linked list
struct node {
    int data;
    struct node *addr;
};

typedef struct node *NODE;

NODE insert_beg(NODE head, int item);
NODE insert_end(NODE head, int item);
void display(NODE head);
NODE reverse(NODE head);
void addzero(NODE head1, NODE head2);
NODE add(NODE head1, NODE head2);

int main() {
    char first[20], second[20];
    int i;
    NODE head1, head2;
    
    // Initialize header nodes for both lists
    head1 = (NODE)malloc(sizeof(struct node));
    head2 = (NODE)malloc(sizeof(struct node));
    
    // Make both lists circular
    head1->addr = head1;
    head2->addr = head2;
    
    // Get the first number as a string
    printf("\nEnter the first number\n");
    scanf("%s", first);

    // Convert the first string into digits and store in linked list head1
    for (i = 0; first[i] != '\0'; i++) {
        head1 = insert_end(head1, first[i] - '0');
    }
    printf("\nThe first number is\n");
    display(head1);

    // Get the second number as a string
    printf("\nEnter the second number\n");
    scanf("%s", second);

    // Convert the second string into digits and store in linked list head2
    for (i = 0; second[i] != '\0'; i++) {
        head2 = insert_end(head2, second[i] - '0');
    }
    printf("\nThe second number is\n");
    display(head2);

    // Adjust the lists so they have equal lengths by adding leading zeros to the shorter list
    addzero(head1, head2);

    printf("\nThe first number after addzero function is\n");
    display(head1);
    printf("\nThe second number after addzero function is\n");
    display(head2);

    // Perform the addition of both numbers
    add(head1, head2);

    return 0;
}

// Function to add leading zeros to the shorter list
void addzero(NODE head1, NODE head2) {
    int count1 = 1, count2 = 1, i;
    NODE t1, t2;
    
    t1 = head1->addr;
    while (t1 != head1) {
        count1++;
        t1 = t1->addr;
    }
    
    t2 = head2->addr;
    while (t2 != head2) {
        count2++;
        t2 = t2->addr;
    }

    // Add zeros to the shorter list
    if (count1 > count2) {
        for (i = 1; i <= count1 - count2; i++) {
            head2 = insert_beg(head2, 0);
        }
    } else {
        for (i = 1; i <= count2 - count1; i++) {
            head1 = insert_beg(head1, 0);
        }
    }
}

// Function to reverse the linked list
NODE reverse(NODE head) {
    NODE cur, prev, next;
    cur = head->addr;
    prev = head;
    
    // Reverse the list
    while (cur != head) {
        next = cur->addr;
        cur->addr = prev;
        prev = cur;
        cur = next;
    }
    head->addr = prev;
    return head;
}

// Function to add two numbers represented by circular singly linked lists
NODE add(NODE head1, NODE head2) {
    NODE head, t1, t2;
    int sum = 0, carry = 0, x;

    // Initialize result list
    head = (NODE)malloc(sizeof(struct node));
    head->addr = head; // Circular list

    // Reverse both lists to start addition from the least significant digit
    head1 = reverse(head1);
    head2 = reverse(head2);

    t1 = head1->addr;
    t2 = head2->addr;

    // Perform addition
    while (t1 != head1 && t2 != head2) {
        x = t1->data + t2->data + carry;
        sum = x % 10;
        carry = x / 10;
        head = insert_beg(head, sum);
        t1 = t1->addr;
        t2 = t2->addr;
    }

    // If there is a carry left, add it to the result
    if (carry > 0) {
        head = insert_beg(head, carry);
    }

    printf("\nThe final added number is: ");
    display(head);
    return head;
}

// Function to insert an item at the beginning of the list
NODE insert_beg(NODE head, int item) {
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    temp->data = item;

    if (head->addr == head) {
        temp->addr = head;
        head->addr = temp;
        return head;
    }
    
    temp->addr = head->addr;
    head->addr = temp;
    return head;
}

// Function to insert an item at the end of the list
NODE insert_end(NODE head, int item) {
    NODE temp, cur;
    temp = (NODE)malloc(sizeof(struct node));
    temp->data = item;

    if (head->addr == head) {
        temp->addr = head;
        head->addr = temp;
        return head;
    }

    cur = head->addr;
    while (cur->addr != head) {
        cur = cur->addr;
    }
    cur->addr = temp;
    temp->addr = head;
    return head;
}

// Function to display the elements of the list
void display(NODE head) {
    NODE temp;
    if (head->addr == head) {
        printf("Empty list\n");
        return;
    }
    temp = head->addr;
    while (temp != head) {
        printf("%d", temp->data);
        temp = temp->addr;
    }
    printf("\n");
}
