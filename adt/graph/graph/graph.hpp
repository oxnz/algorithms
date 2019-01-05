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

class Graph {
public:
    Graph() : m_V(0), m_E(0) {}
    std::vector<int> adj(int v) const {
        return m_adj[v];
    }
    void addEdge(int v, int w) {
        m_adj[v].push_back(w);
        m_adj[w].push_back(v);
    }
    int degree(int v) {
        int deg = 0;
        for (int w : adj(v))
            ++deg;
        return deg;
    }
    int maxDegree() {
        int max = 0;
        for (int v = 0; v < m_V; ++v)
            max = std::max(degree(v), max);
        return max;
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
    int V() const { return m_V; }
    int E() const { return m_E; }
    friend std::istream &operator>>(std::istream &is, Graph &g);
    friend std::ostream &operator<<(std::ostream &os, const Graph &g);
private:
    int m_V;
    int m_E;
    std::vector<std::vector<int>> m_adj;
};

#endif /* graph_hpp */
