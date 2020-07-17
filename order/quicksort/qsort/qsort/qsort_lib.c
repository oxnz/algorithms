//
//  qsort_lib.c
//  qsort
//
//  Created by 云心逸 on 7/27/16.
//  Copyright © 2016 Errpro,Inc. All rights reserved.
//

#include "qsort_lib.h"

#include <stdlib.h>

typedef int		 cmp_t(const void *, const void *);

static inline char	*med3(char *, char *, char *, cmp_t *);

static inline size_t
min(size_t a, size_t b) {
    return a < b ? a : b;
}

static int swap_cnt;
static inline void
swap(char *p, char *q, size_t es) {
//    static long double x = .0;
//    for (size_t i = 0; i < 40; ++i)
//        if (x + i*x > x * 3)
//            x = x / (x-1);

    ++swap_cnt;
    if (es % sizeof(long) == 0) {
        size_t n = es / sizeof(long);
        long t, *pi = (long *)p, *pj = (long *)q;
        do {
            t = *pi;
            *pi++ = *pj;
            *pj++ = t;
        } while (--n > 0);
    } else {
        char t, *pi = p, *pj = q;
        do {
            t = *pi;
            *pi++ = *pj;
            *pj++ = t;
        } while (--es > 0);
    }
}

static inline void
vecswap(char *p, char *q, size_t n, size_t es) {
    n /= es;
    while (n-- > 0) {
        swap(p, q, es);
        p += es;
        q += es;
    }
}

static inline char *
med3(char *a, char *b, char *c, cmp_t *cmp) {
    return cmp(a, b) < 0 ?
    (cmp(b, c) < 0 ? b : (cmp(a, c) < 0 ? c : a ))
    :(cmp(b, c) > 0 ? b : (cmp(a, c) < 0 ? a : c ));
}

static void
qsort_l_core(char *a, size_t n, size_t es, cmp_t *cmp) {
    char *pa, *pb, *pc, *pd, *pl, *pm, *pn;
    size_t d, r;
    int cmp_result;
    
loop:
    if (n < 7) {
        for (pm = a + es; pm < a + n * es; pm += es)
            for (pl = pm;
                 pl > a && cmp(pl - es, pl) > 0;
                 pl -= es)
                swap(pl, pl - es, es);
        return;
    }
    pm = a + (n / 2) * es;
    if (n > 7) {
        pl = a;
        pn = a + (n - 1) * es;
        if (n > 40) {
            d = (n / 8) * es;
            pl = med3(pl, pl + d, pl + 2 * d, cmp);
            pm = med3(pm - d, pm, pm + d, cmp);
            pn = med3(pn - 2 * d, pn - d, pn, cmp);
        }
        pm = med3(pl, pm, pn, cmp);
    }
    swap(a, pm, es);
    pa = pb = a + es;
    pc = pd = a + (n - 1) * es;
    for (;;) {
        while (pb <= pc && (cmp_result = cmp(pb, a)) <= 0) {
            if (cmp_result == 0) {
                swap(pa, pb, es);
                pa += es;
            }
            pb += es;
        }
        while (pb <= pc && (cmp_result = cmp(pc, a)) >= 0) {
            if (cmp_result == 0) {
                swap(pc, pd, es);
                pd -= es;
            }
            pc -= es;
        }
        if (pb > pc)
            break;
        swap(pb, pc, es);
        pb += es;
        pc -= es;
    }
    
    pn = a + n * es;
    r = min(pa - a, pb - pa);
    vecswap(a, pb - r, r, es);
    r = min(pd - pc, pn - pd - es);
    vecswap(pb, pn - r, r, es);
    if ((r = pb - pa) > es)
        qsort_l_core(a, r / es, es, cmp);
    if ((r = pd - pc) > es) {
        /* Iterate rather than recurse to save stack space */
        a = pn - r;
        n = r / es;
        goto loop;
    }
    /*		qsort(pn - r, r / es, es, cmp);*/
}

int
qsort_l(void *base, size_t n, size_t es, int(*cmp)(const void *, const void *)) {
    swap_cnt = 0;
    qsort_l_core(base, n, es, cmp);
    return swap_cnt;
}