#include "merge_sort.h"

int main() {
    int unsorted[] = {12,54,13,67,41,34,5,8,52,234};
    int size = sizeof(unsorted) / sizeof(unsorted[0]);
    int sorted[size];

    merge_sort(unsorted, 0, size - 1);

    print_array(unsorted, size);
    return 0;
}