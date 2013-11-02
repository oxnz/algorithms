#include <stdio.h>
#include "../../../utils/utils.h"

void gnome_sort(int a[], int n) {
    int i = 0;
    while (i < n) {
        if (i == 0 || a[i-1] <= a[i])
            ++i;
        else {
            swap(&a[i], &a[i-1]);
            --i;
        }
    }
}

int main(void) {
    int a[20];
    random_array(a, 20);
    print_array(a, 20);
    gnome_sort(a, 20);
    print_array(a, 20);

    return 0;
}
