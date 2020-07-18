//
//  stack.hpp
//  algorithms
//
//  Created by 云心逸 on 2019/1/8.
//  Copyright © 2019 云心逸. All rights reserved.
//

#ifndef stack_hpp
#define stack_hpp

#include <queue>

namespace stack {
	template <typename T>
	class stack {
		using size_type = size_t;
		using value_type = T;
		using reference = value_type&;
		using const_reference = const value_type&;
	private:
		std::queue<T> m_queue; // pop
	public:
		reference top() { return m_queue.front(); }
		const_reference top() const { return m_queue.front(); }
		void push(const_reference v) {
			m_queue.push(v);
			size_type n = m_queue.size()-1;
			for (size_type i = 0; i < n; ++i) {
				m_queue.push(m_queue.front());
				m_queue.pop();
			}
		}
		void pop() {
			if (empty()) throw std::runtime_error("stack underflow");
			m_queue.pop();
		}
		bool empty() const { return m_queue.empty(); }
		size_type size() const { return m_queue.size(); }
	};

	template <typename T>
	class concurrent_stack {
		struct node {
			T value;
			node* next;
			node(const T& val) : value(val), next(nullptr) {}
		};
		std::atomic<node*> m_top;
	public:
		void push(T val) {
			node* ptr = new node(val);
			ptr->next = m_top.load();
			while (!m_top.compare_exchange_weak(ptr->next, ptr))
				; // if false, ptr->next was updated to new m_top
		}
		void pop(T& val) {
			node* ptr = m_top.load();
			while (m_top && !m_top.compare_exchange_weak(ptr, ptr->next))
				;
			val = std::move(ptr->value);
		}
	};
}

#endif /* stack_hpp */
