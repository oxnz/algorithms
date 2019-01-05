/*
 * Filename:	338.c
 *
 * Author:		Oxnz
 * Email:		yunxinyi@gmail.com
 * Created:		2016-07-04 10:40:26 CST
 * Last-update:	2016-07-04 10:40:26 CST
 * Description: anchor
 *
 * Version:		0.0.1
 * Revision:	[NONE]
 * Revision history:	[NONE]
 * Date Author Remarks:	[NONE]
 *
 * License:
 * Copyright (c) 2016 Oxnz
 *
 * Distributed under terms of the [LICENSE] license.
 * [license]
 *
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int n, int* retsz) {
	*retsz = n + 1;
	int *A = malloc(sizeof(int)*(*retsz));
	A[0] = 0;
	if (n == 0) return A;
	A[1] = 1;
	if (n == 1) return A;
	int i, j, idx = 2;
	for (i = 1; i < 32; ++i) {
		for (j = 0; j < (1 << i); ++j) {
			if (idx + j > n) return A;
			A[idx + j] = A[j] + 1;
		}
		idx += j;
	}
	return A;
}

int main(int argc, char *argv[]) {
	int retsz;
	int num = 17;
	int *a = countBits(num, &retsz);
	int i;
	for (i = 0; i < retsz; ++i)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}
