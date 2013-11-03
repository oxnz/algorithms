#include <stdio.h>
#include <stdlib.h>
#include "../../../utils/utils.h"

/*
 * n: 待排序元素个数
 * a: 待排序数组
 * factor: 常数因子
 */
void library_sort(int a[], int n) {
    int len = (int)((1+factor)*n);
    int *o = (int*)malloc(len*sizeof(int));
    int flag = 1 << 31;
    for (int i = 0; i < len; ++i)
        o[i] = flag;
    free(o);
}

int main(void) {
    int a[20];
    random_array(a, 20);
    print_array(a, 20);
    library_sort(a, 20);
    print_array(a, 20);

    return 0;
}
