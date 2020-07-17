//
//  search.hpp
//  algorithms
//
//  Created by 云心逸 on 2019/1/16.
//  Copyright © 2019 云心逸. All rights reserved.
//

#ifndef search_hpp
#define search_hpp

#include <vector>
#include <numeric>
#include <unordered_map>

namespace search {
	template <typename T>
	class union_find {
	public:
		using size_type = size_t;

		union_find(size_type n) : m_count(n), m_store(n), m_depth(n, 1) {
			std::iota(m_store.begin(), m_store.end(), 0);
		}
		union_find(const union_find&) = delete;
		union_find(union_find&&) = delete;
		union_find& operator=(union_find) = delete;

		/* quick find: perf issue: slow on connect
		void connect(size_type p, size_type q) {
			size_type pi = find(p), qi = find(q);
			if (pi == qi) return;
			for (auto& v : m_store)
				if (v == pi) v = qi;
			--m_count;
		}
		size_type find(size_type p) const { return m_store[p]; }
		*/

		/* quick union : perf issue: slow find
		void connect(size_type p, size_type q) {
			size_type pi = find(p), qi = find(q);
			if (pi == qi) return;
			m_store[pi] = qi;
			--m_count;
		}
		size_type find(size_type p) const {
			while (p != m_store[p]) p = m_store[p];
			return p;
		}
		*/

		// weighted-quick-union : O(logN)
		void connect(size_type p, size_type q) {
			auto pi = find(p), qi = find(q);
			if (pi == qi) return;
			if (m_depth[pi] < m_depth[qi]) { // make smaller point to larger one
				m_store[pi] = qi;
				m_depth[qi] += m_depth[pi];
			} else {
				m_store[qi] = pi;
				m_depth[pi] += m_depth[qi];
			}
			--m_count;
		}
		size_type find(size_type p) const {
			while (p != m_store[p]) p = m_store[p];
			return p;
		}

		void connect(const std::pair<size_type, size_type>& p) {
			return connect(p.first, p.second);
		}
		bool is_connected(size_type p, size_type q) const {
			return find(p) == find(q);
		}
		bool is_connected(const std::pair<size_type, size_type>& p) const {
			return is_connected(p.first, p.second);
		}
		size_type count() const { return m_count; }
	private:
		size_type m_count;
		std::vector<size_type> m_store;
		std::vector<size_type> m_depth;
	};
}

struct DisjointSet {
    DisjointSet(int n) {
        for (int i = 0; i < n*2; ++i) {
            m_v.push_back(i);
        }
    }
    int find(int i) {
        while (m_v[i] != i) i = m_v[i];
        return i;
    }
    void join(int i, int j) {
        m_v[find(i)] = find(j);
    }
    void adj() {
        for (int i = 0; i < m_v.size(); ++i) m_v[i] = find(i);
    }
    int count(int i) {
        return std::count(m_v.begin(), m_v.end(), i);
    }
    int size() const { return m_v.size(); }
private:
    vector<int> m_v;
};

#endif /* search_hpp */
