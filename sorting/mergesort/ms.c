#include <stdio.h>

int a[] = { 1, 3, 5, 7, 9 };
int b[] = { 0, 2, 4, 6, 8 };
int c[10];

void pa(int a[], int n) {
	int i;
	for (i = 0; i < n; ++i)
		printf("%d ", a[i]);
	putchar('\n');
}

int ms(int a[], int an, int b[], int bn, int c[]) {
	int i = 0; int n = an + bn;
	int ai = 0;
	int bi = 0;
	while (i < n) {
		if (ai > an-1)
			c[i++] = b[bi++];
		else if (bi > bn-1)
			c[i++] = a[ai++];
		else {
			if (a[ai] >= b[bi])
				c[i++] = b[bi++];
			else
				c[i++] = a[ai++];
		}
	}
}

int main(int argc, char *argv[]) {
	pa(a, 5); pa(b, 5);
	ms(a, 5, b, 5, c);
	pa(c, 10);
	return 0;
}
