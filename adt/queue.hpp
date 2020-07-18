//
//  queue.hpp
//  algorithms
//
//  Created by 云心逸 on 2019/1/8.
//  Copyright © 2019 云心逸. All rights reserved.
//

#ifndef queue_h
#define queue_h

#include <stack>
#include <vector>
#include <memory>

namespace queue {

template <typename T, typename Allocator = std::allocator<T>>
class queue {
public:
	using value_type = T;
	using reference = value_type&;
	using const_reference = const value_type&;
	using allocator_type = Allocator;
	using __allocator_traits = std::allocator_traits<allocator_type>;
	using size_type = typename __allocator_traits::size_type;
	using pointer = typename __allocator_traits::pointer;

	queue(size_type n) noexcept(std::is_nothrow_constructible<allocator_type>::value &&
	                            std::is_nothrow_constructible<pointer>::value)
	try : m_allocator(), m_capacity(n), m_data(m_allocator.allocate(m_capacity)), m_head(0), m_size(0) {}
	catch (...) { /*automatic rethrow*/ }
	queue(queue const &q) = delete;
	queue(queue&& q) noexcept : m_allocator(), m_capacity(0), m_data(), m_head(0), m_size(0) {
		this->swap(q);
	}
	queue& operator=(queue q) noexcept {
		this->swap(q);
		return *this;
	}
	~queue() {
		while (!empty()) deq();
		m_allocator.deallocate(m_data, m_capacity);
	}
	
	void swap(queue& rhs) {
		std::swap(m_allocator, rhs.m_allocator);
		std::swap(m_capacity, rhs.m_capacity);
		std::swap(m_data, rhs.m_data);
		std::swap(m_head, rhs.m_head);
		std::swap(m_size, rhs.m_size);
	}

	size_type size() const { return m_size; }
	bool empty() const { return size() == 0; }
	size_type capacity() const { return m_capacity; }
	void reserve(size_type sz) = delete;
	reference front() { return m_data[m_head]; }
	const_reference front() const { return m_data[m_head]; }
	reference back() { return m_data[(m_head+m_size-1)%m_capacity]; }
	const_reference back() const { return m_data[(m_head+m_size-1)%m_capacity]; }
	void enq(const_reference v) {
		if (size() == capacity()) throw std::runtime_error("overflow");
		m_allocator.construct(m_data + (m_head+m_size)%m_capacity, v);
		++m_size;
	}
	void deq() {
		if (empty()) throw std::runtime_error("underflow");
		m_allocator.destroy(m_data+m_head);
		m_head = (m_head+1)%m_capacity;
		--m_size;
	}
private:
	allocator_type m_allocator;
	size_type m_capacity;
	pointer m_data;// ring buffer
	size_type m_head;
	size_type m_size;
};

template <typename T>
class Q {
public:
	void enq(T v) { m_in_stack.push(v); }
	T deq() {
		if (m_out_stack.empty())
			while (!m_in_stack.empty()) {
				m_out_stack.push(m_in_stack.top());
				m_in_stack.pop();
			}
		T v = m_out_stack.top();
		m_out_stack.pop();
		return v;
	}
	bool empty() const { return m_in_stack.empty() && m_out_stack.empty(); }
private:
	std::stack<T> m_in_stack; // in stack
	std::stack<T> m_out_stack; // out stack
};

template <typename T>
class list_queue {
private:
    struct node {
        T data;
        std::unique_ptr<node> next;
        node(T val) : data(std::move(val)) {}
    };
    std::unique_ptr<node> m_head;
    node* m_tail;
public:
    list_queue() {}
    list_queue(const list_queue&) = delete;
    list_queue& operator=(const list_queue&) = delete;

    void push(T val) {
        std::unique_ptr<node> ptr(new node(std::move(val)));
        const node* tail = ptr.get();
        if (m_tail) m_tail->next = std::move(ptr);
        else m_head = std::move(ptr);
        m_tail = tail;
    }
    std::shared_ptr<T> pop() {
        if (!m_head) return {};
        auto ptr = std::make_shared(std::move<T>(m_head->data));
        const std::unique_ptr<node> head = std::move(head);
        m_head = std::move(head->next);
        return ptr;
    }
};
}

#endif /* queue_h */
