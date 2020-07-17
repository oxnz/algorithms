#include <stdio.h>
#include "../../../utils/utils.h"

#define MAX_BUCKET 100
static int buf[MAX_BUCKET] = {0}; // 最大数个空桶
void bucket_sort(int a[], int n) {
    for (int i = 0; i < n; ++i)
        buf[a[i]] = a[i];
    int j = 0;
    for (int i = 0; i < MAX_BUCKET; ++i)
        if (buf[i] != 0)
            a[j++] = buf[i];
}

int main(void) {
    int a[20];
    random_array(a, 20);
    print_array(a, 20);
    bucket_sort(a, 20);
    print_array(a, 20);

    return 0;
}
