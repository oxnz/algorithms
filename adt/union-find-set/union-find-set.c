/*
 * Filename:	union-find-set.c
 *
 * Author:		Oxnz
 * Email:		yunxinyi@gmail.com
 * Created:		2016-07-13 00:37:25 CST
 * Last-update:	2016-07-13 00:37:25 CST
 * Description: anchor
 *
 * Version:		0.0.1
 * Revision:	[NONE]
 * Revision history:	[NONE]
 * Date Author Remarks:	[NONE]
 *
 * License:
 * Copyright (c) 2016 Oxnz
 *
 * Ref: https://www.douban.com/note/210478218/
 * Distributed under terms of the [LICENSE] license.
 * [license]
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

inline int min(int a, int b) {
	return a < b ? a : b;
}

inline int max(int a, int b) {
	return a > b ? a : b;
}

struct union_find_set {
	size_t nelement;
	size_t ncomponent;
	int *parents;
	int *ranks;
};

int uf_set_init(struct union_find_set *s, int n) {
	s->nelement = n;
	s->ncomponent = n;
	s->parents = malloc(sizeof(int) * n);
	s->ranks = malloc(sizeof(int) * n);
	if (s->parents == 0 || s->ranks == 0)
		return -1;
	for (int i = 0; i < n; ++i) {
		s->parents[i] = i;
	}
	memset(s->ranks, 0, sizeof(int) * n);
	return 0;
}

int uf_set_destroy(struct union_find_set *s) {
	free(s->parents);
	free(s->ranks);
	s->parents = 0;
	s->ranks = 0;
	s->nelement = 0;
	s->ncomponent = 0;
	return 0;
}

int uf_set_heuristic_find(struct union_find_set *s, int i) {
	int p = s->parents[i];
	if (i != p) {
		p = s->parents[i] = uf_set_heuristic_find(s, p);
	}
	return p;
}

int uf_set_find(struct union_find_set *s, int i) {
	while (i != s->parents[i])
		i = s->parents[i];
	return i;
}

void uf_set_union(struct union_find_set *s, int i, int j) {
	int pi = uf_set_heuristic_find(s, i);
	int pj = uf_set_heuristic_find(s, j);
	if (pi != pj) {
		s->parents[pi] = pj;
		--s->ncomponent;
	}
}

void uf_set_heuristic_union(struct union_find_set *s, int i, int j) {
	int pi = uf_set_find(s, i);
	int pj = uf_set_find(s, j);
	if (pi != pj) {
		--s->ncomponent;
		if (s->ranks[pi] < s->ranks[pj]) {
			s->parents[pi] = pj;
		} else {
			s->parents[pj] = pi;
			if (s->ranks[pi] == s->ranks[pj]) {
				++s->ranks[pi];
			}
		}
	}
}

bool uf_set_connected(struct union_find_set *s, int i, int j) {
	return uf_set_find(s, i) == uf_set_find(s, j);
}

void uf_set_echo(struct union_find_set *s) {
	for (int i = 0; i < s->nelement; ++i) {
		printf("[%d->%d:%d]", i, s->parents[i], s->ranks[i]);
	}
	printf("\n");
}

int test_uf(int argc, char *argv[]) {
	struct union_find_set s;
	int N, p, q;
	scanf("%d", &N);
	uf_set_init(&s, N);
	while (N--) {
		scanf("%d %d", &p, &q);
		uf_set_heuristic_union(&s, p, q);
		//uf_set_union(&s, p, q);
	}
	printf("n components = %ld\n", s.ncomponent);
	//uf_set_echo(&s);
	uf_set_destroy(&s);

	return 0;
}
