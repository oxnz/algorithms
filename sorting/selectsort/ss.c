#include <stdio.h>
#include "hello.h"

int t[] = { 3, 1, 4, 5, 3, 9, 2, 7 };

int swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void ss(int a[], int n) {
	int i, j;
	for (i = 0; i < n; ++i) {
		int m = i;
		for (j = i+1; j < n; ++j) {
			if (a[j] > a[m])
				m = j;	
		}
		if (a[m] != a[i])
			swap(&a[i], &a[m]);
	}
}

int main(int argc, char *argv[]) {
	printf("before sort:\n");
	int i;
	for (i = 0; i < sizeof(t)/sizeof(int); ++i) {
		printf("%d ", t[i]);
	}
	printf("\nafter sort:\n");
	ss(t, sizeof(t)/sizeof(int));
	for (i = 0; i < sizeof(t)/sizeof(int); ++i) {
		printf("%d ", t[i]);
	}
	putchar('\n');

	printf("random(100)=%ld\n", random());
	return 0;
}
