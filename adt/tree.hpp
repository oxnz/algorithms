//
//  tree.hpp
//  algorithms
//
//  Created by 云心逸 on 2019/1/7.
//  Copyright © 2019 云心逸. All rights reserved.
//

#ifndef tree_h
#define tree_h

#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <sstream>

namespace binary_tree {

template<typename T>
struct TreeNode {
	TreeNode *left;
	TreeNode *right;
	T value;
	TreeNode(T v) : left(nullptr), right(nullptr), value(v) {}
};

namespace build {

template <typename T>
TreeNode<T>* by_preorder_and_inorder(const std::vector<T> &preorder, const std::vector<T>& inorder) {
	using v = std::vector<T>;
	if (preorder.size() == 0) return nullptr;
	auto root = new binary_tree::TreeNode<T>(preorder[0]);
	auto it = std::find(inorder.begin(), inorder.end(), root->value);
	auto ln = std::distance(inorder.begin(), it);
	auto rn = preorder.size()-1-ln;
	if (ln) {
		v _pv(preorder.begin()+1, preorder.begin()+1+ln);
		v _iv(inorder.begin(), inorder.begin()+ln);
		root->left = by_preorder_and_inorder(_pv, _iv);
	}
	if (rn) {
		v _pv(preorder.end()-rn, preorder.end());
		v _iv(inorder.end()-rn, inorder.end());
		root->right = by_preorder_and_inorder(_pv, _iv);
	}
	return root;
}

template <typename T>
TreeNode<T>* by_inorder_and_postorder(const std::vector<T> &inorder, const std::vector<T>& postorder) {
	using v = std::vector<T>;
	if (inorder.size() == 0) return nullptr;
	auto root = new TreeNode<T>(postorder[postorder.size()-1]);
	auto it = std::find(inorder.begin(), inorder.end(), root->value);
	size_t ln = distance(inorder.begin(), it);
	size_t rn = inorder.size() - 1 - ln;
	if (ln) {
		v iv(inorder.begin(), inorder.begin()+ln);
		v pv(postorder.begin(), postorder.begin()+ln);
		root->left = by_inorder_and_postorder(iv, pv);
	}
	if (rn) {
		v iv(inorder.end()-rn, inorder.end());
		v pv(postorder.end()-1-rn, postorder.end()-1);
		root->right = by_inorder_and_postorder(iv, pv);
	}
	return root;
}

} // build

namespace traverse {
namespace recursive {

template<typename T, typename Fn>
void pre(const TreeNode<T>* root, Fn f) {
	if (root) {
		f(root->value);
		pre(root->left, f);
		pre(root->right, f);
	}
}

template<typename T, typename Fn>
void in(const TreeNode<T>* root, Fn f) {
	if (root) {
		in(root->left, f);
		f(root->value);
		in(root->right, f);
	}
}

template<typename T, typename Fn>
void post(const TreeNode<T>* root, Fn f) {
	if (root) {
		post(root->left, f);
		post(root->right, f);
		f(root->value);
	}
}
} // recursive



template<typename T, typename Fn>
void pre(const TreeNode<T>* p, Fn f) {
	std::stack<const TreeNode<T>*> nodes;
	if (p) nodes.push(p);
	while (not nodes.empty()) {
		p = nodes.top();
		nodes.pop();
		f(p->value);
		if (p->right) nodes.push(p->right);
		if (p->left) nodes.push(p->left);
	}
}

template<typename T, typename Fn>
void in(const TreeNode<T>* p, Fn f) {
	std::stack<const TreeNode<T>*> nodes;
	while ((not nodes.empty()) or nullptr != p) {
		if (p) {
			nodes.push(p);
			p = p->left;
		} else {
			p = nodes.top();
			nodes.pop();
			f(p->value);
			p = p->right;
		}
	}
}

template<typename T, typename Fn>
void post(const TreeNode<T>* p, Fn f) {
	std::stack<const TreeNode<T>*> nodes;
	if (p) nodes.push(p);
	auto ppre = p;
	while (!nodes.empty()) {
		auto pcur = nodes.top();
		nodes.pop();
		if ((nullptr == pcur->left && nullptr == pcur->right) ||
		        (ppre && (ppre == pcur->left || ppre == pcur->right))) {
			f(pcur);
			nodes.pop();
			ppre = pcur;
		} else {
			if (pcur->right) nodes.push(pcur->right);
			if (pcur->left) nodes.push(pcur->left);
		}
	}
}

template<typename T, typename Fn>
void level(const TreeNode<T>* p, Fn f) {
	std::queue<const TreeNode<T>*> q;
	if (p) q.push(p);
	while (not q.empty()) {
		p = q.front();
		q.pop();
		f(p->value);
		if (p->left) q.push(p->left);
		if (p->right) q.push(p->right);
	}
}

template <typename T>
void echo(const TreeNode<T>* root) { // by level
	if (nullptr == root) return;
	std::queue<const TreeNode<T>*> nodes;
	nodes.push(root);
	nodes.push(nullptr);
	while (!nodes.empty()) { // print one line
		auto p = nodes.front();
		nodes.pop();
		if (p) {
			std::cout << p->value << ", ";
			if (p->left) nodes.push(p->left);
			if (p->right) nodes.push(p->right);
		} else {
			std::cout << "\n";
			if (nodes.empty()) return;
			nodes.push(nullptr);
		}
	}
}

} // traverse

	namespace codec {
		// Encodes a tree to a single string.
		template <typename T>
		std::string serialize(TreeNode<T>* root) {
			if (root == nullptr) return "";
			std::queue<TreeNode<T>*> q;
			q.push(root);
			std::ostringstream ss;
			while (!q.empty()) {
				auto p = q.front();
				q.pop();
				if (p) {
					ss << p->value << " ";
					q.push(p->left);
					q.push(p->right);
				} else ss << "* ";
			}
			return ss.str();
		}

		// Decodes your encoded data to tree.
		template <typename T>
		TreeNode<T>* deserialize(std::string data) {
			if (data.empty()) return nullptr;
			std::vector<TreeNode<T>*> v;
			std::istringstream ss(data);
			for (std::string s; ss >> s; ) {
				if (s == "*") v.push_back(nullptr);
				else v.push_back(new TreeNode<T>(std::stoi(s)));
			}
			for (size_t i = 0, j = 0; j+2 < v.size(); ++i) {
				if (v[i]) {
					v[i]->left = v[++j];
					v[i]->right = v[++j];
				}
			}
			return v.front();
		}
	} // codec

namespace operate {
template <typename T>
void rotate(TreeNode<T> *p) {
	if (nullptr != p) {
		std::swap(p->left, p->right);
		rotate(p->left);
		rotate(p->right);
	}
}
} // operate

template <typename T>
size_t depth(const TreeNode<T> *p) {
	return nullptr == p ? 0 : 1 + std::max(depth(p->left), depth(p->right));
}

template <typename T>
bool _is_symmetric(const TreeNode<T>* lhs, const TreeNode<T>* rhs) {
	if ((nullptr == lhs && nullptr != rhs) || (nullptr != lhs && nullptr == rhs)) return false;
	if ((nullptr == lhs && nullptr == rhs) || lhs == rhs) return true;
	return lhs->value == rhs->value && _is_symmetric(lhs->left, rhs->right) && _is_symmetric(lhs->right, rhs->left);
}

template <typename T>
bool is_symmetric(const TreeNode<T> *p) {
	if (nullptr == p) return true;
	return _is_symmetric(p->left, p->right);
}

namespace bst {
template <typename T>
TreeNode<T>* min(const TreeNode<T>* root) {
	if (nullptr == root) return root;
	while (root->left)
		root = root->left;
	return root;
}

template <typename T>
TreeNode<T>* max(const TreeNode<T>* root) {
	if (nullptr == root) return root;
	while (root->right)
		root = root->right;
	return root;
}

template <typename T>
bool is_balanced(const TreeNode<T>* root) {
	return nullptr == root ||
	        (is_balanced(root->left) && is_balanced(root->right) &&
	         std::abs(static_cast<long long>(depth(root->left) - depth(root->right))) < 2);
}

template <typename T>
TreeNode<T>* LCA(const TreeNode<T>* root, const TreeNode<T>* p, const TreeNode<T>* q) {
	if (nullptr == root || p == root || q == root) return root;
	if (q->value < p->value) std::swap(p, q);
	if (!(p->value < root->value)) return LCA(root->right, p, q);
	if (q->value < root->value) return LCA(root->left, p, q);
	return root;
}

namespace operate {
template <typename T, typename Compare>
TreeNode<T>* erase(TreeNode<T>* root, const T& val, Compare cmp = std::less<T>()) {
	if (nullptr == root) return root;
	if (cmp(val, root->value)) root->left = erase(root->left, val);
	else if (cmp(root->value, val)) root->right = erase(root->right, val);
	else {
		if (nullptr == root->left) return root->right;
		else if (nullptr == root->right) return root->left;
		else {
			auto _min = min(root->right);
			root->right = erase(root->right, _min->value);
			_min->left = root->left;
			if (_min != root->right) _min->right = root->right;
			return _min;
		}
	}
	return root;
}
}

}

} // binary_tree

namespace trie {
class trie {
private:
	struct Node {
		bool is_stop;
		size_t children[53]; // child indexes: letters(26 lower, 26 upper) + '-'
	};
	std::vector<Node> m_nodes;
public:
	trie() : m_nodes(1) {}
	void insert(const std::string& s) {
		size_t parent = 0;
		for (auto c : s) {
			if ('a' <= c && c <= 'z') c -= 'a';
			else if ('A' <= c && c <= 'Z') c = c - 'A' + 26;
			else if (c == '-') c = 52;
			else throw std::runtime_error(std::string("invalid character encoutered: ").append(1, c));
			if (0 == m_nodes[parent].children[c]) { // not exists
				m_nodes.emplace_back();
				m_nodes[parent].children[c] = m_nodes.size() - 1;
			}
			parent = m_nodes[parent].children[c];
		}
		m_nodes[parent].is_stop = true;
	}
	size_t search(const std::string& s) const { // 0: not found
		size_t index = 0;
		for (auto c : s) {
			index = m_nodes[index].children[c];
			if (0 == index) return index;
		}
		return index;
	}
	bool search_prefix(const std::string& prefix) const {
		return search(prefix) > 0;
	}
	bool search_word(const std::string& word) const {
		return m_nodes[search(word)].is_stop;
	}
	size_t word_count() const {
		return std::count_if(m_nodes.begin(), m_nodes.end(), [](const Node& node){ return node.is_stop; });
	}
	size_t size() const {
		return m_nodes.size() - 1;
	}
	bool empty() const {
		return size() > 0;
	}
	void reserve(size_t n) {
		m_nodes.reserve(n);
	}
};

class static_trie {
	constexpr static size_t MAX_CHAR = 26;
	constexpr static size_t MAX_CNT = 1000000;
	class Node {
	public:
		static Node* createNode() {
			// zero-initialized, cause no user-provided default constructor
			static Node SharedMemory[MAX_CNT];
			static size_t allocp; // static is initialized to zero
			if (allocp >= MAX_CNT) throw std::bad_alloc();
			Node *p = &SharedMemory[allocp++];
			p->count = 1;
			return p;
		}
	public:
		size_t count; // number of occurence of this char
		Node* next[MAX_CHAR];
	};
public:
	static_trie() : root(nullptr) {}

	void insert(const std::string& s) {
		Node *p = root;
		if (nullptr == p) p = root = Node::createNode();
		for (auto& c : s) {
			int index = c - 'a';
			if (nullptr != p->next[index]) ++p->next[index]->count;
			else p->next[index] = Node::createNode();
			p = p->next[index];
		}
	}

	size_t search(const std::string& s) const {
		Node *p = root;
		if (nullptr == p) return 0;
		for (const auto& c : s) {
			int index = c - 'a';
			if (nullptr == p->next[index]) return 0;
			p = p->next[index];
		}
		return p->count;
	}
private:
	Node *root;
};

} // trie

namespace nary_tree {
template <typename T>
struct Node {
	Node(const T& val) : value(val), children() {}
	T value;
	std::vector<const Node<T>*> children;
};
template <typename T, typename Fn>
void preorder(const Node<T>* root, Fn f) {
	if (root) {
		f(root->value);
		for (auto p : root->children)
			preorder(p, f);
	}
}
template <typename T, typename Fn>
void postorder(const Node<T>* root, Fn f) {
	if (root) {
		for (auto p : root->children)
			postorder(p, f);
		f(root->value);
	}
}

template <typename T, typename Fn>
void levelorder(const Node<T>* root, Fn f) {
	if (nullptr == root) return;
	std::queue<const Node<T>*> nodes;
	nodes.push(root);
	while (!nodes.empty()) {
		f(nodes.front());
		nodes.pop();
		for (const auto p : root->children)
			nodes.push(p);
	}
}

template <typename T>
void echo(const Node<T>* root) {
	if (nullptr == root) return;
	std::queue<const Node<T>*> nodes;
	nodes.push(root);
	nodes.push(nullptr);
	while (!nodes.empty()) {
		const auto p = nodes.front();
		nodes.pop();
		if (p) {
			std::cout << p->value << ", ";
			for (const auto p : root->children)
				nodes.push(p);
		} else {
			std::cout << "\n";
			if (nodes.empty()) break;
			nodes.push(nullptr);
		}
	}
}

template <typename T>
class binary_indexed_tree {
    using size_type = size_t;
public:
    binary_indexed_tree(const std::vector<T>& v) {
        m_index.emplace_back();
        for (const auto& e : v) m_index.push_back(e);
        for (size_type i = 1; i < m_index.size(); ++i) {
            size_type idx = i + (i & -i);
            if (idx < m_index.size()) m_index[idx] += m_index[i];
        }
    }
    void update(size_type idx, const T& delta) {
        idx += 1;
        while (idx < m_index.size()) {
            m_index[idx] += delta;
            idx += idx & (idx & -idx);
        }
    }
    T prefix_sum(size_type idx) {
        idx += 1;
        T r = 0;
        while (idx > 0) {
            r += m_index[idx];
            idx -= idx & -idx;
        }
        return r;
    }
    T range_sum(size_type idx_from, size_type idx_to) {
        return prefix_sum(idx_to) - prefix_sum(idx_from-1);
    }
private:
    std::vector<T> m_index;
};


/*
struct SegmentTree {
public:
    SegmentTree(const std::vector<int>& v) : m_v(v) {
        auto height = static_cast<int>(std::ceil(std::log2(v.size())));
        auto n = 2 * static_cast<int>(pow(2, height)) - 1;
        m_aux.resize(n);
        make_aux(0, m_v.size()-1, 0);
    }
    int mid(int a, int b) const {
        return (a + b)/2;
    }
    int sum_of_range(int a, int b) const {
        if (a < 0 || b >= m_v.size() || a > b) throw std::invalid_argument("invalid range");
        return sum_of_range(0, m_v.size()-1, a, b, 0);
    }
    void increment(int i, int v) {
        if (i < 0 || i >= m_v.size()) throw std::invalid_argument("invalid index");
        m_v[i] += v;
        increment(0, m_v.size()-1, i, v, 0);
    }
private:
    int make_aux(int i, int j, int k) {
        if (i == j) return m_aux[k] = m_v[i];
        auto m = mid(i, j);
        return m_aux[k] = make_aux(i, m, 2*k+1) + make_aux(m+1, j, 2*k+2);
    }
    int sum_of_range(int a, int b, int i, int j, int k) const {
        if (i <= a && j >= b) return m_aux[k];
        if (j < a || i > b) return 0;
        auto m = mid(a, b);
        return sum_of_range(a, m, i, j, 2*k+1)
               + sum_of_range(m+1, b, i, j, 2*k+2);
    }
    void increment(int a, int b, int i, int v, int k) {
        if (i < a || i > b) return;
        m_v[k] += v;
        if (a != b) {
            auto m = mid(a, b);
            increment(a, m, i, v, 2*k+1);
            increment(m+1, b, i, v, 2*k+2);
        }
    }

private:
    std::vector<int> m_aux;
    std::vector<int> m_v;
};
*/

}

#endif /* tree_h */
