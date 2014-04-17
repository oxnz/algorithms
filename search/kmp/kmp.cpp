#include <iostream>
#include <string>

using namespace std;

void kmpx(const string& t, int next[]) {
	int j = 0, k = -1;
	next[0] = -1;
	while (j < t.length() - 1) {
		if (k == -1 || t[j] == t[k]) {
			++j;
			++k;
			next[j] = k;
		} else
			k = next[k];
	}
}

int kmp(const string& s, const string& t) {
	int next[20];
	int i = 0, j = 0;
	kmpx(t, next);
	while (i < s.length() && j < t.length()) {
		if (j == -1 || s[i] == t[j]) {
			++i;
			++j;
		} else
			j = next[j];
	}
	if (j >= t.length())
		return i - t.length();
	else
		return -1;
}

int main(int argc, char *argv[]) {
	char *s = "ababcabcacbab";
	char *t = "abcac";
	printf("%d\n", kmp(s, t));
	return 0;
}

