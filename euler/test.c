/*
 * Filename:	test.c
 *
 * Author:		Oxnz
 * Email:		yunxinyi@gmail.com
 * Created:		2016-07-28 12:35:11 CST
 * Last-update:	2016-07-28 12:35:11 CST
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
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int T;
	unsigned long long N;
	scanf("%d", &T);
	while (T--) {
		scanf("%llu", &N);
		while (N % 2 == 0)
			N >>= 1;
		if (N == 1)
			printf("2\n");
		else {
			size_t i = 3, root = 2 + sqrt(N);
			for (; i < root; i += 2)
				if (N % i == 0) {
					N /= i;
					if (N <= 2)
						break;
					i = 3;
				}
			printf("%llu\n", N > 2 ? N : i);
		}
	}
	return 0;
}
