#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node of the binary search tree
typedef struct node {
    int key;
    struct node *left;
    struct node *right;
} Node;

// Function to create a new node with the given value
Node *getNewNode(int val)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->key = val;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Function to insert a node in the binary search tree
Node *insert(Node *root, int val)
{
    // If the tree is empty, return a new node
    if (root == NULL)
        return getNewNode(val);

    // If val is greater than root's key, insert in the right subtree
    if (root->key < val)
        root->right = insert(root->right, val);

    // If val is smaller than root's key, insert in the left subtree
    else if (root->key > val)
        root->left = insert(root->left, val);

    // Prevent duplicates by returning the root if val is equal to root's key
    return root;
}

// Function to print the tree in ascending order (inorder traversal)
void inorder(Node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
}

int main()
{
    Node *root = NULL;

    // Inserting nodes in the binary search tree
    root = insert(root, 100);
    root = insert(root, 50);
    root = insert(root, 150);
    root = insert(root, 50); // Duplicate value will not be inserted

    // Printing the tree in ascending order
    inorder(root);

    return 0;
}
