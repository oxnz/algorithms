#include <stdio.h>
#include "../../../utils/utils.h"

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

void heap_adjust3(int array[], int i, int size) {
    for (int j = size/2; j >= 0; --j) {
        if (2*j+1 < size) {
            int index = array[2*j] > array[2*j+1] ? 2*j : 2*j+1;
            if (array[j] < array[index])
                swap(&array[j], &array[index]);
        }
    }
}

void sift_up(int a[], int i) {
    for (;i > 1 && a[i] > a[i/2]; i = i/2)
        swap(&a[i], &a[i/2]);
}

void sift_down(int a[], int i, int n) {
    int j;
    while (2*i < n) {
        j = a[2*i] > a[2*i+1] ? 2*i : (2*i+1);
        if (a[i] < a[j]) {
            swap(&a[i], &a[j]);
            i = j;
        } else break;
    }
}

void make_heap(int a[], int n) {
    for (int i = n/2-1; i >= 0; --i)
        sift_down(a, i, n);
}

void heap_sort(int array[], int n) {
    int tmp;
    //    for (int i = n/2-1; i >= 0; --i)
    //  heap_adjust4(array, i, n);
    make_heap(array, n);
    printf("after adust\n");
    print_array(array, n);
    for (int i = n-1; i > 0; --i) {
        swap(&array[i], &array[0]);
        sift_down(array, 0, i-1);
        //        heap_adjust4(array, 0, i);
    }
}

int main(void) {
    int a[20] = {1, 2, 3, 9, 6, 5, 4, 32, 1231312, 54, 65, 76, 87, 220, 32};
    random_array(a, 20);
    print_array(a, 20);
    heap_sort(a, 20);
    print_array(a, 20);

    return 0;
}
