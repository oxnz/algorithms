//
//  graph.cpp
//  graph
//
//  Created by 云心逸 on 8/4/16.
//  Copyright © 2016 Errpro,Inc. All rights reserved.
//

#include "graph.hpp"

std::istream &operator>>(std::istream &is, Graph &g) {
    is >> g.m_V >> g.m_E;
    g.m_adj.clear();
    for (int i = 0; i < g.m_V; ++i)
        g.m_adj.push_back(std::vector<int>());
    int v, w;
    for (int i = 0; i < g.m_E; ++i) {
        is >> v >> w;
        g.addEdge(v, w);
    }
    return is;
}

std::ostream &operator<<(std::ostream &os, const Graph &g) {
    os << g.V() << " vertices, " << g.E() << " edges" << std::endl;
    for (int v = 0; v < g.V(); ++v) {
        os << v << ": ";
        for (int w : g.adj(v))
            os << w << " ";
        os << std::endl;
    }
    return os;
}