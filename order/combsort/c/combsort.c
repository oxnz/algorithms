#include <stdio.h>
#include "../../../utils/utils.h"


void comb_sort(int a[], int n) {
    float shrink_factor = 1.247330950103979;
    int gap = n;
    int swapped = 1;
    while ((gap > 1) || swapped) {
        if (gap > 1) gap = gap / shrink_factor;

        swapped = 0;
        for (int i = 0; i+gap < n; ++i)
            if (a[i] > a[i+gap]) {
                swap(&a[i], &a[i+gap]);
                swapped = 1;
            }
    }
}

int main(void) {
    int a[20];
    random_array(a, 20);
    print_array(a, 20);
    comb_sort(a, 20);
    print_array(a, 20);

    return 0;
}
