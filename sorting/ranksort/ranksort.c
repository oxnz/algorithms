#include <stdio.h>
#include <assert.h>

void rank(int a[], int an, int r[], int rn) {
    assert(rn >= an);
    for (int i = 0; i < an; ++i)
        r[i] = 0;
    for (int i = 1; i < an; ++i) {
        for (int j = 0; j < i; ++j) {
            if (a[j] <= a[i])
                ++r[i];
            else
                ++r[j];
        }
    }
}

void rearrange(int a[], int an, int r[], int rn) {
    int* u = malloc(sizeof(int)*an);
    for (int i = 0; i < an; ++i)
        u[r[i]] = a[i];
    for (int i = 0; i < an; ++i)
        a[i] = u[i];
    free(u);
}

int main(void) {
    int a[20] = {321321, 32, 43, 43, 54, 65, 76, 3123, 43, 1, 0, 0, 1321};
    int r[20] = {0};
    print_array(a, 20);
    rank(a, 20, r, 20);
    print_array(r, 20);
    rearrange(a, 20, r, 20);
    print_array(a, 20);
    return 0;
}
