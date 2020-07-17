#include <stdio.h>
#include <string.h>
#include <math.h>
#include "../../../utils/utils.h"


// MAXLEN: array max length
// COL: decimal bits count
#define ROW 10
#define MAXLEN 100
#define COL 4
int buf[ROW][MAXLEN];

void radix_sort(int a[], int n, int r) {
    int ix;
    for (int c = 0; c < r; ++c) {
        // clear buffer
        for (int i = 0; i < ROW; ++i)
            for (int j = 0; j < n; ++j)
                buf[i][j] = 0;

        for (int i = 0; i < n; ++i) {
            ix = (a[i] / (int)pow(10, c)) % 10;
            int j = 0;
            while (buf[ix][j])
                ++j;
            buf[ix][j] = a[i];
        }
        ix = 0;
        for (int i = 0; i < ROW; ++i)
            for (int j = 0; j < n; ++j)
                if (buf[i][j])
                    a[ix++] = buf[i][j];
    }
}

int main(void) {
    int a[20];
    random_array(a, 20);
    for (int i = 0; i < 20; ++i)
        if (a[i] == 0)
            a[i] = 1;
    print_array(a, 20);
    radix_sort(a, 20, 2);
    print_array(a, 20);

    return 0;
}
