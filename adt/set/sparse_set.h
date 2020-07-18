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

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * @brief The SparseSet class
 * @ref https://programmingpraxis.com/2012/03/09/sparse-sets/
 */
class SparseSet {
public:
    SparseSet(size_t n = 100) : m_sparse(n) {
	}
	~SparseSet() {
	}
    size_t capacity() const {
        return m_sparse.size();
	}
    size_t count() const {
        return m_dense.size();
	}
    bool empty() const {
        return 0 == count();
	}
    void clear() {
        m_dense.clear();
	}
    bool contain(size_t k) const {
        if (k < m_sparse.size())
            return m_sparse[k] < capacity() && m_dense[m_sparse[k]] == k;
        return false;
	}
    bool insert(size_t k) {
        if (k >= capacity() || contain(k))
			return false;
        m_sparse[k] = m_dense.size();
        m_dense.push_back(k);
		return true;
	}
    bool remove(size_t k) {
        if (!contain(k)) return false;
        xchg(k, m_dense.back());
        m_dense.pop_back();
        return true;
	}
    void foreach(void *(*func)(size_t)) {
        for (int i = 0; i < count(); ++i)
            func(m_dense[i]);
	}
	void inspect(void) {
        printf("count: %d/%d\nelems:\n\t", count(), capacity());
        for (int i = 0; i < count(); ++i)
            printf("[%d]", m_dense[i]);
        printf("\sparse:\n\t");
        for (int i = 0; i < capacity(); ++i)
            printf("[%d]", m_sparse[i]);
		printf("\n");
	}
//private:
    void xchg(size_t a, size_t b) {
        if (a != b && contain(a) && contain(b)) {
            swap(m_sparse[a], m_sparse[b]);
            swap(m_dense[m_sparse[a]], m_dense[m_sparse[b]]);
		}
	}
private:
    std::vector<size_t> m_dense;
    std::vector<size_t> m_sparse;
};
