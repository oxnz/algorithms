#include <iostream>

using namespace std;

void bs(int a[], int n) {
	for (int i = 0; i < n-1; ++i) {
		for (int j = n-1; j > i; --j) {
			if (a[j-1] > a[j])
				swap(a[j-1], a[j]);
		}
	}
}

void pa(int a[], int n) {
	for (int i = 0; i < n; ++i) {
		cout << a[i] << " ";
	}
	cout << endl;
}

int main() {
	int num[10] = {95, 45, 15, 79, 84, 51, 24, 12, 1, 100};
	pa(num, 10);
	bs(num, 10);
	pa(num, 10);
	return 0;
}
