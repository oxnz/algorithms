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
#include <math.h>

#include "qsort.h"
#include "qsort_lib.h"
#include "perf.h"

static unsigned long cnt;

static int
int_cmp(const void *p, const void *q) {
    ++cnt;
    return *(const int *)p - *(const int *)q;
}

static int
long_cmp(const void *p, const void *q) {
    ++cnt;
    long o = *(const long *)p - *(const long *)q;
    return o < 0 ? -1 : (o == 0 ? 0 : 1);
}

static int
long_long_cmp(const void *p, const void *q) {
    ++cnt;
    long long o = *(const long long *)p - *(const long long *)q;
    return o < 0 ? -1 : (o == 0 ? 0 : 1);
}

static int
long_double_cmp(const void *p, const void *q) {
    ++cnt;
//    for (int i = 1000; i > 0; --i)
//        cnt += (i % 2 ? 1 : -1);
    long double o = o = *(const long double *)p - *(const long double *)q;
    return o < 0 ? -1 : (o > 0 ? 1 : 0);
}

static void
dump_array(long *p, size_t n) {
    printf("[");
    for (int i = 0; i < n; ++i)
        printf("%ld ", p[i]);
    printf("\b]\n");
}

static void
debug_array(size_t n) {
    long p[n];
    srand((clock()<<32)>>32);
    for (size_t i = 0; i < n; ++i)
        p[i] = random() % 100000;
    dump_array(p, n);
    qsort_s2(p, n, sizeof(long), long_cmp);
    if (! sort_valid((char *)p, sizeof(long), n, long_cmp))
        printf("sort failed\n");
    else
        printf(".");
}

typedef struct {
	const char *name;
	int (*sortf)(void *, size_t, size_t, int (*)(const void *, const void *));
    clock_t tm;
    unsigned long count;
    unsigned long swap_cnt;
} perf_stat_t;

static int
perf_sort(perf_stat_t *st, size_t es, size_t n, size_t times) {
    perf_stat_t stats[times];
    int (*cmp)(const void *, const void *);
    if (es == sizeof(long long)) cmp = long_long_cmp;
    else if (es == sizeof(long double)) cmp = long_double_cmp;
    else if (es == sizeof(int)) cmp = int_cmp;
    else { printf("invalid es\n"); return -1; }
    void *p = malloc(es*n);
    if (p == 0) {
		perror("malloc");
		return -1;
	}
    for (int i = 0; i < times; ++i) {
        for (size_t i = 0; i < n; ++i)
            *(long double *)(p+i*es) = 100 * random() / (long double)n;
        stats[i].tm = clock();
        cnt = 0;
		stats[i].swap_cnt = st->sortf(p, n, es, cmp);
        stats[i].tm = clock() - stats[i].tm;
        stats[i].count = cnt;
        printf("%s tm: %lu, cmp: %lu\n", st->name, stats[i].tm, stats[i].count);
    }
    free(p);
    clock_t mean = 0;
    unsigned long long mcmp = 0, mswap = 0;
	for (int i = 0; i < times; ++i) {
		mean += stats[i].tm;
		mcmp += stats[i].count;
        mswap += stats[i].swap_cnt;
	}
	st->tm = mean/times;
	st->count = mcmp/times;
    st->swap_cnt = mswap/times;
	return 0;
}

static void
report(size_t start, size_t end, size_t es, size_t ntime) {
	perf_stat_t st[] = {
		{"qsort_l", qsort_l, 0, 0},
        {"qsort_2", qsort_s2, 0, 0},
        {"qsort_3", qsort_s3, 0, 0},
//        {"qsort_o", qsort_opt, 0, 0},
//        {"hsort_l", heapsort, 0, 0},
		{"msort_l", mergesort, 0, 0},
	};
	size_t nperf = sizeof(st)/sizeof(st[0]);
	size_t nelem;
	double ncmp;
	for (size_t i = start; i <= end; ++i) {
		nelem = 1 << i;
		ncmp = stirling_f(nelem);
		for (size_t j = 0; j < nperf; ++j) {
			perf_sort(&st[j], es, nelem, ntime);
		}
		printf("#%-8zu %10s %6s %10s %10s %10s %10s\n", nelem,
               "time", "ratio", "cmp", "ratio", "swap", "ratio");
		for (size_t j = 0; j < nperf; ++j) {
			printf("%-10s %10lu %6.2f%% %10lu %8.2f%% %10lu %8.2f%%\n",
                   st[j].name, st[j].tm,
                   st[j].tm*100.0/st[nperf-1].tm,
                   st[j].count, st[j].count*100/ncmp,
                   st[j].swap_cnt, 0.0
                   );
		}
	}
}

int main(int argc, const char * argv[]) {
	// insert code here...
	int opt = 'p';
	printf("Hello, World!\n");
	switch (opt) {
		case 'd':
			for (int i = 10; i < 100; ++i)
				debug_array(i);
			break;
		case 'p':
			{
				size_t start = 10, end = 22, ntime = 4;
				report(start, end, sizeof(long double), ntime);
			}
			break;
		default:
			break;
	}

	return 0;
}
