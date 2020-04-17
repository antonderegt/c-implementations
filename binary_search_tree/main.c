#include "bst.h"
#include <assert.h>

int main() {
    Node* bst = NULL;

    assert(get_min(bst) == -1);
    assert(get_max(bst) == -1);
    print_values(bst);
    bst = insert(bst, 20);
    bst = insert(bst, 10);
    bst = insert(bst, 30);
    bst = insert(bst, 50);
    bst = insert(bst, 70);
    bst = insert(bst, 40);
    bst = insert(bst, 60);
    print_values(bst);

    assert(get_successor(bst, 30) == 40);
    assert(get_successor(bst, 70) == -1);
    assert(get_successor(bst, 99) == -1);

    assert(get_node_count(bst) == 7);

    assert(is_in_tree(bst, 70) == true);
    assert(is_in_tree(bst, 99) == false);

    assert(get_min(bst) == 10);
    assert(get_max(bst) == 70);

    assert(get_height(bst) == 6);

    assert(is_binary_search_tree(bst) == true);

    bst = delete_value(bst, 60);
    bst = delete_value(bst, 50);
    bst = delete_value(bst, 70);
    bst = delete_value(bst, 99);
    assert(get_node_count(bst) == 4);

    delete_tree(&bst);
    print_values(bst);
    assert(get_node_count(bst) == 0);


    return 0;
}