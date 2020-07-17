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
#include <set>
#include <string>

class Graph {
public:
    Graph() : m_V(0), m_E(0) {}
    std::set<int> adj(int v) const {
        return m_adj[static_cast<size_t>(v)];
    }
    void addEdge(int v, int w) {
        m_adj[static_cast<size_t>(v)].insert(w);
        m_adj[static_cast<size_t>(w)].insert(v);
    }
    size_t degree(int v) {
        return adj(v).size();
    }
    size_t maxDegree() {
        size_t d = 0;
        for (int v = 0; v < m_V; ++v)
            d = std::max(degree(v), d);
        return d;
    }
    double avgDegree() {
        return 2.0 * m_E / m_V;
    }
    int nloops() {
        int n = 0;
        for (int v = 0; v < m_V; ++v)
            for (int w : adj(v))
                if (v == w)
                    ++n;
        return n/2;
    }

    /**
    * method 1: DFS
    * method 2: Disjoint Set
    */
//    bool has_cycle() const {
//        disjoint_set dj(m_V);
//        for (edge : edges) {
//            auto p = dj.find(edge.first);
//            auto q = dj.find(edge.second);
//            if (p == q) return true;
//            dj.connect(p, q);
//        }
//        return false;
//    }
    int V() const { return m_V; }
    int E() const { return m_E; }
    friend std::istream &operator>>(std::istream &is, Graph &g);
    friend std::ostream &operator<<(std::ostream &os, const Graph &g);
private:
    int m_V;
    int m_E;
    std::vector<std::set<int>> m_adj;
};

/**
 * @brief The Bigraph class
 * ref: https://algorithms.tutorialhorizon.com/introduction-to-bipartite-graphs-or-bigraphs/
 */
class Bigraph {
public:
    void add_edge(int u, int v) {
        m.insert({u, v});
        m.insert({v, u});
        v.insert(u);
        v.insert(v);
    }
    bool is_bigraph() const {
        if (v.empty()) return true;
        unordered_map<int, int> color;
        for (auto i : v) {
            if (color.count(i) > 0) continue;
        }
    }
private:
    unordered_multimap<int, int> m;
    unordered_set<int> v;
};

#endif /* graph_hpp */
