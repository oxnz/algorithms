/*
 * Filename:	trie.h
 *
 * Author:		Oxnz
 * Email:		yunxinyi@gmail.com
 * Created:		[2020-02-13 01:09:55 CST]
 * Last-update:	2020-02-13 01:09:55 CST
 * Description: anchor
 *
 * Version:		0.0.1
 * Revision:	[NONE]
 * Revision history:	[NONE]
 * Date Author Remarks:	[NONE]
 *
 * License: 
 * Copyright (c) 2013 Oxnz
 *
 * Distributed under terms of the [LICENSE] license.
 * [license]
 *
 */

#ifndef _TRIE_H_
#define _TRIE_H_

#include <memory>
#include <string>
#include <cstring>
#include <iostream>

namespace m {

template <size_t N>
class trie {
    using size_type = size_t;

private:
    using node_type = struct __node {
        __node() : count() {
            for (size_type i = 0; i < N; ++i) children[i] = nullptr;
        }
        ~__node() {
            for (size_type i = 0; i < N; ++i)
                if (children[i]) delete children[i];
        }
        bool empty() const { return next() == nullptr; }
        __node* next(int i=0) const {
            for (; i < N; ++i) if (children[i]) return children[i];
            return nullptr;
        }
        size_type count;
        __node* children[N];
    };
    static int ord(int c)  { return ::tolower(c) - 'a'; }
    static char chr(int i)  { return i + 'a'; }
public:
    using iterator = struct __iterator {
        __iterator(__node* root, const std::string& prefix) : root(root), prefix(prefix) {}
        __iterator() : root(nullptr) {}
        __iterator& operator++() {
            if (root == nullptr) throw std::out_of_range(__PRETTY_FUNCTION__);
            auto p = root;
//            for (; p;) {
//                if (p->empty()) {
//                    if (prefix.empty()) {
//                        root = nullptr;
//                        return *this;
//                    }
//                }
//            }

        }
        const std::string operator*() {
            return prefix;
        }
        bool operator==(const __iterator& o) const {
            return root == o.root && prefix == o.prefix;
        }
        bool operator!=(const __iterator& o) const {
            return !(*this == o);
        }
        std::string prefix;
        __node* root;
    };
public:
    friend std::ostream& operator<<(std::ostream& os, const trie& t) {
        os << "trie<" << std::addressof(t) << ">\n";
        os << "root" << "\n";
        return os;
    }
public:
    trie() : m_root() {}

    iterator begin() { return iterator(&m_root, ""); }
    iterator end() { return iterator(); }

    void insert(const std::string &s) {
        auto p = &m_root;
        for (auto c : s) {
            auto i = ord(c);
            if (p->children[i] == nullptr) p->children[i] = new __node();
            p = p->children[i];
            ++(p->count);
        }
    }
    size_type count(const std::string& s) const {
        auto p = &m_root;
        for (auto c : s) {
            auto i = ord(c);
            p = p->children[i];
            if (p == nullptr) return 0;
        }
        return p->count;
    }
private:
    __node m_root;
};

}
#endif//_TRIE_H_


