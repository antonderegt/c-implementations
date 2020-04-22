#include "quick_sort.h"

void print_array(int* numbers, int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
}
void swap(int* numbers, int low, int high) {
    int temp = numbers[low];
    numbers[low] = numbers[high];
    numbers[high] = temp;
}

void partition(int* numbers, int low, int high) {
    if(low == high) return;

    int pivotIndex = rand() % (high - low + 1);
    int pivot = numbers[low + pivotIndex];
    int i = low, j = high;

    while(i < j) {
        while (numbers[i] < pivot) ++i;
        while (numbers[j] > pivot) --j;

        if(i <= j) {
            swap(numbers, i, j);
            i++;j--;
        }
    }
    if (low < j) {
        partition(numbers, low, j);
    }

    if (high > i) {
        partition(numbers, i, high);
    }
}

void shuffle(int* a, int n) {
    int i;
    int r;
    int temp;

    for(i = n - 1; i > 0; i--) {
        r = rand() % i;
        temp = a[r];
        a[r] = a[i];
        a[i] = temp;
    }
}

void quick_sort(int* numbers, int size) {
    srand((unsigned)time(NULL));
    shuffle(numbers, size);
    partition(numbers, 0, size - 1);
}