/*
 * Filename:	Subsets.cc
 *
 * Author:		Oxnz
 * Email:		yunxinyi@gmail.com
 * Created:		[2014-12-02 10:29:22 CST]
 * Last-update:	2014-12-02 10:29:22 CST
 * Description: anchor
 *
 * Version:		0.0.1
 * Revision:	[NONE]
 * Revision history:	[NONE]
 * Date Author Remarks:	[NONE]
 *
 * License: 
 * Copyright (c) 2013 Oxnz
 *
 * Distributed under terms of the [LICENSE] license.
 * [license]
 *
 */

#include <iostream>

using namespace std;

int pow(int a, int n) {
	if (n == 1)
		return a;
	else
		return pow(a, n/2) * pow(a, n/2) * (n % 2 ? a : 1);
}

bool next(bool *mask, int n) {
	int i = 0;
	for (; i < n && mask[i]; ++i)
		mask[i] = false;
	if (i == n)
		return false;
	mask[i] = true;
	return true;
}

void psubset(int *a, bool *mask, int n) {
	cout << "[";
	for (int i = 0; i < n; ++i)
		if (mask[i])
			cout << "[" << a[i] << "]";
	cout << "]" << endl;
}

int main(int argc, char *argv[]) {
	int a[] = {3, 1, 2};
	int n = sizeof(a)/sizeof(a[0]);
	bool* mask = new bool[n];
	for (int i = 0; i < n; ++i)
		mask[i] = 0;
	psubset(a, mask, n);
	while (next(mask, n))
		psubset(a, mask, n);
	delete[] mask;

	return 0;
}
