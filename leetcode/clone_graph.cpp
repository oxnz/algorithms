//
//  clone_graph.cpp
//  leetcode
//
//  Created by Max Zhang on 2020/2/16.
//

#include "leetcode.hpp"

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
     std::unordered_map<int, Node*> m_nodes;
    Node* getNode(int val) {
        auto it = m_nodes.find(val);
        if (it == m_nodes.end()) m_nodes[val] = new Node(val);
        return m_nodes[val];
    }
public:
    Node* cloneGraph(Node* node) {
        if (!node) return node;
        printf("clone node val: %d\n", node->val);
        auto p = getNode(node->val);
        for (auto _ : node->neighbors)
            p->neighbors.push_back(cloneGraph(_));
        return p;
    }
};

TEST(clone_graph, case_1) {
    return;
    Node nodes[4];
    nodes[0].val = 1;
    nodes[0].neighbors = {&nodes[1], &nodes[3]};
    nodes[1].val = 2;
    nodes[1].neighbors = {&nodes[0], &nodes[2]};
    nodes[2].val = 3;
    nodes[2].neighbors = {&nodes[1], &nodes[3]};
    nodes[3].val = 4;
    nodes[3].neighbors = {&nodes[0], &nodes[2]};
    Solution sol;
    auto p = sol.cloneGraph(&nodes[0]);
    EXPECT_NE(p, nullptr);
    EXPECT_EQ(p->val, 1);
    EXPECT_EQ(p->neighbors.size(), 2);
    EXPECT_EQ(p->neighbors.front()->val, 2);
    EXPECT_EQ(p->neighbors.back()->val, 4);
}
