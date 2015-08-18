/*
 * Filename:	test.c
 *
 * Author:		Oxnz
 * Email:		yunxinyi@gmail.com
 * Created:		[2015-05-20 18:18:44 CST]
 * Last-update:	2015-05-20 18:18:44 CST
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

struct node {
	int val;
	struct node* next;
};

void plist(struct node* p) {
	while (p) {
		printf("->node(%d)", p->val);
		p = p->next;
	}
	printf("\n");
}

int main() {
	struct node n1, n2, n3, n4;
	n1.val = 1;
	n2.val = 2;
	n3.val = 3;
	n4.val = 4;
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = NULL;


	struct node* p = &n1;
	plist(p);
	struct node* pre = NULL;
	struct node* nxt = 0;
	while (p) {
		nxt = p->next;
		p->next = pre;
		pre = p;
		p = nxt;
	}
	plist(&n4);

	return 0;
}
