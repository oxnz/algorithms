#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "utils.h"

void random_array(int a[], int n) {
    srand(time(0));
    for (int i = 0; i < n; ++i)
        a[i] = rand()%100;
}
