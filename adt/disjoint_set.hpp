//
//  disjoint_set.hpp
//  adt
//
//  Created by Max Zhang on 2020/2/12.
//

#ifndef disjoint_set_hpp
#define disjoint_set_hpp

#include <vector>
#include <iostream>
#include <iterator>

namespace m {
class disjoint_set {
public:
    using size_type = size_t;
    using index_type = int;
    
    disjoint_set(size_type capacity) : m_size(capacity), m_set(capacity, -1), m_rank(capacity) {}
    
    size_type size() const { return m_size; }
    size_type capacity() const { return m_set.size(); }
    bool empty() const { return size() == 0; }
    
    size_type rank(index_type i) const { return m_rank[i]; }
    bool connected(index_type a, index_type b) const { return find(a) == find(b); }

    index_type find(index_type i) const {
        if (m_set[i] == -1) return i;
        return m_set[i] = find(m_set[i]);
    }

    index_type join(index_type a, index_type b) {
        index_type i = find(a), j = find(b);
        if (i == -1 || j == -1) return -1;
        if (i != j) {
            if (rank(i) < rank(j)) std::swap(i, j);
            m_set[i] = j;
            ++m_rank[j];
            --m_size;
        }
        return j;
    }
    
    friend std::ostream& operator<<(std::ostream& os, const disjoint_set& s) {
        os << "disjoint_set<" << std::addressof(s) << ">(size = " << s.size() << ")[\n";
        os << "\tset: [";
        std::copy(s.m_set.begin(), s.m_set.end(), std::ostream_iterator<index_type>(os, ", "));
        os << "]\n";
        os << "\trank: [";
        std::copy(s.m_rank.begin(), s.m_rank.end(), std::ostream_iterator<index_type>(os, ", "));
        return os << "]]";
    }

private:
    size_type m_size;
    mutable std::vector<index_type> m_set;
     std::vector<size_type> m_rank;
};
}

#endif /* disjoint_set_hpp */
