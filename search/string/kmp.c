/*
 * ref: http://www.computing.dcu.ie/~humphrys/Notes/String/kmp.html
 * https://en.wikibooks.org/wiki/Algorithm_Implementation/String_searching/Knuth-Morris-Pratt_pattern_matcher
 */
#include <stdio.h>
#include <string.h>

void echo_array(int *a, size_t n) {
	for (size_t i = 0; i < n; ++i)
		printf("%d ", a[i]);
	printf("\n");
}

void fail_func(const char* p, int *next) {
	next[0] = 0;
	for (int i = 1, j = 0; *(p+i);)
		if (p[j] == p[i])
			next[i++] = ++j;
		else {
			if (j > 0)
				j = next[j-1];
			else {
				next[i++] = 0;
			}
		}
}

/*
 * improved version
 */
void fail_func_p(const char* p, int *next) {
	next[0] = 0;
	for (int i = 1, j = 0; *(p+i);)
		if (p[j] == p[i])
			//next[i++] = ++j;
			next[i++] = next[j++];
		else {
			if (j > 0)
				j = next[j-1];
			else {
				next[i++] = 0;
			}
		}
}

int search(const char* s, const char* t) {
	size_t m = strlen(t);
	int next[m];
	fail_func(t, next);
	int i = 0, j = 0;
	while (*(s+i) && *(t+j)) {
		printf("i = %d, j = %d\n", i, j);
		if (s[i] == t[j]) {
			++i;
			++j;
		} else {
			if (j == 0)
				++i;
			else
				j = next[j-1];
		}
	}
	if (t[j] == '\0')
		return i - m;
	else
		return -1;
}

void fail_func2(const char *p, int *next) {
	next[1] = 0;
	for (int i = 1, j = 0; *(p+i);) {
		if (j == 0 || p[i] == p[j])
			next[++i] = ++j;
		else
			j = next[j];
	}
}

int search2(const char *s, const char *p) {
	size_t m = strlen(p);
	int next[m];
	fail_func2(p, next);
	int i = 1, j = 1;
	while (*(s+i) && *(p+j))
		if (j == 0 || s[i] == p[j]) { ++i; ++j; }
		else j = next[j];
	if (*(p+j)) return -1;
	else return i - m;
}

int main(int argc, char *argv[]) {
	const char *s = "ababcabcacbab";
	const char *p = "aaaab";
	int m = strlen(p);
	int next[m];
	fail_func_p(p, next);
	echo_array(next, m);
	int idx = search(s, p);
	printf("%s %s\n", s, idx == -1 ? "not found" : s+idx);

	return 0;
}
