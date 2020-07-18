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

#include <iostream>
#include <algorithm>
#include <memory>

namespace m {

/**
 * # Sparse Set
* storing sparse sets of integers on the range [0 .. u-1] and performing
 *1. initialization,
 *2. lookup,
 *3. and insertion in time O(1) and iteration in O(n), where n is the number of elements in the set.

 The data structure considers a universe of integers from 0 to u−1; depending on the circumstances, the integers probably map to something else. Any given set consists of n items chose from the universe; there are no duplicates. Note that n ≤ u, certainly, and likely n is much less than u — otherwise, you would probably use a bit vector to represent the set. Note also that we are optimizing for speed at the expense of space, as a bit vector takes u bits but our data structure takes 2u integers.

 Think about a bit vector. Setting a bit is a constant-time operation, as is checking if a bit is set or unset. But initializing the bit vector and iterating over the set elements of the bit vector each take time proportional to the size of the bit vector. Our sparse sets reduce the iteration to time proportional to the size of the set (rather than the size of the universe) and reduce the initialization time to a constant.

 The sparse set is represented by two vectors that we will call dense (abbreviated D) and sparse (abbreviated S). Initially n, the number of elements in the set, is zero; the two vectors are uninitialized and may contain anything. To add an element 0 ≤ k < u to a set that does not already contain k, we set D[n] to k, S[k] to n, and increase n by 1, an operation that takes constant time. After this, the two vectors point to each other, which gives a test of set membership that also works in constant time: an element k is in the set if and only if S[k] < n and D[S[k]] == k>. Note that if k is not a member of the set, the value of S[k] doesn’t matter; either it S[k] will be greater than n or it will point to an element of D that doesn’t point back to it. The diagram above right shows a set with the elements 5, 1 and 4; the blue boxes may contain any value. To iterate over the elements of the set, read D[0 .. n−1], which takes time O(n), and to clear the set make n = 0, which takes time O(1); note in particular that clearing the set doesn’t require reinitialization. Other operations, including size-of, delete, union, intersection, difference, and set-equality are possible, and equally time-efficient compared to bit vectors, but we won’t discuss them here, since they are seldom used with this representation of sets. A common use of these sparse sets is with register allocation algorithms in compilers, which have a fixed universe (the number of registers in the machine) and are updated and cleared frequently during a single processing run.

 */
class sparse_set {
public:
    using size_type = size_t;
    using value_type = uint;

    sparse_set(size_type capacity)
        : m_dense(std::make_unique<value_type[]>(capacity)),
          m_sparse(std::make_unique<value_type[]>(capacity)), m_size(), m_capacity(capacity)
    {}
    sparse_set(sparse_set&) = delete;
    sparse_set(sparse_set&&) = default;
    sparse_set& operator=(sparse_set&) = delete;
    sparse_set& operator=(sparse_set&&) = default;
    ~sparse_set() {}
    
	size_type capacity() const { return m_capacity; }
	size_type size() const { return m_size; }
	bool empty() const { return size() == 0; }
	void clear() { m_size = 0; }
    
    bool contain(const value_type& k) {
        if (k >= m_capacity || empty())
			return false;
        size_type i = m_sparse[k];
		return i < m_size && m_dense[i] == k;
	}
	bool insert(value_type k) {
        if (k >= m_capacity || contain(k))
			return false;
        m_sparse[k] = m_size;
        m_dense[m_size] = k;
		++m_size;
		return true;
	}
    bool remove(value_type k) {
		if (contain(k)) {
            xchg(k, m_dense[m_size-1]);
            --m_size;
			return true;
		}
		return false;
	}
    template <typename Fn>
    void foreach(Fn fn) {
        for (size_type i = 0; i < m_size; ++i) {
			fn(m_dense[i]);
		}
	}
    friend std::ostream& operator<<(std::ostream& os, const sparse_set& s) {
        os << "sparse_set<" << std::addressof(s) << ">"
           << "(size = " << s.m_size << ", capacity = " << s.m_capacity << ")[\n";
        os << "\telements: [";
        for (size_type i = 0; i < s.m_size; ++i) os << s.m_dense[i] << ", ";
        os << "]\n";
        os << "\tdense: [";
        for (size_type i = 0; i < s.m_capacity; ++i) os << s.m_dense[i] << ", ";
        os << "]\n";
        os << "\tsparse: [";
        for (size_type i = 0; i < s.m_capacity; ++i) os << s.m_sparse[i] << ", ";
        os << "]]";
        return os;
    }
private:

    /**
     * @brief xchg
     *  sparse 0:2 1:8 dense 2:0 8:1 ->
     *  sparse 0:8 1:2 dense 2:1 8:0
     * @param a
     * @param b
     */
	void xchg(int a, int b) {
        if (a != b && contain(a) && contain(b)) {
			int i = m_sparse[a];
            int j = m_sparse[b];
            std::swap(m_sparse[a], m_sparse[b]);
            std::swap(m_dense[i], m_dense[j]);
		}
	}
private:
    std::unique_ptr<value_type[]> m_dense;
    std::unique_ptr<value_type[]> m_sparse;
    size_type m_size;
    size_type m_capacity;
};

}
