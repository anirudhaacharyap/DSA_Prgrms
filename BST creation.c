#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node of the binary search tree
typedef struct node {
    int key;
    struct node *left;
    struct node *right;
} Node;

// Function to create a new node with the given value
Node* getNewNode(int val) {
    Node* newNode = malloc(sizeof(Node));
    newNode->key = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node in the binary search tree
Node* insert(Node* root, int val) {
    if (root == NULL) {
        return getNewNode(val); // Insert node at the first empty position
    }

    if (val < root->key) {
        root->left = insert(root->left, val); // Insert in left subtree
    } else if (val > root->key) {
        root->right = insert(root->right, val); // Insert in right subtree
    }

    return root; // Return the unchanged root pointer
}

// Function to perform inorder traversal and print the tree
void inorder(Node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);  // Traverse left subtree
    printf("%d ", root->key);  // Print node's value
    inorder(root->right); // Traverse right subtree
}

int main() {
    Node* root = NULL;  // Initialize an empty tree

    // Insert values into the BST
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    // Print the inorder traversal (should print the elements in ascending order)
    printf("Inorder traversal of the BST:\n");
    inorder(root);
    printf("\n");

    return 0;
}
