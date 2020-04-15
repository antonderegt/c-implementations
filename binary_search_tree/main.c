#include "bst.h"
#include <assert.h>

int main() {
    Node* bst = NULL;

    bst = insert(bst, 20);
    bst = insert(bst, 10);
    bst = insert(bst, 30);
    bst = insert(bst, 50);
    bst = insert(bst, 70);
    bst = insert(bst, 40);
    bst = insert(bst, 60);
    print_values(bst);

    return 0;
}