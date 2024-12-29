#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node using typedef
typedef struct node {
    int data;
    struct node *llink;
    struct node *rlink;
} Node;

Node *root = NULL, *tail = NULL;

// Display the elements of the Doubly Linked List
void display() {
    Node *temp = root;
    if (root == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Elements of the list: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->rlink;
    }
    printf("\n");
}

// Insert a node at the end
void insert_end() {
    Node *temp = (Node *)malloc(sizeof(Node));
    printf("Enter data: ");
    scanf("%d", &temp->data);
    temp->llink = NULL;
    temp->rlink = NULL;

    if (root == NULL) {
        root = tail = temp;
    } else {
        tail->rlink = temp;
        temp->llink = tail;
        tail = temp;
    }
}

// Insert at the beginning
void ins_beg() {
    Node *temp = (Node *)malloc(sizeof(Node));
    printf("Enter data: ");
    scanf("%d", &temp->data);
    temp->llink = NULL;
    temp->rlink = root;

    if (root != NULL) {
        root->llink = temp;
    } else {
        tail = temp;
    }
    root = temp;
}

// Insert at a specified position
void ins_at_pos() {
    int pos, i = 1;
    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos < 1) {
        printf("Invalid position.\n");
        return;
    } else if (pos == 1) {
        ins_beg();
        return;
    }

    Node *temp = (Node *)malloc(sizeof(Node));
    Node *p = root;
    printf("Enter data: ");
    scanf("%d", &temp->data);
    temp->llink = NULL;
    temp->rlink = NULL;

    while (i < pos - 1 && p != NULL) {
        p = p->rlink;
        i++;
    }

    if (p == NULL) {
        printf("Position out of range.\n");
        free(temp);
        return;
    }

    temp->rlink = p->rlink;
    if (p->rlink != NULL) {
        p->rlink->llink = temp;
    } else {
        tail = temp;
    }
    p->rlink = temp;
    temp->llink = p;
}

// Delete at the beginning
void del_beg() {
    if (root == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node *temp = root;
    root = root->rlink;
    if (root != NULL) {
        root->llink = NULL;
    } else {
        tail = NULL;
    }
    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

// Delete at the end
void del_end() {
    if (tail == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node *temp = tail;
    tail = tail->llink;
    if (tail != NULL) {
        tail->rlink = NULL;
    } else {
        root = NULL;
    }
    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

// Delete at a specified position
void del_pos() {
    int pos, i = 1;
    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos < 1 || root == NULL) {
        printf("Invalid position or list is empty.\n");
        return;
    }

    Node *temp = root;

    while (i < pos && temp != NULL) {
        temp = temp->rlink;
        i++;
    }

    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }

    if (temp->llink != NULL) {
        temp->llink->rlink = temp->rlink;
    } else {
        root = temp->rlink;
    }

    if (temp->rlink != NULL) {
        temp->rlink->llink = temp->llink;
    } else {
        tail = temp->llink;
    }

    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

// Reverse the list
void reverse() {
    Node *current = root, *temp = NULL;
    while (current != NULL) {
        temp = current->llink;
        current->llink = current->rlink;
        current->rlink = temp;
        current = current->llink;
    }

    if (temp != NULL) {
        tail = root;
        root = temp->llink;
    }
    printf("List reversed.\n");
}

// Concatenate two lists
void concatenate(Node *root1, Node *root2) {
    if (root1 == NULL) {
        root = root2;
    } else {
        Node *temp = root1;
        while (temp->rlink != NULL) {
            temp = temp->rlink;
        }
        temp->rlink = root2;
        if (root2 != NULL) {
            root2->llink = temp;
        }
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Insert End\n2. Insert Beginning\n3. Insert at Position\n4. Delete Beginning\n5. Delete End\n6. Delete at Position\n7. Display\n8. Reverse\n9. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert_end();
                break;
            case 2:
                ins_beg();
                break;
            case 3:
                ins_at_pos();
                break;
            case 4:
                del_beg();
                break;
            case 5:
                del_end();
                break;
            case 6:
                del_pos();
                break;
            case 7:
                display();
                break;
            case 8:
                reverse();
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
