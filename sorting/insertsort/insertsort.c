#include <stdio.h>


void insert_sort(int a[], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = i; j > 0 && a[j] > a[j-1]; --j) {
            int tmp = a[j];
            a[j] = a[j-1];
            a[j-1] = tmp;
        }
    }
}

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
