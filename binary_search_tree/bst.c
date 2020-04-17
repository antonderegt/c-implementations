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

int get_max(Node* root) {
    if(root == NULL) {
        printf("Tree is empty, can't get max of empty trees.\n");
        return -1;
    } else if(root->right != NULL) {
        return get_max(root->right);
    } 

    return root->value;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int get_height(Node* root) {
    if(root == NULL) {
        return 0;
    } 
    return 1 + max(get_node_count(root->left), get_node_count(root->right));
}

Node* delete_value(Node* root, int value) {
    if(root == NULL) {
        printf("Value %d not in tree.\n", value);
        return root;
    } else if(value < root->value) {
        root->left = delete_value(root->left, value);
    } else if(value > root->value) {
        root->right = delete_value(root->right, value);
    } else {
        // Delete node if it is a leaf
        if(root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
        }

        // Only left child is NULL
        else if (root->left == NULL) {
            Node* temp = root;
            root = root->right;
            free(temp);
            temp = NULL;
        }

        // Only right child is NULL
        else if(root->right == NULL) {
            Node* temp = root;
            root = root->left;
            free(temp);
            temp = NULL;
        }

        // Has two children
        else {
            int min = get_min(root->right);
            root->value = min;
            root->right = delete_value(root->right, min);
        }
    }

    return root;
} 

Node* find(Node* root, int value) {
    if(root == NULL) {
        printf("Value not in tree.\n");
        return NULL;
    }

    if(value < root->value) {
        return find(root->left, value);
    } else if(value > root->value) {
        return find(root->right, value);
    } else {
        return root;
    }
}

int get_successor(Node* root, int value) {
    Node* current = find(root, value);

    if(current == NULL) return -1;

    if(current->right != NULL) {
        return get_min(current->right);
    } else {
        Node* successor = NULL;
        Node* ancestor = root;
        while(ancestor != current) {
            if(current->value < ancestor->value) {
                successor = ancestor;
                ancestor = ancestor->left;
            } else {
                ancestor = ancestor->right;
            }
        }
        if(successor != NULL) {
            return successor->value;
        } else {
            return -1;
        }
    }
}