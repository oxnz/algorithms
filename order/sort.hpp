//
//  sort.hpp
//  algorithms
//
//  Created by 云心逸 on 2019/1/7.
//  Copyright © 2019 云心逸. All rights reserved.
//

#ifndef sort_hpp
#define sort_hpp

#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <type_traits>
#include "../adt/adt.hpp"

namespace sort {

	template <typename BidirectionalIterator, typename Compare>
	void bubble_sort(BidirectionalIterator first, BidirectionalIterator last, Compare cmp) {
		for (BidirectionalIterator cur = first; cur != last; ++cur)
			for (BidirectionalIterator it = last-1; it != cur; --it)
				if (cmp(*it, *(it-1))) iter_swap(it, it-1);
	}

	template <typename BidirectionalIterator>
	void bubble_sort(BidirectionalIterator first, BidirectionalIterator last) {
		bubble_sort(first, last, std::less<typename std::iterator_traits<BidirectionalIterator>::value_type>());
	}

	template <typename RandomAccessIterator, typename Compare>
	void insertion_sort(RandomAccessIterator first, RandomAccessIterator last, Compare cmp) {
		for (RandomAccessIterator it = first; it != last; ++it) {
			for (RandomAccessIterator cur = it; cur != first && cmp(*cur, *(cur-1)); --cur)
				iter_swap(cur-1, cur);
		}
	}

	void insertion_sort2(int a[], int n) {
		int t;
		for (int i = 1; i < n; ++i) {
			t = a[i];
			int j = i;
			for (; j > 0 && a[j] > t; --j)
				a[j] = a[j-1];
			a[j] = t;
		}
	}
	
	template <typename RandomAccessIterator>
	void insertion_sort(RandomAccessIterator first, RandomAccessIterator last) {
		insertion_sort(first, last, std::less<typename std::iterator_traits<RandomAccessIterator>::value_type>());
	}

template <typename ForwardIterator, typename Compare>
void selection_sort(ForwardIterator first, ForwardIterator last, Compare cmp) {
    for (; first != last; ++first) {
        ForwardIterator min_iter = first, it = first;
        for (; it != last; ++it)
            if (cmp(*it, *min_iter)) min_iter = it;
        if (it != min_iter) std::iter_swap(first, min_iter);
    }
}

template <typename ForwardIterator>
void selection_sort(ForwardIterator first, ForwardIterator last) {
    selection_sort(first, last, std::less<typename std::iterator_traits<ForwardIterator>::value_type>());
}

template <typename T, typename RandomAccessIterator, typename OutputIterator, typename Compare>
void merge(RandomAccessIterator first, RandomAccessIterator last, OutputIterator result, Compare cmp) { // k-merge/ cmp = greater<T>()
    auto iter_cmp = [&cmp](auto& p1, auto& p2) { return cmp(*p1.first, *p2.first); };
    last = std::partition(first, last, [](const auto& p){ return p.first != p.second; });
    std::make_heap(first, last, iter_cmp);
    while (first != last) {
        std::pop_heap(first, last, iter_cmp);
        auto it = last-1;
        *result++ = *(it->first++);
        if (it->first != it->second) { // pair<begin, end>
            std::push_heap(first, last, iter_cmp);
        } else --last;
    }
}

template <typename T>
ForwardListNode<T>* merge_sort_heap(std::vector<ForwardListNode<T>*>& v) {
    using pointer = ForwardListNode<T>*;
    pointer root = nullptr, p = nullptr;
    v.assign(v.begin(), partition(v.begin(), v.end(), [](const pointer p){ return nullptr != p; }));
    auto cmp = [](const pointer p, const pointer q) {
        return p->val > q->val;
    };
    std::make_heap(v.begin(), v.end(), cmp);
    while (!v.empty()) {
        std::pop_heap(v.begin(), v.end(), cmp);
        if (root == nullptr) { p = root = v.back(); }
        else { p->next = v.back(); p = p->next; }
        if (v.back()->next) {
            v.back() = v.back()->next;
            push_heap(v.begin(), v.end(), cmp);
        } else v.pop_back();
    }
    return root;
}

template <typename T>
ForwardListNode<T>* merge_sort_pq(std::vector<ForwardListNode<T>*>& v) {
    using pointer = ForwardListNode<T>*;
    pointer root = nullptr, p = nullptr;
    v.assign(v.begin(), partition(v.begin(), v.end(), [](const pointer p){ return nullptr != p; }));
    auto cmp = [](const pointer p, const pointer q) {
        return p->val > q->val;
    };
    std::priority_queue<pointer> pq(cmp, v);
    while (!pq.empty()) {
        if (root == nullptr) { p = root = pq.top(); }
        else { p->next = pq.top(); p = p->next; }
        if (pq.top()->next) {
            pq.pop();
            pq.push(p->next);
        } else pq.pop();
    }
    return root;
}

template <typename T>
std::vector<T> topology_sort(const std::vector<std::pair<T, T>>& edges) {
    std::unordered_multimap<T, T> m;
    std::unordered_map<T, int> d;
    std::unordered_set<T> v;
    for (const auto& p : edges) {
        v.insert(p.first);
        v.insert(p.second);
        m.insert(p);
        ++d[p.second];
    }
    std::vector<int> r;
    for (auto i : v) if (d[i] == 0) r.push_back(i);
    for (size_t i = 0; r.size() < v.size();) {
        auto n = r.size();
        if (i == n) return r; // loop detected
        for (; i < n; ++i) {
            auto bounds = m.equal_range(r[i]);
            std::for_each(bounds.first, bounds.second, [&d, &r](const auto& p) {
                if (--d[p.second] == 0) r.push_back(p.second);
            });
        }
    }
    return r;
}
} // namespace sort

#endif /* sort_hpp */
