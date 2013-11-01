#include <stdio.h>
#include "utils.h"

int main(void) {
    int a[20];
    random_array(a, 20);
    print_array(a, 20);

    return 0;
}
