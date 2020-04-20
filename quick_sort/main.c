#include "quick_sort.h"

int main() {
    int array[] = {12,54,13,67,34,5,8,52,234, -10};
    int size = sizeof(array) / sizeof(array[0]);

    print_array(array, size);

    quick_sort(array, size);

    print_array(array, size);
    return 0;
}