//
//  qsort.c
//  qsort
//
//  Created by 云心逸 on 7/25/16.
//  Copyright © 2016 Errpro,Inc. All rights reserved.
//

#include "qsort.h"
#include <stdlib.h>
#include <assert.h>

static inline size_t
min(size_t a, size_t b) {
    return a < b ? a : b;
}

static void
dump_array(size_t *a, size_t n) {
    printf("=> [");
    for (int i = 0; i < n; ++i)
        printf("%lu ", a[i]);
    printf("\b]\n");
}

static inline void
swap(char *base, size_t es, size_t i, size_t j, size_t *index) {
    size_t t = index[i];
    index[i] = index[j];
    index[j] = t;
    if (es % sizeof(long) == 0) {
        size_t n = es / sizeof(long);
        long t, *pi = (long *)(base + i*es), *pj = (long *)(base + j*es);
        do {
            t = *pi;
            *pi++ = *pj;
            *pj++ = t;
        } while (--n > 0);
    } else {
        char *pi = base + es*i, *pj = base + es*j;
        do {
            t = *pi;
            *pi++ = *pj;
            *pj++ = t;
        } while (--es > 0);
    }
}

static inline void
vecswap(char *base, size_t es, size_t i, size_t j, size_t n, size_t *index) {
    while (n--)
        swap(base, es, i++, j++, index);
}

static inline void
insertion_sort_r(char *base, size_t es, size_t lo, size_t hi, size_t *index) {
    for (; lo <= hi; ++lo)
        for (size_t j = lo; j > 0 && index[j] < index[j-1]; --j)
            swap(base, es, j, j-1, index);
}

static inline void
insertion_sort(char *base, size_t es, size_t lo, size_t hi,
                                  int (*cmp)(const void *, const void *),
                                  size_t *index) {
    for (; lo <= hi; ++lo)
        for (size_t j = lo; j > 0 && cmp(base + j*es, base + (j-1)*es) <= 0; --j)
            swap(base, es, j, j-1, index);
}

static inline void
qsort_s_stable(char *base, size_t es, size_t lo, size_t hi, size_t *index) {
    size_t mid = lo + ((hi - lo) >> 1);
    swap(base, es, lo, mid, index);
    size_t lt = lo+1, gt = hi, pivot = index[lo];
    for (;;) {
        for (; lt <= gt && index[lt] < pivot; ++lt);
        for (; lt <= gt && index[gt] > pivot; --gt);
        if (lt > gt) break;
        swap(base, es, lt++, gt--, index);
    }
    swap(base, es, lo, gt, index);
    //if (gt > lo + 16) insertion_sort_r(base, es, lo, gt-1, index);
    if (gt > lo + 1)
        qsort_s_stable(base, es, lo, gt-1, index);
//    if (hi > lt+16) insertion_sort_r(base, es, lt, hi, index);
    if (hi > lt)
        qsort_s_stable(base, es, lt, hi, index);
}

static inline void
qsort_s_core(char *base, size_t es, size_t lo, size_t hi,
             int (*cmp)(const void *, const void *), size_t *index) {
    size_t mid = lo + ((hi - lo)>>1), le = lo+1, lt = lo+1, ge = hi, gt = hi;
    swap(base, es, lo, mid, index);
    char *pivot = base + lo*es;
    int r;
    for (;;) {
        for (; lt <= gt && (r = cmp(base + lt*es, pivot)) <= 0; ++lt)
            if (r == 0) swap(base, es, le++, lt, index);
        for (; lt <= gt && (r = cmp(base + gt*es, pivot)) >= 0; --gt)
            if (r == 0) swap(base, es, gt, ge--, index);
        if (lt > gt) break;
        swap(base, es, lt++, gt--, index);
    }
    size_t n1 = min(le - lo, lt - le), n2 = min(hi - ge, ge - gt);
    vecswap(base, es, lo, lt-n1, n1, index);
    vecswap(base, es, gt+n2, ge+1, n2, index);
    if (lt > le + 1)
        qsort_s_core(base, es, lo, lo + (gt - le), cmp, index);
    if (gt + (hi - ge) > lt - (le - lo))
        qsort_s_stable(base, es, lt - (le - lo), gt + (hi - ge), index);
    if (ge > gt + 1)
        qsort_s_core(base, es, hi - (ge - lt), hi, cmp, index);
}

int
qsort_s(void *base, size_t nelem, size_t es,
        int (*compar)(const void *, const void *)) {
    size_t *index = malloc(sizeof(size_t)*nelem);
    if (index == 0) return -1;
    for (size_t i = 0; i < nelem; ++i)
        index[i] = i;
    qsort_s_core(base, es, 0, nelem - 1, compar, index);
    return 0;
}