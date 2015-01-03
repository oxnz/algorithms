/*
     Filename: max-sub-array.c
  Description: 

      Version: 0.1
      Created: 2014-09-10 22:38:11
  Last-update: 2014-09-13 02:48:42
     Revision: None

       Author: Oxnz
        Email: yunxinyi@gmail.com

Revision history:
	Date Author Remarks
*/

#include <stdio.h>

int maxsum(int a[], int n) {
	int sum = 0;
	int b = 0;
	int i;
	for (i = 0; i < n; ++i) {
		if (b < 0)
			b = a[i];
		else
			b += a[i];
		if (sum < b)
			sum = b;
	}
	return sum;
}

// a short version for maxsum
int ms(int a[], int n) {
	int sum = 0, b = 0, i = -1;
	while (++i < n) {
		b = b < 0 ? a[i] : b + a[i];
		if (sum < b)
			sum = b;
	}
	return sum;
}

int main() {
	int a[8] = {1, -2, 3, 10, -4, 7, 2, -5};
	printf("max sum = %d\n", maxsum(a, 8));
	printf("max sum = %d\n", ms(a, 8));

	return 0;
}
