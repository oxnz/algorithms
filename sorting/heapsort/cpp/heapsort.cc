#include <iostream>

struct Node {
    double element; // the data
    Node* left; // left child
    Node* right; // right child
    // Node* parent; // parent
};

class Tree {
public:
    Tree();
    Tree(const Tree& t);
    ~Tree();

    bool empty() const;
    double root(); // decomposition (access functions)
    Tree& left();
    Tree& right();

    // Tree& parent(double x);

    // ... update ...
    void insert(const double x); // compose x into a Tree
    void remove(const double x); // decompose x from a Tree
};
