/*
 * Filename:	dlist.c
 *
 * Author:		Oxnz
 * Email:		yunxinyi@gmail.com
 * Created:		2015-08-18 16:17:30 CST
 * Last-update:	2015-08-18 16:17:30 CST
 * Description: anchor
 *
 * Version:		0.0.1
 * Revision:	[NONE]
 * Revision history:	[NONE]
 * Date Author Remarks:	[NONE]
 *
 * License:
 * Copyright (c) 2015 Oxnz
 *
 * Distributed under terms of the [LICENSE] license.
 * [license]
 *
 */

#include <stdio.h>
#include <stdlib.h>


struct Node {
	int val;
	struct Node *pre;
	struct Node *nxt;
};

void plist(struct Node* p) {
	while (p) {
		printf("->node(%d)", p->val);
		p = p->nxt;
	}
	putchar('\n');
}

void reverse(struct Node* p) {
	struct Node* pre = 0;
	struct Node* nxt;
	while (p) {
		nxt = p->nxt;
		pre = p->pre;
		p->pre = p->nxt;
		p->nxt = pre;
		p = nxt;
	}
}

int test_reverse(int argc, char *argv[]) {

	struct Node n1, n2, n3, n4;
	n1.val = 1;
	n2.val = 2;
	n3.val = 3;
	n4.val = 4;
	n1.pre = 0;
	n1.nxt = &n2;
	n2.pre = &n1;
	n2.nxt = &n3;
	n3.pre = &n2;
	n3.nxt = &n4;
	n4.pre = &n3;
	n4.nxt = 0;

	plist(&n1);
	reverse(&n1);
	plist(&n4);
	return 0;
}

