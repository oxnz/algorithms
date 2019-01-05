//
//  adt.h
//  algorithms
//
//  Created by 云心逸 on 2018/12/29.
//  Copyright © 2018 云心逸. All rights reserved.
//

#ifndef adt_h
#define adt_h

#include <iostream>
#include <algorithm>

template<typename T>
struct TreeNode {
	TreeNode *left;
	TreeNode *right;
	T value;
	TreeNode(T v) : left(nullptr), right(nullptr), value(v) {}
};

template<typename T>
struct ListNode {
	ListNode *prev;
	ListNode *next;
	T value;
	ListNode() : prev(nullptr), next(nullptr) {}
};

template<typename T>
struct ForwardListNode {
	ForwardListNode *next;
	T value;
	ForwardListNode(T v) : next(nullptr), value(v) {}
};

template<typename ForwardIterator>
void echo(ForwardIterator first, ForwardIterator last) {
	std::copy(first, last,
			  std::ostream_iterator<typename std::iterator_traits<ForwardIterator>::value_type>(std::cout, ", "));
	std::cout << std::endl;
}

template<typename Container>
void echo(Container container) {
	echo(container.begin(), container.end());
}

template<typename T>
void echo(ForwardListNode<T>* p) {
	for (; nullptr != p; p = p->next) {
		std::cout << p->value << ", ";
	}
	std::cout << std::endl;
}

template<typename Node, typename ForwardIterator>
struct node_accessor {
	node_accessor(ForwardIterator it) : m_it(it) {}
	void operator()(const Node& node) {
		*m_it++ = node.value;
	}
	ForwardIterator m_it;
};

#endif /* adt_h */
