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

#include <iostream>
#include "adt.h"

using namespace std;

template <typename T>
ForwardListNode<T>* reverse(ForwardListNode<T> *head) {
	if (nullptr == head) return head;
	typedef ForwardListNode<T> Node;
	Node *pre = head;
	Node *p = pre->next;
	Node *nxt;
	while (nullptr != p) {
		nxt = p->next;
		p->next = pre;
		pre = p;
		p = nxt;
	}
	head->next = nullptr;
	return pre;
}

template <typename T>
void list_insert(ForwardListNode<T>& list, ForwardListNode<T>& node) {
	node.next = list.next;
	list.next = &node;
}

template <typename T>
void list_erase(ForwardListNode<T>& list, ForwardListNode<T>* p) {
}

int test_list() {
	ForwardListNode<int> list(0);
	ForwardListNode<int> nodes[10]{1,2,3,4,5,6,7,8,9,10};
	for (int i = 0; i < 10; ++i) {
		nodes[i].value = i+1;
		list_insert(list, nodes[i]);
	}

	echo(&list);
	ForwardListNode<int> *p = reverse(&list);
	echo(p);
	list_erase(list, &nodes[4]);
	list_erase(list, &nodes[6]);
	list_erase(list, &nodes[8]);
	echo(reverse(p));

	return 0;
}
