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

class sparse_set {
public:
    using size_type = size_t;
    using value_type = int;

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
    
	bool contain(value_type k) {
        if (k >= m_capacity || empty())
			return false;
		int i = m_sparse[k];
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
	bool remove(int k) {
		if (contain(k)) {
			--m_size;
			int topval = m_dense[m_size];
			if (k != topval)
				xchg(k, topval);
			return true;
		}
		return false;
	}
	void foreach(void *(*func)(int)) {
		for (int i = 0; i < m_size; ++i) {
			func(m_dense[i]);
		}
	}
    friend std::ostream& operator<<(std::ostream& os, const sparse_set& s) {
        os << "sparse_set<" << std::addressof(s) << ">"
           << "(size = " << s.m_size << ", capacity = " << s.m_capacity << ")[\n";
        os << "\telements: [";
        for (int i = 0; i < s.m_size; ++i) os << s.m_dense[i] << ", ";
        os << "]\n";
        os << "\tdense: [";
        for (int i = 0; i < s.m_capacity; ++i) os << s.m_dense[i] << ", ";
        os << "]\n";
        os << "\tsparse: [";
        for (int i = 0; i < s.m_capacity; ++i) os << s.m_sparse[i] << ", ";
        os << "]]";
        return os;
    }
private:
	void xchg(int a, int b) {
		if (contain(a) && contain(b) && a != b) {
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
