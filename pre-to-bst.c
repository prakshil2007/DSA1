#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Create a new node
struct Node *newNode(int value) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Insert a value into the BST
struct Node *insert(struct Node *root, int value) {
    if (root == NULL) {
        return newNode(value);      // empty spot found
    }
    if (value < root->data) {
        root->left = insert(root->left, value);    // go left
    } else {
        root->right = insert(root->right, value);  // go right
    }
    return root;
}

void preorder(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(struct Node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    int n, value;
    struct Node *root = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter the preorder traversal: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);   // insert in the given order
    }

    printf("Pre-order  : ");
    preorder(root);
    printf("\nIn-order   : ");
    inorder(root);
    printf("\nPost-order : ");
    postorder(root);
    printf("\n");

    return 0;
}