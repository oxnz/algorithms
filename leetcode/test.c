#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

unsigned long long F[10240*2];
unsigned long long S[10240*2];

#define NX 1000000
char P[NX];

int main() {
	memset(P, 1, NX);
	P[0] = 0;
	P[1] = 0;
	P[2] = 1;
	for (int i = 2; i < NX; ++i) {
		for (int j = 2; i*j < NX; ++j) {
			P[i*j] = 0;
		}
	}

	int T;
	scanf("%d", &T);
	unsigned long long N;
	while (T--) {
		scanf("%llu", &N);
		unsigned long long root = ceill(sqrtl(N)) + 1;
		printf("root = %d\n", root);
		while (--root)
			if (P[root]) {
				printf("%llu\n", root);
				break;
			}
	}
	return 0;
}
