/*
 * Filename:	graph.cpp
 *
 * Author:		Oxnz
 * Email:		yunxinyi@gmail.com
 * Created:		2016-08-04 20:37:02 CST
 * Last-update:	2016-08-04 20:37:02 CST
 * Description: anchor
 *
 * Version:		0.0.1
 * Revision:	[NONE]
 * Revision history:	[NONE]
 * Date Author Remarks:	[NONE]
 *
 * License:
 * Copyright (c) 2016 Oxnz
 *
 * Distributed under terms of the [LICENSE] license.
 * [license]
 */

#ifndef graph_hpp
#define graph_hpp

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

namespace m {
template <typename T, typename Allocator = std::allocator<T>>
class graph {
public:
    using size_type = size_t;
    using value_type = T;

    graph() : graph(0, 0) {}
    graph(size_type v, size_type e) : m_V(v), m_E(e), m_adj() {}
    
    std::vector<value_type>& adj(value_type v) { return m_adj[v]; }
    const std::vector<value_type>& adj(value_type v) const { return m_adj[v]; }

    void edge(const value_type& v, const value_type& w) {
        m_adj[v].push_back(w);
        m_adj[w].push_back(v);
    }
    size_type degree(value_type v) { return adj(v).size(); }
    
    int max_degree() {
        size_type n = 0;
        for (int v = 0; v < m_V; ++v)
            n = std::max(degree(v), n);
        return n;
    }
    double avg_degree() { return 2.0 * m_E / m_V; }
    int nloops() {
        int n = 0;
        for (int v = 0; v < m_V; ++v)
            for (int w : adj(v))
                if (v == w)
                    ++n;
        return n/2;
    }
    
    bool empty() const { return m_adj.empty(); }
    int V() const { return m_V; }
    int E() const { return m_E; }
    
    friend std::istream &operator>>(std::istream &is, graph &g) {
        is >> g.m_V >> g.m_E;
        g.m_adj.clear();
        for (size_type i = 0; i < g.m_V; ++i) g.m_adj.emplace();
        value_type v, w;
        for (size_type i = 0; i < g.m_E; ++i) {
            is >> v >> w;
            g.edge(v, w);
        }
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const graph &g) {
        os << "graph<" << std::addressof(g) << ">"
           << "(vertices = " << g.V() << ", edges = " << g.E() << ")";
        if (g.empty()) return os << "[]";
        os << "[";
        for (const auto &p : g.m_adj) {
            os << "\n<" << p.first << ">[";
            for (const auto &v : p.second)
                os << v << ", ";
            os << "]\n";
        }
        return os << "]";
    }
    
private:
    size_type m_V;
    size_type m_E;
    std::unordered_map<value_type, std::vector<value_type, Allocator>> m_adj;
};

}

#endif /* graph_hpp */
