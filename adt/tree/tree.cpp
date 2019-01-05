#include <iostream>
#include <stack>
#include <queue>

#include "../adt.h"

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

TEST(traverse, traverse) {
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
