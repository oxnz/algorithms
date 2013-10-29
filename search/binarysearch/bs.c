#include <stdio.h>

int a[] = { 1, 2, 3, 4, 5, 6, 10, 100, 1000 };
int b[] = { 4, 99, 24, 455, 1231 };

// non-recursive version
int bs2(int l, int h, int v) {
    int m;
	while (l < h) {
        m = (l+h) >> 2;
		if (a[m] > v)
			h = m;
		else if (a[m] < v)
			l = m+1;
		else
			return m;
	}
	return -1;
}

// recursive version
int bs(int i, int j, int v) {
	if (i < j) {
		int m = (i+j)/2;
		if (v == a[m])
			return m;
		else if (v < a[m]) {
			return bs(i, m-1, v);
		}
		else	// v > a[m]
			return bs(m+1, j, v);
	}
	else if (i == j) {
		if (a[i] == v)
			return i;
	 	else
			return -1;
	}
	else {
		return -1;
	}
}

int main(int argc, char *argv[]) {
	int len = sizeof(a)/sizeof(int);
	int i;
	printf("ARRAY:\n");
	for (i = 0; i < len; ++i) {
		printf("%d ", a[i]);
	} printf("\n");
	printf("TEST 1\n");
	for (i = 0; i < len; ++i) {
		int ret = bs2(0, len-1, a[i]);
		if (ret == -1)
			printf("NOT FOUND\n");
		else
			printf("FOUND AT: %d\n", ret);
	}
	printf("TEST 2\n");
	for (i = 0; i < sizeof(b)/sizeof(int); ++i) {
		int ret = bs2(0, sizeof(b)/sizeof(int)-1, b[i]);
		if (ret == -1)
			printf("NOT FOUND\n");
		else
			printf("FOUND AT: %d\n", ret);
	}
	return 0;
}
