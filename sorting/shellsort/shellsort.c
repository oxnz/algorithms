#include <stdio.h>

void shell_sort(int a[], int n) {
    int h = 1;
    while (h < n/3)
        h = 3*h + 1; // 1, 4, 13, 40, 121, 364, 1093, ...
    while (h >= 1) {
        // sort h
        for (int i = h; i < n; ++i) {
            for (int j = i; j >= h && a[j] < a[j-h]; j -= h) {
                int tmp = a[j];
                a[j] = a[j-h];
                a[j-h] = tmp;
            }
        }
        h = h/3;
    }
}

int main() {
    int a[20] = {321, 32, 32, 43, 4, 65, 87, 32, 4342, 43, 5454, 6776, 564};
    for (int i = 0; i < 20; ++i)
        printf("%d ", a[i]);
    putchar('\n');
    shell_sort(a, 20);
    for (int i = 0; i < 20; ++i)
        printf("%d ", a[i]);
    putchar('\n');

    return 0;
}
