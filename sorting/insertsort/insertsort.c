#include <stdio.h>


void insert_sort1(int a[], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = i; j > 0 && a[j] > a[j-1]; --j) {
            int tmp = a[j];
            a[j] = a[j-1];
            a[j-1] = tmp;
        }
    }
}

void insertion_sort2(int a[], int n) {
	int t;
	for (int i = 1; i < n; ++i) {
		t = a[i];
		int j = i;
		for (; j > 0 && a[j] > t; --j)
			a[j] = a[j-1];
		a[j] = t;
	}
}

/*
int main() {
    int a[10] = {232, 43, 321321, 32, 43, 5, 87, 9898, 43242, 3213};
    for (int i = 0; i < 10; ++i)
        printf("%d ", a[i]);
    putchar('\n');
    insert_sort(a, 10);
    for (int i = 0; i < 10; ++i)
        printf("%d ", a[i]);
    putchar('\n');

    return 0;
}
*/
