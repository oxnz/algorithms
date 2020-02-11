/*
 * Filename:	tree.h
 *
 * Author:		Oxnz
 * Email:		yunxinyi@gmail.com
 * Created:		[2020-02-09 12:46:20 CST]
 * Last-update:	2020-02-09 12:46:20 CST
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

#ifndef _TREE_H_
#define _TREE_H_

#include <map>
#include <list>

template <typename T, typename Compare = std::less<T>, typename Allocator = std::allocator<T>>
class binary_tree {
public:
    using value_type = T;
    using size_type = typename std::allocator_traits<Allocator>::size_type;
private:
    using value_comparator = Compare;
    using __value_allocator_traits = std::allocator_traits<Allocator>;
    using node_type = struct TreeNode {
        TreeNode *left;
        TreeNode *right;
        T value;
    };
    using node_allocator_type = typename __value_allocator_traits::template rebind_alloc<node_type>;
    using __node_allocator_traits = typename std::allocator_traits<node_allocator_type>;
public:
    struct iterator {
        iterator(): m_node(nullptr) {}
        iterator(node_type* p) : m_node(p) {}
    private:
        node_type *m_node;
    };
    
    binary_tree() : m_node_allocator(), m_value_comp(), m_root(), m_size() {}
    size_type size() const { return m_size; }
    bool empty() const { return m_root == nullptr; }
    
    iterator begin() {
        return iterator(m_root);
    }
    
    iterator end() {
        return iterator();
    }
    
    void insert(const T& value) {
        node_type* p = __node_allocator_traits::allocate(m_node_allocator, 1);
        __node_allocator_traits::construct(m_node_allocator, p);
        insert(p);
    }
    void remove(const T& value) {
        node_type **p = find(value);
        if (nullptr == p) return;
        node_type *l = (*p)->left;
        node_type *r = (*p)->right;
        __node_allocator_traits::destroy(m_node_allocator, std::addressof((*p)->value));
        __node_allocator_traits::deallocate(m_node_allocator, *p, 1);
        *p = r;
        std::swap(r->left, l);
        insert(l);
    }
private:
    node_type** find(const T& value) {
        node_type **p = &m_root;
        while (*p) {
            if (m_value_comp((*p)->value, value)) p = &(*p)->left;
            else if (m_value_comp(value, (*p)->value)) p = &(*p)->right;
            else return p;
        }
        return nullptr;
    }
    void insert(node_type* v) {
        insert(v, &m_root);
    }
    void insert(node_type* v, node_type** p) {
        while (*p) {
            if (m_value_comp((*p)->value, v->value)) p = &(*p)->left;
            else p = &(*p)->right;
        }
        *p = v;
        ++m_size;
    }
    void remove(node_type *v) {
        /*
        2
    1       4
        3       5
         */
    }
private:
    node_allocator_type m_node_allocator;
    value_comparator m_value_comp;
    node_type* m_root;
    size_type m_size;
};

#endif//_TREE_H_


