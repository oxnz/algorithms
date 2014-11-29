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

class SparseDenseSet {
public:
	SparseDenseSet(int n = 100) : n(0), capacity(n) {
		dense = new int[capacity];
		sparse = new int[capacity];
	}
	~SparseDenseSet() {
		n = 0;
		delete[] dense;
		delete[] sparse;
	}
	void clear() {
		n = 0;
	}
	bool contain(int k) {
		if (k >= capacity || n <= 0)
			return false;
		int i = sparse[k];
		return i < n && dense[i] == k;
	}
	bool insert(int k) {
		if (k >= capacity || contain(k))
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
		printf("count: %d/%d\nelems:\n\t", n, capacity);
		for (int i = 0; i < n; ++i)
			printf("[%d]", dense[i]);
		printf("\ndense:\n\t");
		for (int i = 0; i < capacity; ++i)
			printf("[%d]", dense[i]);
		printf("\nsparse:\n\t");
		for (int i = 0; i < capacity; ++i)
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
	int capacity;
};

int main(int argc, char *argv[]) {
	int sep[] = {8, 9, 3, 2};
	SparseDenseSet s(10);
	s.inspect();
	for (int n : sep) {
		printf("contain %d = %s\n", n, s.contain(n) ? "yes" : "no");
		printf("insert %d %s\n", n, s.insert(n) ? "success" : "failure");
		printf("contain %d = %s\n", n, s.contain(n) ? "yes" : "no");
	}
	s.inspect();
	for (int i = 0; i < 10; ++i) {
		printf("contain %d = %s\n", i, s.contain(i) ? "yes" : "no");
	}
	s.foreach([](int n)->void * { printf("[%d]", n); return 0; });
	putchar('\n');
	s.remove(2);
	s.remove(3);
	for (int i = 0; i < 10; ++i) {
		printf("contain %d = %s\n", i, s.contain(i) ? "yes" : "no");
	}
	s.clear();
	s.inspect();
	s.insert(3);
	s.insert(7);
	s.insert(4);
	s.inspect();
	s.xchg(3, 7);
	printf("after swap(3, 7):\n");
	s.inspect();
	s.xchg(3, 4);
	printf("after swap(3, 4):\n");
	s.inspect();

	return 0;
}
