#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct Node* insert(struct Node* root, int data) {
    struct Node* newNode = createNode(data);

    
    if (root == NULL)
        return newNode;

    struct Node* current = root;
    struct Node* parent = NULL;

    while (current != NULL) {
        parent = current;

        if (data < current->data)
            current = current->left;
        else if (data > current->data)
            current = current->right;
        else {
            printf("Duplicate value %d not inserted!\n", data);
            return root;
        }
    }

    if (data < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;

    return root;
}

struct Node* create(struct Node* root) {
    int n, data;
    printf("Enter number of nodes to insert: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &data);
        root = insert(root, data);
    }

    printf("All nodes inserted successfully!\n");
    return root;
}



struct Node* findMin(struct Node* root) {
    while (root && root->left != NULL)
        root = root->left;
    return root;
}

struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        
        if (root->left == NULL && root->right == NULL) {
            printf("\nDeleting %d\n", root->data);
            return NULL; 
        }
        else if (root->left == NULL) {
            printf("\nDeleting %d \n", root->data);
            return root->right;
        }
        else if (root->right == NULL) {
            printf("\nDeleting %d \n", root->data);
            return root->left;
        }
        printf("\nDeleting %d 1\n", root->data);
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}


void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, data;

    while (1) {
        printf("1. Create BST (Insert Multiple Nodes)\n");
        printf("2. Insert Single Node\n");
        printf("3. Delete a Node\n");
        printf("4. Display Inorder Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            root = create(root);
            break;

        case 2:
            printf("Enter element to insert: ");
            scanf("%d", &data);
            root = insert(root, data);
            break;

        case 3:
            if (root == NULL) {
                printf("Tree is empty!\n");
                break;
            }
            printf("Enter node value to delete: ");
            scanf("%d", &data);
            root = deleteNode(root, data);
            break;

        case 4:
            if (root == NULL)
                printf("Tree is empty!\n");
            else {
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
            }
            break;

        case 5:
            printf("Exiting...\n");
            return 0;

        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}