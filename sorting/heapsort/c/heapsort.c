void heap_adjust(int array[], int i, int n) {
    int n_child;
    int tmp;
    for (tmp = array[i]; 2*i+1 < n; i = n_child) {
        n_child = 2 * i + 1;
        if (n_child < n - 1 && array[n_child+1] > array[n_child])
            ++n_child;
        if (tmp < array[n_child]) {
            array[i] = array[n_child];
            array[n_child] = tmp;
        }
        else
            break;
    }
}

void heap_sort(int array[], int n) {
    int tmp;
    for (int i = n/2-1; i >= 0; --i)
        heap_adjust(array, i, n);
    for (int i = n-1; i > 0; --i) {
        tmp = array[i];
        array[i] = array[0];
        array[0] = tmp;
        heap_adjust(array, 0, i);
    }
}

#include <stdio.h>

int main(void) {
    int a[20] = {1, 2, 3, 9, 6, 5, 4, 32, 1231312, 54, 65, 76, 87, 220, 32};
    heap_sort(a, 20);
    int i;
    for (i = 0; i < 20; ++i)
        printf("%d ", a[i]);
    putchar('\n');

    return 0;
}
