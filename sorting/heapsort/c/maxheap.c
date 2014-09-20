/*
     Filename: maxheap.c
  Description: 

      Version: 0.1
      Created: 2014-09-18 23:04:12
  Last-update: 2014-09-20 23:06:19
     Revision: None

       Author: Oxnz
        Email: yunxinyi@gmail.com

Revision history:
	Date Author Remarks
*/
#include <stdio.h>
#include "../../../utils/utils.h"

int parent(int i) {
	return (i-1)/2;
}

int left(int i) {
	return ((i+1) << 1)-1;
}

int right(int i) {
	return ((i+1) << 1);
}

void max_heapify(int a[], int n, int i) {
	int l = left(i);
	int r = right(i);
	int maxi = i;
	if (l < n && a[l] > a[maxi])
		maxi = l;
	if (r < n && a[r] > a[maxi])
		maxi = r;
	if (maxi != i) {
		swap(&a[i], &a[maxi]);
		max_heapify(a, n, maxi);
	}
}

void build_max_heap(int a[], int n) {
	for (int i = n/2-1; i >= 0; --i)
		max_heapify(a, n, i);
}

void heap_sort(int a[], int n) {
	build_max_heap(a, n);
	for (int i = n-1; i > 0; --i) {
		swap(&a[0], &a[i]);
		max_heapify(a, i, 0);
	}
}

int main() {
    int a[13];
	int n = sizeof(a)/sizeof(a[0]);
    random_array(a, n);
    print_array(a, n);
    heap_sort(a, n);
    print_array(a, n);

	return 0;
}
