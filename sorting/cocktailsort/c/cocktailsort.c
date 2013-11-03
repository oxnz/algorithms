#include <stdio.h>
#include "../../../utils/utils.h"

void cocktail_sort(int a[], int n) {
    int swapped = 0;
    do {
        swapped = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] > a[i+1]) {
                swap(&a[i], &a[i+1]);
                swapped = 1;
            }
        }

        for (int i = n-1; i > 0; --i) {
            if (a[i-1] > a[i]) {
                swap(&a[i], &a[i-1]);
                swapped = 1;
            }
        }
    } while (swapped);
}

int main(void) {
    int a[20];
    random_array(a, 20);
    print_array(a, 20);
    cocktail_sort(a, 20);
    print_array(a, 20);

    return 0;
}
