/*
 * Filename:	shift.c
 *
 * Author:		Oxnz
 * Email:		yunxinyi@gmail.com
 * Created:		2016-07-23 22:45:37 CST
 * Last-update:	2016-07-23 22:45:37 CST
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

void shift(const char *p, int i) {
	int ch = *p;
	for (; ch; ch = *++p) {
		if (ch >= 'a' && ch <= 'z')
			ch += 'A' - 'a';
		if (ch >= 'A' && ch <= 'Z')
			printf("%c", 'A' + (ch - 'A' + i) % 26);
		else
			printf("%c", ch);
	}
	printf("\n");
}

void decrypt(const char *p) {
	for (int i = 1; i < 26; ++i)
		shift(p, i);
}

int main(int argc, char *argv[]) {
	int buflen = 1024;
	char buf[buflen];
	scanf("%s", buf);
	decrypt(buf);

	return 0;
}
