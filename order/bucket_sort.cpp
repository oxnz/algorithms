#include "common.h"

#define MAX_BUCKET 100
static int buf[MAX_BUCKET] = {0}; // 最大数个空桶
/**
 * @brief bucket_sort
 * 1. stable
 * 2. faster than most common sorting algorithms
 * 3. high space complexity
 * @param a
 * @param n
 */
void bucket_sort(int a[], int n) {
    for (int i = 0; i < n; ++i)
        buf[a[i]] = a[i];
    int j = 0;
    for (int i = 0; i < MAX_BUCKET; ++i)
        if (buf[i] != 0)
            a[j++] = buf[i];
}

TEST(bucket_sort, bucket_sort) {
    int v[20];
    bucket_sort(v, 20);
    EXPECT_TRUE(std::is_sorted(std::begin(v), std::end(v)));
}
