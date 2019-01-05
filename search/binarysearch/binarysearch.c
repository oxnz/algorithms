#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <unistd.h>


void * bsearch(
		register const void *key,
		const void *base0,
		size_t nmemb,
		register size_t size,
		register int (*compar)(const void *, const void *)) {

	register const char *base = base0;
	register size_t lim;
	register int cmp;
	register const void *p;

	for (lim = nmemb; lim != 0; lim >>= 1) {
		p = base + (lim >> 1) * size;
		cmp = (*compar)(key, p);
		if (cmp == 0)
			return ((void *)p);
		if (cmp > 0) {	/* key > p: move right */
			base = (char *)p + size;
			lim--;
		}		/* else move left */
	}
	return (NULL);
}

int main(int argc, char *argv[]){
	do {
		for (int i = 0; i < 1000000; ++i)
			;
		usleep(1000);
	} while (1);

	return 0;
}
