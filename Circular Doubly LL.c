#include <stdio.h>
#include <stdlib.h>

// Define the structure for circular doubly linked list node
typedef struct node {
    int data;
    struct node *llink;
    struct node *rlink;
} Node;

Node *root = NULL, *tail = NULL;

// Function to get the length of the circular doubly linked list
int get_length() {
    if (root == NULL) {
        return 0;
    }
    int count = 0;
    Node *temp = root;
    do {
        count++;
        temp = temp->rlink;
    } while (temp != root);
    return count;
}

// Insert at the beginning
void insert_beg() {
    Node *temp = (Node *)malloc(sizeof(Node));
    printf("Enter data: ");
    scanf("%d", &temp->data);

    if (root == NULL) {
        root = tail = temp;
        temp->llink = temp->rlink = temp;
    } else {
        temp->rlink = root;
        root->llink = temp;
        temp->llink = tail;
        tail->rlink = temp;
        root = temp;
    }
}

// Insert at the end
void insert_end() {
    Node *temp = (Node *)malloc(sizeof(Node));
    printf("Enter data: ");
    scanf("%d", &temp->data);

    if (root == NULL) {
        root = tail = temp;
        temp->llink = temp->rlink = temp;
    } else {
        temp->llink = tail;
        tail->rlink = temp;
        temp->rlink = root;
        root->llink = temp;
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

    Node *current = root;
    while (i < pos - 1) {
        current = current->rlink;
        i++;
    }
    temp->rlink = current->rlink;
    temp->llink = current;
    current->rlink->llink = temp;
    current->rlink = temp;

    if (current == tail) {
        tail = temp;
    }
}

// Delete at the beginning
void delete_beg() {
    if (root == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node *temp = root;

    if (root->rlink == root) {
        root = tail = NULL;
    } else {
        root = root->rlink;
        root->llink = tail;
        tail->rlink = root;
    }

    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

// Delete at the end
void delete_end() {
    if (root == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node *temp = tail;

    if (root->rlink == root) {
        root = tail = NULL;
    } else {
        tail = tail->llink;
        tail->rlink = root;
        root->llink = tail;
    }

    printf("Deleted element: %d\n", temp->data);
    free(temp);
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

    Node *temp = root;
    while (i < pos) {
        temp = temp->rlink;
        i++;
    }
    temp->llink->rlink = temp->rlink;
    temp->rlink->llink = temp->llink;

    if (temp == tail) {
        tail = temp->llink;
    }

    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

// Display elements
void display() {
    if (root == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node *temp = root;
    printf("Elements in the list: ");
    do {
        printf("%d ", temp->data);
        temp = temp->rlink;
    } while (temp != root);
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
