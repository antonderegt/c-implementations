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

void print_values_helper(Node* root) {
    if(root->left != NULL) {
        print_values_helper(root->left);
    }

    printf("%d\n", root->value);
    
    if(root->right != NULL) {
        print_values_helper(root->right);
    }
}

void print_values(Node* root) {
    if(root == NULL) {
        printf("Tree is empty, can't print empty trees.\n");
    } else {
        printf("\nPrinting the tree:\n");
        print_values_helper(root);
        printf("\n");
    }
}

int get_node_count(Node* root) {
    if(root == NULL) {
        return 0;
    } 
    return 1 + get_node_count(root->left) + get_node_count(root->right);
}

void delete_tree(Node** root) {
    if(*root == NULL) {
        return;
    }
    delete_tree(&(*root)->left);
    delete_tree(&(*root)->right);
    *root = NULL;
    free(*root);
}

bool is_in_tree(Node* root, int value) {
    if(root == NULL) {
        return 0;
    } else if(root->value == value) {
        return 1;
    }

    return 0 + is_in_tree(root->left, value) + is_in_tree(root->right, value);
}

int get_min(Node* root) {
    if(root == NULL) {
        printf("Tree is empty, can't get min of empty trees.\n");
        return -1;
    } else if(root->left != NULL) {
        return get_min(root->left);
    } 

    return root->value;
}