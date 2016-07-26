//
//  main.c
//  qsort
//
//  Created by 云心逸 on 7/25/16.
//  Copyright © 2016 Errpro,Inc. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "qsort.h"

static unsigned long cnt;
static int
long_cmp(const void *p, const void *q) {
    ++cnt;
    long o = *(const long *)p - *(const long *)q;
    return o < 0 ? -1 : (o == 0 ? 0 : 1);
}

static void
dump_array(long *p, size_t n) {
    printf("[");
    for (int i = 0; i < n; ++i)
        printf("%ld ", p[i]);
    printf("\b]\n");
}

static void
debug_array(void) {
    long p[] = {0, 9, 2, 5, 0, 3, 5, 2, 5, 3, 7, 2, 4, 5, 4, 9, 8, 1};
    size_t n = sizeof(p)/sizeof(p[0]);
    dump_array(p, n);
    qsort_s(p, n, sizeof(long), long_cmp);
    dump_array(p, n);
}

typedef struct {
    clock_t tm;
    unsigned long count;
} perf_stat_t;

static int
perf_long(size_t n, size_t times) {
    perf_stat_t stats[times];
    for (int i = 0; i < times; ++i) {
        long *p = malloc(sizeof(long) * n);
        if (p == 0) return -1;
        for (size_t i = 0; i < n; ++i)
            *(long *)(p+i) = random() % 32; //random()%(n > 1000 ? n/1000 : n);
        stats[i].tm = clock();
        cnt = 0;
        if (i % 2)
            qsort_s(p, n, sizeof(long), long_cmp);
        else
            mergesort(p, n, sizeof(long), long_cmp);
        stats[i].tm = clock() - stats[i].tm;
        stats[i].count = cnt;
        free(p);
    }
    clock_t mmean = 0, qmean = 0;
    unsigned long long qcmp = 0, mcmp = 0;
    for (int i = 0; i < times; ++i) {
        if (i % 2) {
            qmean += stats[i].tm;
            qcmp += stats[i].count;
        } else {
            mmean += stats[i].tm;
            mcmp += stats[i].count;
        }
    }
    times >>= 1;
    printf("#%lu tm: %10lu/%-10lu = %4.2lf%% cmp: %llu/%llu = %4.2lf%%\n", n, qmean/times, mmean/times,
           (qmean*100.0)/mmean, qcmp/times, mcmp/times, qcmp*100.0/mcmp
           );
    return 0;
}

static void
report(perf_stat_t *stats) {
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int opt = 'p';
    printf("Hello, World!\n");
    switch (opt) {
        case 'd':
            debug_array();
            break;
        case 'p':
            for (int i = 2; i < 18; ++i)
                perf_long(1<<i, 200);
            break;
        default:
            break;
    }
    
    return 0;
}
