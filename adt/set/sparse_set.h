/*
 * Filename:	sparse-dense.c
 *
 * Author:		Oxnz
 * Email:		yunxinyi@gmail.com
 * Created:		[2014-11-29 17:47:40 CST]
 * Last-update:	2014-11-29 17:47:40 CST
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

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

class SparseSet {
public:
	SparseSet(int n = 100) : n(0), c(n) {
		dense = new int[c];
		sparse = new int[c];
	}
	~SparseSet() {
		n = 0;
		delete[] dense;
		delete[] sparse;
	}
	int capacity() {
		return c;
	}
	int count() {
		return n;
	}
	bool empty() {
		return 0 == n;
	}
	void clear() {
		n = 0;
	}
	bool contain(int k) {
		if (k >= c || n <= 0)
			return false;
		int i = sparse[k];
		return i < n && dense[i] == k;
	}
	bool insert(int k) {
		if (k >= c || contain(k))
			return false;
		sparse[k] = n;
		dense[n] = k;
		++n;
		return true;
	}
	bool remove(int k) {
		if (contain(k)) {
			--n;
			int topval = dense[n];
			if (k != topval)
				xchg(k, topval);
			return true;
		}
		return false;
	}
	void foreach(void *(*func)(int)) {
		for (int i = 0; i < n; ++i) {
			func(dense[i]);
		}
	}
	void inspect(void) {
		printf("count: %d/%d\nelems:\n\t", n, c);
		for (int i = 0; i < n; ++i)
			printf("[%d]", dense[i]);
		printf("\ndense:\n\t");
		for (int i = 0; i < c; ++i)
			printf("[%d]", dense[i]);
		printf("\nsparse:\n\t");
		for (int i = 0; i < c; ++i)
			printf("[%d]", sparse[i]);
		printf("\n");
	}
//private:
	void xchg(int a, int b) {
		if (contain(a) && contain(b) && a != b) {
			int i = sparse[a];
			int j = sparse[b];
			swap(sparse[a], sparse[b]);
			swap(dense[i], dense[j]);
		}
	}
private:
	int *dense;
	int *sparse;
	int n;
	int c;
};
