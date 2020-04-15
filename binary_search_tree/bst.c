#include "bst.h"

Node* newNode(int value) {
    Node* node = malloc(sizeof(Node));
    node->value = value;
    node->left = node->right = NULL;
    return node;
}

Node* insert(Node* root, int value) {
    if(root == NULL) {
        return newNode(value);
    } else if(value <= root->value) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

void print_values(Node* root) {
    if(root->left != NULL) {
        print_values(root->left);
    }

    printf("%d\n", root->value);
    
    if(root->right != NULL) {
        print_values(root->right);
    }
}