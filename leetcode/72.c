/*
 * Filename:	72.c
 *
 * Author:		Oxnz
 * Email:		yunxinyi@gmail.com
 * Created:		2016-07-04 14:51:16 CST
 * Last-update:	2016-07-04 14:51:16 CST
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

int minDistance(char* s1, char* s2) {
	size_t l1 = strlen(s1);
	size_t l2 = strlen(s2);
	int **m = malloc(sizeof(int*) * (l1 + 1));
	int i;
	for (i = 0; i <= l1; ++i)
		m[i] = malloc(sizeof(int) * (l2 + 1));
	for (i = 0; i <= l1; ++i)
		m[i][0] = i;
	for (i = 0; i <= l2; ++i)
		m[0][i] = i;
	int j;
	int dist;
	for (i = 1; i <= l1; ++i)
		for (j = 1; j <= l2; ++j) {
			dist = m[i-1][j-1] + (s1[i-1] == s2[j-1] ? 0 : 1);
			if (dist > m[i-1][j]+1) dist = m[i-1][j]+1;
			if (dist > m[i][j-1] + 1) dist = m[i][j-1]+1;
			m[i][j] = dist;
		}
	/*
	for (i = l1; i >= 0; --i) {
		for (j = 0; j <= l2; ++j)
			printf("%02x ", m[i][j]);
		putchar('\n');
	}
	*/
	return m[l1][l2];
}

int main(int argc, char *argv[]) {
	const char *p1 = "intention";
	const char *p2 = "execution";
	printf("minDistance = %d\n", minDistance(p1, p2));
}
