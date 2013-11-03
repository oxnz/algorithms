#include <stdio.h>
#include "../../../utils/utils.h"

#define PBUFLEN 1024
int buf[PBUFLEN];

void pogeon_sort(int a[], int n, int max) {
    if (max > PBUFLEN) {
        printf("error: max too large\n");
        return;
    }
    for (int i = 0; i < PBUFLEN; ++i)
        buf[i] = 0;
    for (int i = 0; i < n; ++i)
        ++buf[a[i]];
    int ix = 0;
    for (int i = 0; i <= max; ++i)
        while (buf[i]--)
            a[ix++] = i;
}

int main(void) {
    int a[20];
    random_array(a, 20);
    print_array(a, 20);
    pogeon_sort(a, 20, 99);
    print_array(a, 20);

    return 0;
}
