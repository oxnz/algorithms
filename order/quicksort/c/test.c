/*
 * Filename:	test.c
 *
 * Author:		Oxnz
 * Email:		yunxinyi@gmail.com
 * Created:		2016-07-05 22:22:55 CST
 * Last-update:	2016-07-05 22:22:55 CST
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

int cmp(const void *a, const void *b) {
	return *(char *)a - *(char *)b;
}

int main(int argc, char *argv[]) {
	int n = 1<<30;
	char *p = malloc(sizeof(char) * n);
	if (!p) {
		perror("calloc");
		return -1;
	}
	qsort(p, n, sizeof(char), cmp);
	return 0;
}

