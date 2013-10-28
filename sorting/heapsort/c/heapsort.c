void heap_adjust(int array[], int i, int size) {
    int lchild = 2*i;
    int rchild = 2*i+1;
    int max = i;
    if (i <= size/2) {
        if (lchild <= size && array[lchild] > array[max])
            max = lchild;
        if (rchild <= size && array[rchild] > array[max])
            max = rchild;
        if (max != i) {
            // swap(array[i], array[max]);
            int tmp = array[i];
            array[i] = array[max];
            array[max] = tmp;
            heap_adjust(array, max, size);
        }
    }
}

void heap_adjust2(int array[], int i, int size) {
    int nChild;
    int nTmp;
    for (nTmp = array[i]; 2*i+1 < size; i = nChild) {
        nChild = 2*i+1;
        if (nChild < size-1 && array[nChild+1] > array[nChild])
            ++nChild;
        if (nTmp < array[nChild]) {
            array[i] = array[nChild];
            array[nChild] = nTmp;
        }
        else break;
    }
}
           
void heap_sort(int array[], int n) {
    int tmp;
    for (int i = n/2-1; i >= 0; --i)
        heap_adjust2(array, i, n);
    for (int i = n-1; i > 0; --i) {
        tmp = array[i];
        array[i] = array[0];
        array[0] = tmp;
        heap_adjust2(array, 0, i);
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
