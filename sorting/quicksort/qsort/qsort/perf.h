//
//  perf.h
//  qsort
//
//  Created by 云心逸 on 7/28/16.
//  Copyright © 2016 Errpro,Inc. All rights reserved.
//

#ifndef perf_h
#define perf_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

static int
qsort_opt(void *base, size_t nelem, size_t es, int (*compar)(const void *,
                                                             const void *)) {
    qsort(base, nelem, es, compar);
    return 1;
}

static inline bool
sort_valid(char *base, size_t es, size_t nelem,
           int (*cmp)(const void *, const void *)) {
    for (size_t i = 1; i < nelem; ++i)
        if (cmp(base + i*es, base + (i-1)*es) < 0)
            return false;
    return true;
}

static inline bool
stable_sort_valid(char *base, size_t es, size_t nelem, size_t *index,
             int (*cmp)(const void *, const void *)) {
    int r;
    for (size_t i = 1; i < nelem; ++i)
        if ((r = cmp(base + i*es, base + (i-1)*es)) < 0 || (r == 0 && index[i] < index[i-1]))
            return false;
    return true;
}

static inline double
stirling_f(size_t n) {
    return log2(sqrt(2*M_PI*n)) + n*log2(n/M_E);
}

#endif /* perf_h */
