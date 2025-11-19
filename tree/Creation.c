#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}


struct Node* createTree() {
    int value;
    printf("Enter data (-1 for no node): ");
    scanf("%d", &value);

    if (value == -1)
        return NULL;

    struct Node* root = createNode(value);

    printf("Enter left child of %d:\n", value);
    root->left = createTree();

    printf("Enter right child of %d:\n", value);
    root->right = createTree();

    return root;
}

//(Root → Left → Right)
void preOrder(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

//(Left → Root → Right)
void inOrder(struct Node* root) {
    if (root == NULL) return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

//(Left → Right → Root)
void postOrder(struct Node* root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}


int main() {
    struct Node* root = NULL;

    printf("Create your binary tree:\n");
    root = createTree();

    printf("\nPreorder traversal: ");
    preOrder(root);

    printf("\nInorder traversal: ");
    inOrder(root);

    printf("\nPostorder traversal: ");
    postOrder(root);

    printf("\n");
    return 0;
}
