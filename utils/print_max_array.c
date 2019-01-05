/*
 * Filename:	get_max_tool.c
 *
 * Author:		Oxnz
 * Email:		yunxinyi@gmail.com
 * Created:		2016-10-10 18:13:07 CST
 * Last-update:	2016-10-10 18:13:07 CST
 *
 * Version:		0.0.1
 * Revision:	[NONE]
 * Revision history:	[NONE]
 * Date Author Remarks:	[NONE]
 * Description: print max sum sub array
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void dump_arr(int *p, int i, int j) {
    for (; i < j; ++i)
        printf("%d ", p[i]);
    printf("\n");
}

void parse_nums(char *nums[], int n, int *p) {
    int i;
    for (i = 0; i < n; ++i)
        p[i] = atoi(nums[i]);
}

int would_overflow(long long a, int b) {
    if (a > 0 && b > 0 && (int)a + b < 0) return 1;
    return 0;
}

/*
 * return
 * 0: ok
 * -1: error
 */
int print_max_subarr(int *p, int n) {
    int i = 0;
    int start = 0, end = 1;
    long long sum = 0, maxsum = INT_MIN;
    int maxsum_start = 0, maxsum_end = 0;
    while (i < n && p[i] <= 0) ++i;
    if (i == n) return 0;
    sum = p[i];
    start = i;
    end = i+1;
    while (i < n) {
        ++i;
        if (p[i] < 0) {
            if (sum > maxsum) {
                maxsum = sum;
                maxsum_start = start;
                maxsum_end = end;
                while (i < n && p[i] <= 0) ++i;
                if (i == n) {
                    dump_arr(p, maxsum_start, maxsum_end);
                    return 0;
                }
                sum = p[i];
                start = i;
                end = i+1;
            }
            sum += p[i];
            if (sum <= 0) {
                while (i < n && p[i] <= 0) ++i;
                if (i == n) {
                    dump_arr(p, maxsum_start, maxsum_end);
                    return 0;
                }
                start = i;
                end = i+1;
                sum = p[i];
            } else {
                ++end;
            }
        }
        sum += p[i];
        ++end;
        if (sum < 0) {
            fprintf(stderr, "overflow\n");
            return -1;
        }
    }
    if (sum > maxsum) {
        maxsum = sum;
        maxsum_start = start;
        maxsum_end = n;
    }
    for (i = maxsum_end - 1; sum > 0 && p[i] < 0; --i) {
        --maxsum_end;
    }
    for (i = maxsum_start; i < maxsum_end; ++i)
        printf("%d ", p[i]);
    printf("\n");
    return 0;
}
