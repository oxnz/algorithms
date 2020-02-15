//
//  digraph.hpp
//  graph
//
//  Created by 云心逸 on 8/7/16.
//  Copyright © 2016 Errpro,Inc. All rights reserved.
//

#ifndef digraph_hpp
#define digraph_hpp

#include <vector>

class Digraph {
public:
    Digraph(int v) : m_V(v), m_E(0) {
        for (int i = 0; i < m_V; ++i)
            m_adj[i] = std::vector<int>();
    }
    int V() const { return m_V; }
    int E() const { return m_E; }
    void addEdge(int v, int w) {
        m_adj[v].push_back(w);
        ++m_E;
    }
    std::vector<int> adj(int v) const { return m_adj[v]; }
    Digraph* reverse() const {
        Digraph *g = new Digraph(m_V);
        for (int v = 0; v < m_V; ++v)
            for (int w : m_adj[v])
                g->addEdge(w, v);
        return g;
    }
    friend std::istream& operator>>(std::istream &is, Digraph &graph);
    friend std::ostream& operator<<(std::ostream &os, const Digraph &graph);
private:
    int m_V;
    int m_E;
    std::vector<std::vector<int>> m_adj;
};

#endif /* digraph_hpp */
