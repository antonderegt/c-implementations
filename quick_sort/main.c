#include "quick_sort.h"

int main() {
    int array[] = {5, 86, 69, 73, 11, 17, 1, 74, 34, 3};
    int size = sizeof(array) / sizeof(array[0]);

    print_array(array, size);

    quick_sort(array, size);

    print_array(array, size);
    return 0;
}