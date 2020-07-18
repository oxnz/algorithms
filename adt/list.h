/*
 * Filename:	list.h
 *
 * Author:		Oxnz
 * Email:		yunxinyi@gmail.com
 * Created:		[2020-02-09 21:15:46 CST]
 * Last-update:	2020-02-09 21:15:46 CST
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

#ifndef _LIST_H_
#define _LIST_H_

#include <list>

namespace m {
template<typename T, typename Allocator = std::allocator<T>>
class list
{
public:
    using value_type = T;
private:
    using node_type = struct node
    {
        node *prev;
        node *next;
        T value;
    };
    using __value_allocator_traits = typename std::allocator_traits<Allocator>;
    using node_allocator_type = typename __value_allocator_traits::template rebind_alloc<node_type>;
    using __node_allocator_traits = typename std::allocator_traits<node_allocator_type>;
    using iterator = struct __iterator
    {
        friend class list;
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type = T;
        using difference_type = int;
        using pointer = T *;
        using reference = T &;
        __iterator(node_type *p) : __ptr(p) {}
        __iterator(const __iterator &o) : __ptr(o.__ptr) {}
        __iterator() : __ptr(nullptr) {}
        __iterator &operator=(const __iterator &o)
        {
            __ptr = o.__ptr;
            return *this;
        }
        __iterator &operator++()
        {
            __ptr = __ptr->next;
            return *this;
        }
        __iterator &operator--()
        {
            __ptr = __ptr->prev;
            return *this;
        }
        __iterator operator++(int)
        {
            __iterator it(*this);
            ++(*this);
            return it;
        }
        __iterator operator--(int)
        {
            __iterator it(*this);
            ++(*this);
            return it;
        }
        T *operator->() const { return std::addressof(__ptr->value); }
        T &operator*() const { return __ptr->value; }
        bool operator==(const __iterator &o) const { return __ptr == o.__ptr; }
        bool operator!=(const __iterator &o) const { return !(*this == o); }
        void swap(__iterator &o) { std::swap(__ptr, o.__ptr); }
        friend void swap(const __iterator &l, const __iterator &r) { l.swap(r); }
        
    private:
        node_type *__ptr;
    };
    using const_iterator = const iterator;
    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = const reverse_iterator;
public:
    using size_type = typename __value_allocator_traits::size_type;
    list() : m_size(), m_head(), m_rear(), m_node_allocator() {}
    list(list&) = delete;
    list(list&&) = default;
    list& operator=(list&) = delete;
    list& operator=(list&&) = default;
    ~list() { clear(); }
    
    size_type size() const { return m_size; }
    bool empty() const { return m_size == 0; }
    void clear() { while(!empty()) pop_front(); }
    
public:
    iterator push_front(const T &v) { return insert(begin(), v); }
    iterator push_back(const T &v) { return insert(end(), v); }
    T &front() { return m_head->value; }
    T &back() { return m_rear->value; }
    const T &front() const { return m_head->value; }
    const T &back() const { return m_rear->value; }
    void pop_front() { erase(m_head); }
    void pop_back() { erase(m_rear); }
    iterator find(const T &v) const { return std::find(begin(), end(), v); }
    iterator insert(const_iterator position, const value_type& x);
    iterator erase(const_iterator it);
    
public:
    iterator begin() { return m_head; }
    iterator end() { return nullptr; }
    const_iterator begin() const { return m_head; }
    const_iterator end() const { return nullptr; }

    reverse_iterator rbegin() { return reverse_iterator(end()); }
    reverse_iterator rend() { return reverse_iterator(begin()); }
    const_reverse_iterator crbegin() const { return const_reverse_iterator(end()); }
    const_reverse_iterator crend() const { return const_reverse_iterator(begin()); }
    
private:
    size_type m_size;
    node_type *m_head;
    node_type *m_rear;
    node_allocator_type m_node_allocator;
};

template<typename T, typename Allocator>
inline typename list<T, Allocator>::iterator list<T, Allocator>::insert(const_iterator it, const value_type& v) {
    auto p = __node_allocator_traits::allocate(m_node_allocator, 1);
    __node_allocator_traits::construct(m_node_allocator, std::addressof(p->value), v);
#ifdef DEBUG
    printf("insert <%p>[%d], sz=%lu\n", p, v, m_size);
#endif
    if (m_size == 0) {
        p->prev = p->next = nullptr;
        m_head = m_rear = p;
        ++m_size;
        return p;
    }
    p->next = it.__ptr;
    if (!p->next) { // push back
        p->prev = m_rear;
        m_rear->next = p;
        m_rear = p;
    } else if (p->next == m_head) { // push front
        p->prev = nullptr;
        m_head->prev = p;
        m_head = p;
    } else { // insert
        p->prev = p->next->prev;
        p->prev->next = p;
        p->next->prev = p;
    }
    ++m_size;
    return p;
}

template<typename T, typename Allocator>
inline typename list<T, Allocator>::iterator list<T, Allocator>::erase(list::const_iterator it)
{
    node_type* p = it.__ptr;
#ifdef DEBUG
    printf("free %p, v: %d\n", p, p->value);
#endif
    if (p == nullptr) throw std::runtime_error("non-dereferenceable iterator");
    switch ((p->prev == nullptr ? 0b00 : 0b10) | (p->next == nullptr ? 0b00 : 0b01)) {
        case 0b00:
            m_head = m_rear = nullptr;
            break;
        case 0b01:
            m_head = p->next;
            m_head->prev = 0;
            break;
        case 0b10:
            m_rear = p->prev;
            m_rear->next = 0;
            break;
        case 0b11:
            p->prev->next = p->next;
            p->next->prev = p->prev;
            break;
    }
    p = p->next;
    __node_allocator_traits::destroy(m_node_allocator, std::addressof(*it));
    __node_allocator_traits::deallocate(m_node_allocator, it.__ptr, 1);
    --m_size;
    return p;
}
} // namespace m

#endif //_LIST_H_
