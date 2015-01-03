/*
 * Filename:	1202.c
 *
 * Author:		Oxnz
 * Email:		yunxinyi@gmail.com
 * Created:		[2014-12-22 22:44:56 CST]
 * Last-update:	2014-12-22 22:44:56 CST
 * Description: anchor
 *
 * Version:		0.0.1
 * Revision:	[NONE]
 * Revision history:	[NONE]
 * Date Author Remarks:	[NONE]
 *
 * License: 
 * Copyright (c) 2013 Oxnz
 *
 * Distributed under terms of the [LICENSE] license.
 * [license]
 *
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	scanf("%d", &n);
	int s;
	scanf("%d", &s);
	int t;
	int i;
	for (i = 1; i < 2*n+1; ++i) {
		scanf("%d", &t);
		s ^= t;
	}
	printf("%d\n", s);

	return 0;
}
