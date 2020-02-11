///*
// * Filename:	trie.c
// *
// * Author:		Oxnz
// * Email:		yunxinyi@gmail.com
// * Created:		2015-09-03 20:43:57 CST
// * Last-update:	2015-09-03 20:43:57 CST
// * Description: anchor
// *
// * Version:		0.0.1
// * Revision:	[NONE]
// * Revision history:	[NONE]
// * Date Author Remarks:	[NONE]
// *
// * License:
// * Copyright (c) 2015 Oxnz
// *
// * Distributed under terms of the [LICENSE] license.
// * [license]
// *
// */
//
//#include <iostream>
//#include <gtest/gtest.h>
//
//#define MAX_CHAR 26 // 字符集大小
//#define MAX_CNT 1000000L
//
//namespace Trie {
//	class Node {
//	public:
//		static Node* createNode() {
//			// zero-initialized, cause no user-provided default constructor
//			static Node SharedMemory[MAX_CNT];
//			static size_t allocp; // static is initialized to zero
//			if (allocp >= MAX_CNT) throw new std::bad_alloc;
//			Node *p = &SharedMemory[allocp++];
//			p->count = 1;
//			return p;
//		}
//	public:
//		size_t count; // number of occurence of this char
//		Node* next[MAX_CHAR];
//	};
//
//	class Trie {
//	public:
//		Trie() : root(nullptr) {}
//
//		void insert(const std::string& s) {
//			Node *p = root;
//			if (nullptr == p) p = root = Node::createNode();
//			for (const auto& c : s) {
//				int index = c - 'a';
//				if (nullptr != p->next[index]) ++p->next[index]->count;
//				else p->next[index] = Node::createNode();
//				p = p->next[index];
//			}
//		}
//
//		size_t search(const std::string& s) const {
//			Node *p = root;
//			if (nullptr == p) return 0;
//			for (const auto& c : s) {
//				int index = c - 'a';
//				if (nullptr == p->next[index]) return 0;
//				p = p->next[index];
//			}
//			return p->count;
//		}
//	private:
//		Node *root;
//	};
//}
//
//TEST(trie, trie) {
//	Trie::Trie t;
//	t.insert("hello");
//	t.insert("world");
//	EXPECT_EQ(t.search("h"), 1) << "search(h) != 1";
//	EXPECT_EQ(t.search("hell"), 1) << "search(hell) != 1";
//	EXPECT_EQ(t.search("w"), 1) << "search(w) != 1";
//	EXPECT_EQ(t.search("o"), 0) << "search(o) != 0";
//}
