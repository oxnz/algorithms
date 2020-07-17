#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../../utils/utils.h"

void counting_sort(int a[], int n) {
    int *b = (int*)malloc(n*sizeof(int)); // buffer array
    memset(b, 0, sizeof(int)*n);
    int max = a[0];
    for (int i = 1; i < n; ++i)
        if (max < a[i])
            max = a[i];
    ++max;
    int *c = (int*)malloc(sizeof(int)*max); // count array
    memset(c, 0, sizeof(int)*max);
    for (int i = 0; i < n; ++i)
        ++c[a[i]];

    for (int i = 1; i < max; ++i)
        c[i] += c[i-1];

    for (int i = n-1; i >= 0; --i) {
        b[c[a[i]]-1] = a[i];
        --c[a[i]];
    }
    for (int i = 0; i < n; ++i)
        a[i] = b[i];
    free(b);
    free(c);
}

int main(void) {
    int a[20];
    random_array(a, 20);
    print_array(a, 20);
    counting_sort(a, 20);
    print_array(a, 20);

    return 0;
}
