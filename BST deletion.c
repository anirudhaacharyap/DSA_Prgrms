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
    if (root == NULL)
        return getNewNode(val);

    if (root->key < val)
        root->right = insert(root->right, val);
    else if (root->key > val)
        root->left = insert(root->left, val);

    return root;
}

// Function to get the minimum value in the right subtree
int getRightMin(Node *root)
{
    Node *temp = root;

    // The minimum value is in the leftmost node of the right subtree
    while (temp->left != NULL)
        temp = temp->left;

    return temp->key;
}

// Function to remove a node from the binary search tree
Node *removeNode(Node *root, int val)
{
    if (root == NULL)
        return NULL;

    // Search for the node to remove
    if (root->key < val)
        root->right = removeNode(root->right, val);
    else if (root->key > val)
        root->left = removeNode(root->left, val);
    else
    {
        // Case 1: Leaf node
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        // Case 2: Node with only right child
        else if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        // Case 3: Node with only left child
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        // Case 4: Node with both children
        else
        {
            int rightMin = getRightMin(root->right);
            root->key = rightMin;
            root->right = removeNode(root->right, rightMin);
        }
    }

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
    // Constructing the tree
    Node *root = NULL;
    root = insert(root, 100);
    root = insert(root, 50);
    root = insert(root, 200);
    root = insert(root, 150);
    root = insert(root, 300);

    printf("Initial tree :\t");
    inorder(root);
    printf("\n");

    // Remove leaf node 300
    root = removeNode(root, 300);
    printf("After deletion of 300, the new tree :\t");
    inorder(root);
    printf("\n");

    // Remove root node 100
    root = removeNode(root, 100);
    printf("After deletion of 100, the new tree :\t");
    inorder(root);
    printf("\n");

    return 0;
}
