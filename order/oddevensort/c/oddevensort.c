#include <stdio.h>
#include "../../../utils/utils.h"

void odd_even_sort(int a[], int n) {
    for (int i = n-1; i > n/2 - 1; --i) {
        for (int j = 1; j < n-1; j += 2)
            if (a[j] > a[j+1])
                swap(&a[j], &a[j+1]);
        for (int j = 0; j < n-1; j += 2)
            if (a[j] > a[j+1])
                swap(&a[j], &a[j+1]);
    }
}

void odd_even_sort2(int a[], int n) {
    while (1) {
        int sorted = 1;
        for (int i = 1; i < n-1; i += 2)
            if (a[i] > a[i+1]) {
                swap(&a[i], &a[i+1]);
                sorted = 0;
            }
        for (int i = 0; i < n-1; i += 2)
            if (a[i] > a[i+1]) {
                swap(&a[i], &a[i+1]);
                sorted = 0;
            }
        if (sorted)
            return;
    }
}

int main(void) {
    int a[20];
    random_array(a, 20);
    print_array(a, 20);
    odd_even_sort2(a, 20);
    print_array(a, 20);

    return 0;
}
