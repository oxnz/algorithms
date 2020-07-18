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

static int swap_cnt;
static void
swap(char *base, size_t es, size_t i, size_t j, size_t *index) {
//    static long double x = .0;
//    for (size_t i = 0; i < 40; ++i)
//        if (x + i*x > x * 3)
//            x = x / (x-1);

    ++swap_cnt;
    size_t t = index[i];
    index[i] = index[j];
    index[j] = t;
    if (es % sizeof(long) == 0) {
        size_t n = es / sizeof(long);
        long *pi = (long *)(base + i*es), *pj = (long *)(base + j*es);
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
    for (++lo; lo <= hi; ++lo)
        for (size_t j = lo; j > 0 && index[j] < index[j-1]; --j)
            swap(base, es, j, j-1, index);
}

static inline void
insertion_sort(char *base, size_t es, size_t lo, size_t hi,
                                  int (*cmp)(const void *, const void *),
                                  size_t *index) {
    int r;
    for (++lo; lo <= hi; ++lo)
        for (size_t j = lo; j > 0 && ((r = cmp(base + j*es, base + (j-1)*es)) < 0
                                      || (r == 0 && index[j] < index[j-1])); --j)
            swap(base, es, j, j-1, index);
}

static inline size_t
med3_s(size_t a, size_t b, size_t c) {
    return a < b ? (b < c ? b : a < c ? c : a) : (a < c ? a : b > c ? b : c);
}

static inline size_t
med3(char *base, size_t es, size_t i, size_t j, size_t k,
       int (*cmp)(const void *, const void *)) {
    return cmp(base + i*es, base + j*es) < 0 ?
    (cmp(base + j*es, base + k*es) < 0 ? j : (cmp(base + i*es, base + k*es) < 0 ? k : i))
    :(cmp(base + j*es, base + k*es) > 0 ? j : (cmp(base + i*es, base + k*es) < 0 ? i : k));
}

static void
qsort_s_index(char *base, size_t es, size_t lo, size_t hi, size_t *index) {
    size_t mid, n;
    
    if (hi - lo < 6) {
        for (++lo; lo <= hi; ++lo)
            for (size_t j = lo; j > 0 && index[j] < index[j-1]; --j)
                swap(base, es, j, j-1, index);
        return;
    }
    n = hi - lo + 1;
    if (n <= 40) mid = med3_s(index[lo], index[lo + (n >> 1)], index[hi]);
    else {
        size_t d = n >> 3;
        mid = med3_s(med3_s(index[lo], index[lo + d], index[lo + (d << 1)]),
                     med3_s(index[(n>>1) - d], index[n>>1], index[(n>>1) + d]),
                     med3_s(index[hi - (d << 1)], index[hi - d], index[hi]));
    }
    if (lo != mid) swap(base, es, lo, mid, index);
    size_t lt = lo+1, gt = hi, pivot = index[lo];
    for (;; ++lt, --gt) {
        for (; lt <= gt && index[lt] < pivot; ++lt);
        for (; lt <= gt && index[gt] > pivot; --gt);
        if (lt > gt) break;
        if (lt != gt) swap(base, es, lt, gt, index);
    }
    if (lo != gt) swap(base, es, lo, gt, index);
    if (gt > lo + 1)
        qsort_s_index(base, es, lo, gt-1, index);
    if (hi > lt) {
        qsort_s_index(base, es, lt, hi, index);
    }
}

static inline void
qsort_s_3way(char *base, size_t es, size_t lo, size_t hi,
             int (*cmp)(const void *, const void *), size_t *index) {
    size_t n, mid, le, lt, ge, gt;
    int r;
    char *pivot;

    n = hi - lo + 1;
    if (n <= 40) { mid = med3(base, es, lo, lo + (n>>1), hi, cmp); }
    else {
        size_t d = n >> 3;
        mid = med3(base, es, med3(base, es, lo, lo + d, lo + (d<<1), cmp),
                   med3(base, es, (n>>1)-d, n>>1, (n>>1) + d, cmp),
                   med3(base, es, hi - (d<<1), hi-d, hi, cmp), cmp);
    }
    le = lt = lo+1;
    ge = gt = hi;
    if (lo != mid) swap(base, es, lo, mid, index);
    pivot = base + lo*es;
    for (;;) {
        for (; lt <= gt && (r = cmp(base + lt*es, pivot)) <= 0; ++lt)
            if (r == 0) {
                if (le != lt) swap(base, es, le, lt, index);
                ++le;
            }
        for (; lt <= gt && (r = cmp(base + gt*es, pivot)) >= 0; --gt)
            if (r == 0) {
                if (gt != ge) swap(base, es, gt, ge, index);
                --ge;
            }
        if (lt > gt) break;
        swap(base, es, lt++, gt--, index);
    }
    size_t n1 = min(le - lo, lt - le), n2 = min(hi - ge, ge - gt);
    vecswap(base, es, lo, lt - n1, n1, index);
    vecswap(base, es, lt, hi - n2 + 1, n2, index);
    if (lt > le + 1)
        qsort_s_3way(base, es, lo, lo + (gt - le), cmp, index);
    if (gt + (hi - ge) > lt - (le - lo) + 6)
        qsort_s_index(base, es, lt - (le - lo), gt + (hi - ge), index);
    else if (gt + (hi - ge) > lt - (le - lo))
        insertion_sort_r(base, es, lt - (le - lo), gt + (hi - ge), index);
    if (ge > gt + 1) {
        qsort_s_3way(base, es, hi - (ge - lt), hi, cmp, index);
    }
}

static inline void
qsort_s_2way(char *base, size_t es, size_t lo, size_t hi,
             int (*cmp)(const void *, const void *), size_t *index) {
    size_t n, mid, lt, gt;
    int r;
    char *pivot;
    
    n = hi - lo + 1;
    if (n < 8) {
        insertion_sort(base, es, lo, hi, cmp, index);
        return;
    }
    if (n <= 40) { mid = med3(base, es, lo, lo + (n>>1), hi, cmp); }
    else {
        size_t d = n >> 3;
        mid = med3(base, es, med3(base, es, lo, lo + d, lo + (d<<1), cmp),
                   med3(base, es, (n>>1)-d, n>>1, (n>>1) + d, cmp),
                   med3(base, es, hi - (d<<1), hi-d, hi, cmp), cmp);
    }
    lt = lo+1;
    gt = hi;
    if (lo != mid) swap(base, es, lo, mid, index);
    pivot = base + lo*es;
    for (;;) {
        for (; lt <= gt && ((r = cmp(base + lt*es, pivot)) < 0
                            || (r == 0 && index[lt] < index[lo])); ++lt)
            ;
        for (; lt <= gt && ((r = cmp(base + gt*es, pivot)) > 0
                            || (r == 0 && index[gt] > index[lo])); --gt)
            ;
        if (lt > gt) break;
        swap(base, es, lt++, gt--, index);
    }
    swap(base, es, lo, gt, index);
    if (gt > lo + 1)
        qsort_s_2way(base, es, lo, gt-1, cmp, index);
    if (hi > lt) {
        qsort_s_2way(base, es, lt, hi, cmp, index);
    }
}

static int
qsort_stable(char *base, size_t nelem, size_t es,
             int (*cmp)(const void *, const void *),
             int way) {
    swap_cnt = 0;
    size_t *index = (size_t *)malloc(sizeof(size_t)*nelem);
    if (index == 0) return -1;
    for (size_t i = 0; i < nelem; ++i)
        index[i] = i;
    if (way == 2) {
        qsort_s_2way(base, es, 0, nelem-1, cmp, index);
    } else {
        qsort_s_3way(base, es, 0, nelem-1, cmp, index);
    }
    free(index);
    return swap_cnt;
}


int
qsort_s2(void *base, size_t nelem, size_t es,
         int (*compar)(const void *, const void *)) {
    return qsort_stable(base, nelem, es, compar, 2);
}

int
qsort_s3(void *base, size_t nelem, size_t es,
        int (*compar)(const void *, const void *)) {
    return qsort_stable(base, nelem, es, compar, 3);
}

