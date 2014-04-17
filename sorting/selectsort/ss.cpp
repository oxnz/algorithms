#include <iostream>

using namespace std;

#define pa(a, n) do { \
	for (int i = 0; i < n; ++i) \
		cout << a[i] << " "; \
	cout << endl; \
} while (0)

int t[] = { 3, 1, 4, 5, 3, 9, 2, 7 };

void ss(int a[], int n) {
	for (int i = 0; i < n; ++i) {
		int min = i;
		for (int j = i+1; j < n; ++j) {
			if (a[j] < a[min])
				min = j;	
		}
		if (min != i)
			swap(a[i], a[min]);
	}
}

int main(int argc, char *argv[]) {
	int n = sizeof(t)/sizeof(t[0]);
	pa(t, n);
	ss(t, n);
	pa(t, n);
	return 0;
}
