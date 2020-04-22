#include "quick_sort.h"

int main() {
    int numbers[] = {5, 86, 69, 73, 11, 17, 1, 74, 34, 3};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    print_array(numbers, size);

    quick_sort(numbers, size);

    print_array(numbers, size);
    return 0;
}