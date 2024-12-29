#include <stdio.h>
#include <stdlib.h>

// Define the structure for a circular singly linked list node
typedef struct node {
    int data;
    struct node *link;
} Node;

Node *tail = NULL;

// Function to get the length of the circular singly linked list
int get_length() {
    if (tail == NULL) {
        return 0;
    }

    int count = 0;
    Node *p = tail->link;
    do {
        count++;
        p = p->link;
    } while (p != tail->link);

    return count;
}

// Concatenate two circular singly linked lists
void concatenate(Node *tail1, Node *tail2) {
    if (tail1 == NULL) {
        tail1 = tail2;
        return;
    }
    if (tail2 == NULL) {
        return;
    }

    Node *p = tail1->link;
    tail1->link = tail2->link;
    tail2->link = p;
    tail1 = tail2;
}

// Insert at the beginning
void insert_beg() {
    Node *temp = (Node *)malloc(sizeof(Node));
    printf("Enter data: ");
    scanf("%d", &temp->data);

    if (tail == NULL) {
        tail = temp;
        tail->link = temp;
    } else {
        temp->link = tail->link;
        tail->link = temp;
    }
}

// Insert at the end
void insert_end() {
    Node *temp = (Node *)malloc(sizeof(Node));
    printf("Enter data: ");
    scanf("%d", &temp->data);

    if (tail == NULL) {
        tail = temp;
        tail->link = temp;
    } else {
        temp->link = tail->link;
        tail->link = temp;
        tail = temp;
    }
}

// Insert at a specified position
void insert_at_pos() {
    int pos, i = 1, length;
    printf("Enter position: ");
    scanf("%d", &pos);

    length = get_length();
    if (pos < 1 || pos > length + 1) {
        printf("Invalid position.\n");
        return;
    }

    if (pos == 1) {
        insert_beg();
        return;
    }

    Node *temp = (Node *)malloc(sizeof(Node));
    printf("Enter data: ");
    scanf("%d", &temp->data);

    Node *p = tail->link;
    while (i < pos - 1) {
        p = p->link;
        i++;
    }
    temp->link = p->link;
    p->link = temp;

    if (p == tail) {
        tail = temp;
    }
}

// Delete at the beginning
void delete_beg() {
    if (tail == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node *temp = tail->link;

    if (tail->link == tail) {
        tail = NULL;
    } else {
        tail->link = temp->link;
    }

    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

// Delete at the end
void delete_end() {
    if (tail == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node *temp = tail->link;
    if (tail->link == tail) {
        printf("Deleted element: %d\n", tail->data);
        free(tail);
        tail = NULL;
    } else {
        Node *p;
        while (temp->link != tail->link) {
            p = temp;
            temp = temp->link;
        }
        p->link = tail->link;
        printf("Deleted element: %d\n", tail->data);
        free(tail);
        tail = p;
    }
}

// Delete at a specified position
void delete_at_pos() {
    int pos, i = 1, length;
    printf("Enter position: ");
    scanf("%d", &pos);

    length = get_length();
    if (pos < 1 || pos > length) {
        printf("Invalid position.\n");
        return;
    }

    if (pos == 1) {
        delete_beg();
        return;
    }

    Node *temp = tail->link, *p;
    while (i < pos - 1) {
        temp = temp->link;
        i++;
    }
    p = temp->link;
    temp->link = p->link;

    if (p == tail) {
        tail = temp;
    }

    printf("Deleted element: %d\n", p->data);
    free(p);
}

// Display the elements of the circular singly linked list
void display() {
    if (tail == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node *p = tail->link;
    printf("Elements of the list: ");
    do {
        printf("%d ", p->data);
        p = p->link;
    } while (p != tail->link);
    printf("\n");
}

// Main function to demonstrate the operations
int main() {
    int choice;
    while (1) {
        printf("\n1. Insert at Beginning\n2. Insert at End\n3. Insert at Position\n4. Delete at Beginning\n5. Delete at End\n6. Delete at Position\n7. Display\n8. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert_beg();
                break;
            case 2:
                insert_end();
                break;
            case 3:
                insert_at_pos();
                break;
            case 4:
                delete_beg();
                break;
            case 5:
                delete_end();
                break;
            case 6:
                delete_at_pos();
                break;
            case 7:
                display();
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
