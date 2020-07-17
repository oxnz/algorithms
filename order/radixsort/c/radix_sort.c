/*
 * Filename:	radix_sort.c
 *
 * Author:		Oxnz
 * Email:		yunxinyi@gmail.com
 * Created:		2016-07-16 15:52:43 CST
 * Last-update:	2016-07-16 15:52:43 CST
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
#include <string.h>

void count_sort(char **A, int n, int offset) {
	int R = 256;
	int count[R];
	char* T[n];
	int i;
	memset(count, 0, sizeof(int)*R);
	for (i = 0; i < n; ++i)
		++count[A[i][offset]];
	for (i = 0; i < R-1; ++i)
		count[i+1] += count[i];
	for (i = n-1; i >=0; --i)
		T[--count[A[i][offset]]] = A[i];
	for (i = 0; i < n; ++i)
		A[i] = T[i];
}

void radix_sort(char **A, int n, int width) {
	for (int i = width-1; i >= 0; --i) {
		count_sort(A, n, i);
	}
}

int main() {
	char * A[] = {"DABC", "DACB", "DBAC", "DBCA", "DCAB", "DCBA",
		"CABD", "CADB", "CBAD", "CBDA", "CDAB", "CDBA",
		"BACD", "BADC", "BCAD", "BCDA", "BDAC", "BDCA",
		"ABCD", "ABDC", "ACBD", "ACDB", "ADBC", "ADCB",
		"ABCD", "BCDA", "CDAB", "DABC"
	};
	int n = sizeof(A)/sizeof(A[0]);
	radix_sort(A, n, 4);
	for (int i = 0; i < n; ++i)
		puts(A[i]);
	return 0;
}
