#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct Node {
    int value;
    struct Node* left;
    struct Node* right;
};

typedef struct Node Node;

Node* insert(Node* root, int value); // insert value into tree
int get_node_count(Node* root); // get count of values stored
void print_values(Node* root); // prints the values in the tree, from min to max
void delete_tree(Node** root);
bool is_in_tree(Node* root, int value); // returns true if given value exists in the tree
int get_height(Node* root); // returns the height in nodes (single node's height is 1)
int get_min(Node* root); // returns the minimum value stored in the tree
int get_max(Node* root); // returns the maximum value stored in the tree
bool is_binary_search_tree(Node* root);
Node* delete_value(Node* root, int value);
int get_successor(Node* root, int value); // returns next-highest value in tree after given value, -1 if none

#endif