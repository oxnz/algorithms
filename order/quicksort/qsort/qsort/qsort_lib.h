//
//  qsort_lib.h
//  qsort
//
//  Created by 云心逸 on 7/27/16.
//  Copyright © 2016 Errpro,Inc. All rights reserved.
//

#ifndef qsort_lib_h
#define qsort_lib_h

#include <stdio.h>

int
qsort_l(void *base, size_t n, size_t es, int(*)(const void *, const void *));

#endif /* qsort_lib_h */
