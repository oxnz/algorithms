#include <iostream>
#include <stack>
#include <queue>

#include "adt.hpp"

#include <gtest/gtest.h>

using namespace std;

using Node = binary_tree::TreeNode<int>;

bool has_path_sum(const Node *p, int v) { // path: root to leaf
	if (nullptr == p) return false;
	if (nullptr == p->left && nullptr == p->right) return v == p->value;
	return has_path_sum(p->left, v-p->value) || has_path_sum(p->right, v-p->value);
}

template <typename T>
bool contains(binary_tree::TreeNode<T>* root, const T& val) {
	if (root == nullptr) return false;
	return root->value == val || contains(root->left, val) || contains(root->right, val);
}

template <typename T>
binary_tree::TreeNode<T>* lowest_common_ancestor(binary_tree::TreeNode<T>* root, binary_tree::TreeNode<T>* p, binary_tree::TreeNode<T>* q) {
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
	auto tree = binary_tree::build::by_inorder_and_postorder(inorder, postorder);
	EXPECT_NE(nullptr, tree);
	EXPECT_EQ(3, tree->value);
	EXPECT_EQ(9, tree->left->value);
	EXPECT_EQ(nullptr, tree->left->left);
	EXPECT_EQ(nullptr, tree->left->right);
	EXPECT_EQ(20, tree->right->value);
	EXPECT_EQ(15, tree->right->left->value);
	EXPECT_EQ(7, tree->right->right->value);
	vector<int> iv{1, 2}, pv{2, 1};
	tree = binary_tree::build::by_inorder_and_postorder(iv, pv);
	EXPECT_NE(nullptr, tree);
	EXPECT_EQ(nullptr, tree->left);
	EXPECT_EQ(2, tree->right->value);
	iv = {2, 3, 1};
	pv = {3, 2, 1};
	tree = binary_tree::build::by_inorder_and_postorder(iv, pv);
	EXPECT_NE(nullptr, tree);
	EXPECT_EQ(2, tree->left->value);
	EXPECT_EQ(3, tree->left->right->value);
}

TEST(tree, build_tree_by_preorder_inorder) {
	vector<int> pv{3,9,20,15,7}, iv{9,3,15,20,7};
	auto tree = binary_tree::build::by_preorder_and_inorder(pv, iv);
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
	binary_tree::traverse::recursive::pre(p, accessor);
	EXPECT_EQ(prev, v);
	v.clear();
	binary_tree::traverse::pre(p, accessor);
	EXPECT_EQ(prev, v) << "non recursive pre order traverse";
	v.clear();
	binary_tree::traverse::recursive::in(p, accessor);
	EXPECT_EQ(midv, v);
	v.clear();
	binary_tree::traverse::in(p, accessor);
	EXPECT_EQ(midv, v) << "in order traverse";
	v.clear();
	binary_tree::traverse::recursive::post(p, accessor);
	EXPECT_EQ(postv, v);
	v.clear();
	binary_tree::traverse::level(p, accessor);
	EXPECT_EQ(levelv, v) << "level order";
}

TEST(tree, codec) {
	Node nodes[]{1,2,3,4,5,6};
	nodes[0].right = &nodes[1];
	nodes[1].left = &nodes[2];
	nodes[1].right = &nodes[3];
	nodes[2].left = &nodes[4];
	nodes[2].right = &nodes[5];
	auto root = &nodes[0];
	auto s = binary_tree::codec::serialize(root);
	auto p = binary_tree::codec::deserialize<int>(s);
	EXPECT_NE(nullptr, p);
	EXPECT_EQ(p->value, root->value);
	EXPECT_EQ(binary_tree::codec::serialize(p), s);
}

TEST(tree, rotate) {
	Node nodes[]{1, 2, 3};
	nodes[0].left = &nodes[1];
	nodes[0].right = &nodes[2];
	Node *root = &nodes[0];
	binary_tree::operate::rotate(root);
	EXPECT_EQ(root->left, &nodes[2]);
	EXPECT_EQ(root->right, &nodes[1]);
}

TEST(tree, depth) {
	EXPECT_TRUE(0 == binary_tree::depth<int>(nullptr));
	Node nodes[]{1, 2, 3};
	EXPECT_EQ(1, binary_tree::depth(&nodes[0]));
	nodes[0].left = &nodes[1];
	EXPECT_EQ(2, binary_tree::depth(&nodes[0]));
	nodes[0].right = &nodes[2];
	Node *root = &nodes[0];
	EXPECT_EQ(2, binary_tree::depth(root));
}

TEST(tree, is_symmetric) {
	EXPECT_TRUE(binary_tree::is_symmetric<int>(nullptr));
	EXPECT_TRUE(binary_tree::_is_symmetric<int>(nullptr, nullptr));
	Node nodes[]{1, 2, 3};
	Node *root = &nodes[0];
	EXPECT_TRUE(binary_tree::is_symmetric(root));
	EXPECT_TRUE(binary_tree::_is_symmetric(root, root));
	root->left = &nodes[1];
	EXPECT_FALSE(binary_tree::is_symmetric(root));
	root->right = &nodes[2];
	EXPECT_FALSE(binary_tree::is_symmetric(root));
	root->right = root->left;
	EXPECT_TRUE(binary_tree::is_symmetric(root));
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

TEST(tree, is_balanced) {
	Node nodes[]{3, 9, 20, 15, 7};
	Node *root = &nodes[0];
	root->left = &nodes[1];
	root->right = &nodes[2];
	root->right->left = &nodes[3];
	root->right->right = &nodes[4];
	EXPECT_TRUE(binary_tree::bst::is_balanced(root));
}

#include <fstream>

TEST(trie, perf) {
//	cout << "------------trie perf-------------\n";
//	ifstream ifs("/usr/share/dict/words", ifstream::in);
//	trie::trie root;
//	for(string s; ifs.good(); ) {
//		ifs >> s;
//		root.insert(s);
//	}
//	cout << "size: " << root.size() << ", word count: " << root.word_count()
//	<< "\n";
//	cout << "==================================\n";
}

TEST(trie, trie) {
    trie::static_trie t;
	t.insert("hello");
	t.insert("world");
	EXPECT_EQ(t.search("h"), 1) << "search(h) != 1";
	EXPECT_EQ(t.search("hell"), 1) << "search(hell) != 1";
	EXPECT_EQ(t.search("w"), 1) << "search(w) != 1";
	EXPECT_EQ(t.search("o"), 0) << "search(o) != 0";
}
