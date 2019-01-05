/*
 * Filename:	pi.c
 *
 * Author:		Oxnz
 * Email:		yunxinyi@gmail.com
 * Created:		2016-07-28 17:53:51 CST
 * Last-update:	2016-07-28 17:53:51 CST
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
#include <time.h>

long double
pi(size_t ntimes) {
	size_t cnt = 0;
	const unsigned long M = 1<<31;
	const unsigned long mod = M-1, prod = M*M;
	unsigned long x, y;
	for (size_t i = 0; i < ntimes; ++i) {
		x = random() & mod;
		y = random() & mod;
		if (x*x + y*y < prod)
			++cnt;
	}
	return 4.0*cnt/ntimes;
}

int main() {
	srand(time(0));
	for (int i = 0; i < 30; ++i)
		printf("%.40Lf\n", pi(1<<i));
	return 0;
}
