//
//  list.hpp
//  algorithms
//
//  Created by 云心逸 on 2019/1/7.
//  Copyright © 2019 云心逸. All rights reserved.
//

#ifndef list_h
#define list_h

#include <algorithm>
#include <iterator>

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
public:
	ForwardListNode(T v) : next(nullptr), value(v) {}
};

/*
template <typename NodePtr>
class ListIterator {
	NodePtr m_ptr;
public:
	using iterator_category = std::forward_iterator_tag;

	ListIterator() noexcept : m_ptr(nullptr) {}

	reference operator*() const {
		return m_ptr->value;
	}

	pointer operator->() const {
		return std::pointer_traits<pointer>::pointer_to(m_ptr->value);
	}

	ListIterator& operator++() {
		m_ptr = m_ptr->next;
		return *this;
	}

	ListIterator operator++(int) {
		ListIterator it(*this);
		++(*this);
		return it;
	}

	friend bool operator==(const ListIterator& lhs, const ListIterator& rhs) {
		return lhs.m_ptr == rhs.m_ptr;
	}
	friend bool operator!=(const ListIterator& lhs, const ListIterator& rhs) {
		return !(lhs.m_ptr == rhs.m_ptr);
	}
};
*/

namespace list {
template <typename T, typename Compare>
ForwardListNode<T>* sort(ForwardListNode<T>* root, Compare cmp = std::less<T>()) {
	if (nullptr == root) return root;
	auto unsorted = root->next;
	auto sorted = root;
	sorted->next = nullptr;
	for (; unsorted;) {
		auto cur = unsorted;
		unsorted = unsorted->next; // get one
		cur->next = nullptr;
		auto pre = sorted, p = sorted;
		while (p && cmp(p->value, cur->value)) {
			pre = p;
			p = p->next;
		}
		if (cmp(pre->value, cur->value)) {
			cur->next = pre->next;
			pre->next = cur;
		} else {
			cur->next = sorted;
			sorted = cur;
		}
	}
	return sorted;
}

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

template <typename T>
ForwardListNode<T>* reverse2(ForwardListNode<T>* head) {
	if (nullptr == head || nullptr == head->next) return head;
	ForwardListNode<T>* p = head->next;
	ForwardListNode<T>* next = p->next;
	p->next = head;
	head->next = reverse2(next);
	return p;
}

template <typename T>
ForwardListNode<T>* reverse_n(ForwardListNode<T>* head, size_t step) {
	auto prev = head, p = head;
	auto n = step+1;
	for (; --n > 0 && nullptr != p; p = p->next)
		prev = p;
	if (step < 2 || n > 0) return head;
	prev->next = nullptr;
	prev = reverse(head);
	head->next = reverse_n(p, step);
	return prev;
}
}

#endif /* list_h */
