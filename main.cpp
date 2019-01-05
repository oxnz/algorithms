#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <string>
#include <random>
#include <deque>
#include <list>
#include <forward_list>
#include <utility>

#include <gtest/gtest.h>

using namespace std;

template<typename ForwardIterator>
void echo(ForwardIterator first, ForwardIterator last) {
	std::copy(first, last, std::ostream_iterator<typename iterator_traits<ForwardIterator>::value_type>(std::cout, ", "));
	std::cout << "\n";
}

template<typename Container>
void echo(Container container) {
	echo(container.begin(), container.end());
}

template <typename T>
struct ListNode {
	ListNode(T v) : value(v), next(nullptr) {}
	T value;
	ListNode* next;
};

template <typename T>
ListNode<T>* reverse(ListNode<T>* head) {
	if (nullptr == head || nullptr == head->next) return head;
	ListNode<T>* p = head->next;
	ListNode<T>* next = p->next;
	p->next = head;
	head->next = reverse(next);
	return p;
}

TEST(list, reverse) {
	using Node = ListNode<int>;
	Node nodes[5] {1, 2, 3, 4, 5};
	int expected[] {2, 1, 4, 3, 5};
	for (int i = 0; i < 4; ++i) {
		nodes[i].next = &nodes[i+1];
	}
	EXPECT_TRUE(nodes[1].next == &nodes[2]);
	EXPECT_TRUE(nodes[4].next == nullptr);
	Node *lst = reverse<int>(&nodes[0]);
	int i = 0;
	for (Node* p = lst; p; p = p->next) {
		cout << p->value << ",";
		EXPECT_EQ(expected[i++], p->value);
	}
	EXPECT_EQ(i, 5);
	lst = nullptr;
	EXPECT_EQ(nullptr, reverse<int>(lst));
}

template <typename Container>
size_t find_any_peak(Container v, size_t first, size_t last) {
	if (last == first) return first;
	size_t mid = first + ((last-first)>>1);
	if (mid == first) { // 2 elem
		if (v[last] < v[first]) return first;
		else return last;
	}
	if (v[mid] < v[mid-1]) return find_any_peak(v, first, mid-1);
	return find_any_peak(v, mid, last);
}

template <typename Container>
size_t find_any_peak(Container container) {
	if (container.size() == 0) throw new invalid_argument("empty container");
	return find_any_peak(container, 0, container.size()-1);
}

TEST(find_any_peak, find_any_peak) {
	vector<int> v1 {7, 6, 5, 4, 3, 4, 3}, v2 { 1, 2, 3, 4, 5}, v3 {5, 4, 3, 2, 1};
	vector<int> v0 {};
	EXPECT_EQ(find_any_peak(v1), 0);
	EXPECT_EQ(find_any_peak(v2), 4);
	EXPECT_EQ(find_any_peak(v3), 0);
	EXPECT_THROW(find_any_peak(v0), invalid_argument);
}
