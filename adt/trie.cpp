/*
 * Filename:	trie.c
 *
 * Author:		Oxnz
 * Email:		yunxinyi@gmail.com
 * Created:		2015-09-03 20:43:57 CST
 * Last-update:	2015-09-03 20:43:57 CST
 * Description: anchor
 *
 * Version:		0.0.1
 * Revision:	[NONE]
 * Revision history:	[NONE]
 * Date Author Remarks:	[NONE]
 *
 * License:
 * Copyright (c) 2015 Oxnz
 *
 * Distributed under terms of the [LICENSE] license.
 * [license]
 *
 */

#include <iostream>

#define MAX_CHAR 26 // 字符集大小
#define MAX_CNT 1000000L

namespace Trie {
	class Node {
	public:
		static Node* createNode() {
			static Node SharedMemory[MAX_CNT];
			static int allocp = 0;
			if (allocp >= MAX_CNT) {
				std::cerr << "MAX_CNT REACHED" << std::endl;
				return 0;
			}
			Node *p = &SharedMemory[allocp++];
			p->count = 1;
			for (int i = 0; i < MAX_CHAR; ++i) {
				p->next[i] = 0;
			}
			return p;
		}
	public:
		int count;	// 记录该字符出现次数
		Node* next[MAX_CHAR];
	};


	class Trie {
	public:
		Trie() : root(0) {}

		void insert(const char *s) {
			Node *p = root;
			if (!p) {
				p = root = Node::createNode();
			}
			for (int i = 0; s[i]; ++i) {
				int index = s[i] - 'a';
				if (p->next[index]) {
					++p->next[index]->count;
				} else {
					p->next[index] = Node::createNode();
				}
				p = p->next[index];
			}
		}

		int search(const char* s) {
			Node *p = root;
			if (!p) {
				return 0;
			}
			for (int i = 0; s[i]; ++i) {
				int index = s[i] - 'a';
				if (!p->next[index]) {
					return 0;
				}
				p = p->next[index];
			}
			return p->count;
		}
	private:
		Node *root;
	};
}

int main(int argc, char *argv[]) {
	Trie::Trie t;
	t.insert("hello");
	t.insert("he");
	std::cout << "search(\"h\")" << t.search("h") << std::endl
		<< "search(\"hell\")" << t.search("hell") << std::endl
		<< "search(\"w\")" << t.search("w") << std::endl;

	return 0;
}
