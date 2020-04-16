#include "bst.h"
#include <assert.h>

int main() {
    Node* bst = NULL;

    print_values(bst);
    bst = insert(bst, 20);
    bst = insert(bst, 10);
    bst = insert(bst, 30);
    bst = insert(bst, 50);
    bst = insert(bst, 70);
    bst = insert(bst, 40);
    bst = insert(bst, 60);
    print_values(bst);

    assert(get_node_count(bst) == 7);

    assert(is_in_tree(bst, 70) == true);
    assert(is_in_tree(bst, 99) == false);

    delete_tree(&bst);
    printf("Size: %d\n", get_node_count(bst)); 
    print_values(bst);
    assert(get_node_count(bst) == 0);


    return 0;
}