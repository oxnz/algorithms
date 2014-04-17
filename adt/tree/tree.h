#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct Data {
	double value;
	Data(double v) {
		value = v;
	}
	std::string str() {
		string s;
		stringstream ss(s);
		ss << value;
		return ss.str();
	}
};

struct Node {
    Data _data; // the data
    Node* _left; // left child
    Node* _right; // right child

	Data data() {
		return _data;
	}
    // Node* parent; // parent
};

class Tree {
public:
    Tree() {
		_root = nullptr;
	}
    Tree(const Tree& t);
    ~Tree() {
	}

    bool empty() const;
    double root(); // decomposition (access functions)
    Tree& left();
    Tree& right();

    // Tree& parent(double x);

    // ... update ...
    void insert(const Data d) { // compose x into a Tree
		Node *p = _root;
		while (p) {
			if (p->data() < d) {
				p = p->right();
			} else {
				p = p->left();
			}
		}
	}
    void remove(const Data x); // decompose x from a Tree
private:
	Node *_root;
};
