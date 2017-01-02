//
//  qsort.h
//  qsort
//
//  Created by 云心逸 on 7/25/16.
//  Copyright © 2016 Errpro,Inc. All rights reserved.
//

#ifndef qsort_h
#define qsort_h

#include <stdio.h>

int qsort_s(void *base, size_t nelem, size_t es, int (*compar)(const void *,
                                                                const void *));

#endif /* qsort_h */
