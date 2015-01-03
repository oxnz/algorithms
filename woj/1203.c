/*
 * Filename:	1203.c
 *
 * Author:		Oxnz
 * Email:		yunxinyi@gmail.com
 * Created:		[2014-12-22 22:53:03 CST]
 * Last-update:	2014-12-22 22:53:03 CST
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
	while (1) {
	int n;
	if (scanf("%d", &n) != 1)
		break;
	int c;
	scanf("%d", &c);
	int o = 1;
	int t;
	while (--n) {
		scanf("%d", &t);
		if (t == c) {
			++o;
		} else {
			if (--o) {
			} else {
				c = t;
				o = 1;
			}
		}
	}
	printf("%d\n", c);
	}

	return 0;
}
