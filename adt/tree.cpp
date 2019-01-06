#include <iostream>
#include <stack>
#include <queue>

#include "adt.h"

#include <gtest/gtest.h>

using namespace std;

using Node = TreeNode<int>;

template<typename Accessor>
void pre_order_traverse_r(const Node* root, Accessor fn) {
	if (root) {
		fn(root->value);
		pre_order_traverse_r(root->left, fn);
		pre_order_traverse_r(root->right, fn);
	}
}

template<typename Accessor>
void in_order_traverse_r(const Node* root, Accessor fn) {
	if (root) {
		in_order_traverse_r(root->left, fn);
		fn(root->value);
		in_order_traverse_r(root->right, fn);
	}
}

template<typename Accessor>
void post_order_traverse_r(const Node* root, Accessor fn) {
	if (root) {
		post_order_traverse_r(root->left, fn);
		post_order_traverse_r(root->right, fn);
		fn(root->value);
	}
}

template<typename Accessor>
void pre_order_traverse(const Node* p, Accessor fn) {
	stack<const Node*> nodes;
	if (p) nodes.push(p);
	while (not nodes.empty()) {
		p = nodes.top();
		nodes.pop();
		fn(p->value);
		if (p->right) nodes.push(p->right);
		if (p->left) nodes.push(p->left);
	}
}

template<typename Accessor>
void in_order_traverse(const Node* p, Accessor fn) {
	stack<const Node*> nodes;
	while ((not nodes.empty()) or nullptr != p) {
		if (p) {
			nodes.push(p);
			p = p->left;
		} else {
			p = nodes.top();
			nodes.pop();
			fn(p->value);
			p = p->right;
		}
	}
}

template<typename Accessor>
void level_order_traverse(const Node* p, Accessor fn) {
	queue<const Node*> q;
	if (p) q.push(p);
	while (not q.empty()) {
		p = q.front();
		q.pop();
		fn(p->value);
		if (p->left) q.push(p->left);
		if (p->right) q.push(p->right);
	}
}

void rotate(Node *p) {
	if (nullptr != p) {
		std::swap(p->left, p->right);
		rotate(p->left);
		rotate(p->right);
	}
}

size_t depth(Node *p) {
	return nullptr == p ? 0 : 1 + max(depth(p->left), depth(p->right));
}

bool is_symmetric(const Node* lhs, const Node* rhs) {
	if ((nullptr == lhs && nullptr != rhs) || (nullptr != lhs && nullptr == rhs)) return false;
	if ((nullptr == lhs && nullptr == rhs) || lhs == rhs) return true;
	return lhs->value == rhs->value && is_symmetric(lhs->left, rhs->right) && is_symmetric(lhs->right, rhs->left);
}

bool is_symmetric(const Node *p) {
	if (nullptr == p) return true;
	return is_symmetric(p->left, p->right);
}

bool has_path_sum(const Node *p, int v) { // path: root to leaf
	if (nullptr == p) return false;
	if (nullptr == p->left && nullptr == p->right) return v == p->value;
	return has_path_sum(p->left, v-p->value) || has_path_sum(p->right, v-p->value);
}

template <typename T>
TreeNode<T>* build_tree_by_inorder_postorder(vector<T> &inorder, vector<T>& postorder) {
	using v = vector<T>;
    if (inorder.size() == 0) return nullptr;
    auto root = new TreeNode<T>(postorder[postorder.size()-1]);
    auto it = std::find(inorder.begin(), inorder.end(), root->value);
	size_t ln = distance(inorder.begin(), it);
	size_t rn = inorder.size() - 1 - ln;
	if (ln) {
        v iv(inorder.begin(), inorder.begin()+ln);
		v pv(postorder.begin(), postorder.begin()+ln);
        root->left = build_tree_by_inorder_postorder(iv, pv);
    }
	if (rn) {
		v iv(inorder.end()-rn, inorder.end());
		v pv(postorder.end()-1-rn, postorder.end()-1);
        root->right = build_tree_by_inorder_postorder(iv, pv);
    }
    return root;
}

template <typename T>
TreeNode<T>* build_tree_by_preorder_inorder(vector<T> &pv, vector<T>& iv) {
	using v = vector<T>;
	if (pv.size() == 0) return nullptr;
	auto root = new TreeNode<T>(pv[0]);
	auto it = std::find(iv.begin(), iv.end(), root->value);
	size_t ln = distance(iv.begin(), it);
	size_t rn = pv.size()-1-ln;
	if (ln) {
		v _pv(pv.begin()+1, pv.begin()+1+ln);
		v _iv(iv.begin(), iv.begin()+ln);
		root->left = build_tree_by_preorder_inorder(_pv, _iv);
	}
	if (rn) {
		v _pv(pv.end()-rn, pv.end());
		v _iv(iv.end()-rn, iv.end());
		root->right = build_tree_by_preorder_inorder(_pv, _iv);
	}
	return root;
}

template <typename T>
bool contains(TreeNode<T>* root, const T& val) {
	if (root == nullptr) return false;
	return root->value == val || contains(root->left, val) || contains(root->right, val);
}

template <typename T>
TreeNode<T>* lowest_common_ancestor(TreeNode<T>* root, TreeNode<T>* p, TreeNode<T>* q) {
	if (root == nullptr) return root;
	if (root->value == p->value || root->value == q->value) return root;
	if (contains(root->left, p->value) && contains(root->right, q->value)) return root;
	if (contains(root->left, q->value) && contains(root->right, p->value)) return root;
	auto an = lowest_common_ancestor(root->left, p, q);
	if (an) return an;
	return lowest_common_ancestor(root->right, p, q);
}

TEST(tree, build_tree_by_inorder_postorder) {
    vector<int> inorder {9,3,15,20,7}, postorder {9,15,7,20,3};
    auto tree = build_tree_by_inorder_postorder(inorder, postorder);
    EXPECT_NE(nullptr, tree);
    EXPECT_EQ(3, tree->value);
    EXPECT_EQ(9, tree->left->value);
    EXPECT_EQ(nullptr, tree->left->left);
    EXPECT_EQ(nullptr, tree->left->right);
    EXPECT_EQ(20, tree->right->value);
    EXPECT_EQ(15, tree->right->left->value);
    EXPECT_EQ(7, tree->right->right->value);
	vector<int> iv{1, 2}, pv{2, 1};
	tree = build_tree_by_inorder_postorder(iv, pv);
	EXPECT_NE(nullptr, tree);
	EXPECT_EQ(nullptr, tree->left);
	EXPECT_EQ(2, tree->right->value);
	iv = {2, 3, 1};
	pv = {3, 2, 1};
	tree = build_tree_by_inorder_postorder(iv, pv);
	EXPECT_NE(nullptr, tree);
	EXPECT_EQ(2, tree->left->value);
	EXPECT_EQ(3, tree->left->right->value);
}

TEST(tree, build_tree_by_preorder_inorder) {
	vector<int> pv{3,9,20,15,7}, iv{9,3,15,20,7};
	auto tree = build_tree_by_preorder_inorder(pv, iv);
	EXPECT_NE(nullptr, tree);
	EXPECT_EQ(3, tree->value);
	EXPECT_EQ(9, tree->left->value);
	EXPECT_EQ(20, tree->right->value);
	EXPECT_EQ(15, tree->right->left->value);
	EXPECT_EQ(7, tree->right->right->value);
}

TEST(tree, traverse) {
	Node nodes[]{1,2,3,4,5,6};
	nodes[0].left = &nodes[1];
	nodes[0].right = &nodes[2];
	nodes[1].left = &nodes[3];
	nodes[1].right = &nodes[4];
	nodes[2].left = &nodes[5];
	vector<int> v, prev{1, 2, 4, 5, 3, 6}, midv{4, 2, 5, 1, 6, 3}, postv{4, 5, 2, 6, 3, 1}, levelv{1, 2, 3, 4, 5, 6};
	const auto p = &nodes[0];
	auto it = back_inserter(v);
	auto accessor = node_accessor<Node, back_insert_iterator<vector<int>>>(it);
	pre_order_traverse_r(p, accessor);
	EXPECT_EQ(prev, v);
	v.clear();
	pre_order_traverse(p, accessor);
	EXPECT_EQ(prev, v) << "non recursive pre order traverse";
	v.clear();
	in_order_traverse_r(p, accessor);
	EXPECT_EQ(midv, v);
	v.clear();
	in_order_traverse(p, accessor);
	EXPECT_EQ(midv, v) << "in order traverse";
	v.clear();
	post_order_traverse_r(p, accessor);
	EXPECT_EQ(postv, v);
	v.clear();
	level_order_traverse(p, accessor);
	EXPECT_EQ(levelv, v) << "level order";
}

TEST(tree, rotate) {
	Node nodes[]{1, 2, 3};
	nodes[0].left = &nodes[1];
	nodes[0].right = &nodes[2];
	Node *root = &nodes[0];
	rotate(root);
	EXPECT_EQ(root->left, &nodes[2]);
	EXPECT_EQ(root->right, &nodes[1]);
}

TEST(tree, depth) {
	EXPECT_EQ(0, depth(nullptr));
	Node nodes[]{1, 2, 3};
	EXPECT_EQ(1, depth(&nodes[0]));
	nodes[0].left = &nodes[1];
	EXPECT_EQ(2, depth(&nodes[0]));
	nodes[0].right = &nodes[2];
	Node *root = &nodes[0];
	EXPECT_EQ(2, depth(root));
}

TEST(tree, is_symmetric) {
	EXPECT_TRUE(is_symmetric(nullptr));
	EXPECT_TRUE(is_symmetric(nullptr, nullptr));
	Node nodes[]{1, 2, 3};
	Node *root = &nodes[0];
	EXPECT_TRUE(is_symmetric(root));
	EXPECT_TRUE(is_symmetric(root, root));
	root->left = &nodes[1];
	EXPECT_FALSE(is_symmetric(root));
	root->right = &nodes[2];
	EXPECT_FALSE(is_symmetric(root));
	root->right = root->left;
	EXPECT_TRUE(is_symmetric(root));
}

TEST(tree, has_path_sum) {
	EXPECT_FALSE(has_path_sum(nullptr, 0));
	Node nodes[]{1, 2, 3};
	Node *root = &nodes[0];
	EXPECT_FALSE(has_path_sum(root, 3));
	EXPECT_TRUE(has_path_sum(root, 1));
	root->left = &nodes[1];
	EXPECT_TRUE(has_path_sum(root, 3));
	EXPECT_FALSE(has_path_sum(root, 4));
	root->right = &nodes[2];
	EXPECT_TRUE(has_path_sum(root, 3));
	EXPECT_TRUE(has_path_sum(root, 4));
}

/*

void pre_order2(Node* root) {
	stack<TreeNode*> stack;
	TreeNode* p = root;
	while (p || !stack.empty()) {
		while (p) {
			cout << p->data << endl;
			stack.push(p);
			p = p->left;
		}
		if (!stack.empty()) {
			p = stack.top();
			stack.pop();
			p = p->right;
		}
	}
}

void in_order2(TreeNode* root) {
	stack<TreeNode*> stack;
	TreeNode* p = root;
	while (p || !stack.empty()) {
		while (p) {
			stack.push(p);
			p = p->left;
		}
		if (!stack.empty()) {
			p = stack.top();
			cout << p->data << endl;
			stack.pop();
			p = p->right;
		}
	}
}
void post_order2(TreeNode* root) {
	stack<TreeNode*> stack;
	if (root)
		stack.push(root);
	while (!stack.empty()) {
		TreeNode* pcur = stack.top();
		stack.pop();
		if ((pcur->left == NULL && pcur->right == NULL) ||
				(ppre && (ppre == pcur->left || ppre == pcur->right))) {
			cout << ppcur->data << endl;
			stack.pop();
			ppre = pcur;
		} else {
			if (pcur->right)
				stack.push(pcur->right);
			if (pcur->left)
				stack.push(pcur->left);
		}
	}
}
*/
