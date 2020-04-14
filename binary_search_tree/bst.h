#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void insert(); // insert value into tree
int get_node_count(); // get count of values stored
void print_values(); // prints the values in the tree, from min to max
void delete_tree();
bool is_in_tree(); // returns true if given value exists in the tree
int get_height(); // returns the height in nodes (single node's height is 1)
int get_min(); // returns the minimum value stored in the tree
int get_max(); // returns the maximum value stored in the tree
bool is_binary_search_tree();
void delete_value();
int get_successor(); // returns next-highest value in tree after given value, -1 if none

#endif