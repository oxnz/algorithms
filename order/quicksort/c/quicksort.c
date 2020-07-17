#include <stdio.h>

void quicksort(int a[], int left, int right) {
    if (left >= right)
        return;
    int l = left;
    int r = right;
    int m = a[l];
    while (l < r) {
        while (l < r && a[r] >= m)
            --r;
        if (l < r)
            a[l++] = a[r];
        while (l < r && a[l] < m)
            ++l;
        if (l < r)
            a[r--] = a[l];
    }
    a[l] = m;
    quicksort(a, left, l-1);
    quicksort(a, l+1, right);

}

void print_array(int a[], int n) {
    int i;
    for (i = 0; i < n; ++i)
        printf("%d ", a[i]);
    putchar('\n');
}

int main(void) {
    int a[20] = {213, 321,3, 23,2, 32,3, 2,43, 100, 999, 200, 1, 0};
    print_array(a, 20);
    quicksort(a, 0, 19);
    print_array(a, 20);

    return 0;
}
