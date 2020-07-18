//
//  heap.hpp
//  Interview
//
//  Created by 云心逸 on 2019/1/2.
//  Copyright © 2019 Errpro,Inc. All rights reserved.
//

#ifndef heap_hpp
#define heap_hpp

#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

<<<<<<< HEAD
template <typename T, typename Comparator=std::less<T>, typename Allocator = std::allocator<T>>
class heap {
public:
	using value_type = T;
	using allocator_type = Allocator;
	using reference = value_type&;
	using const_reference = const value_type&;
	using __allocator_traits = std::allocator_traits<allocator_type>;
	using size_type = typename __allocator_traits::size_type;
	using pointer = typename __allocator_traits::pointer;
	
	heap() noexcept(std::is_nothrow_default_constructible_v<allocator_type> &&
					std::is_nothrow_default_constructible<pointer>::value)
    : m_allocator(), m_storage(), m_size(), m_capacity() {}
    heap(heap&) = delete;
    heap(heap&&) = default;
    heap& operator=(heap&) = delete;
    heap& operator=(heap&&) = default;
	~heap() {
		for (auto i = 0; i < m_size; ++i)
			m_allocator.destroy(m_storage+i);
		m_allocator.deallocate(m_storage, m_capacity);
	}
	
	void push(const T& value) {
        if (m_size == m_capacity) reserve(m_size == 0 ? 1 : m_size<<1);
		m_allocator.construct(m_storage+m_size, value);
		++m_size;
	}
	void push(T&& value) {
        if (m_size == m_capacity) reserve(m_size == 0 ? 1 : m_size<<1);
		m_allocator.construct(m_storage+m_size, std::move(value));
		++m_size;
	}
	template <typename ...Args>
	void emplace(Args&&... args) {
        if (m_size == m_capacity) reserve(m_size == 0 ? 1 : m_size<<1);
		m_allocator.construct(m_storage+m_size, std::forward<Args...>(args...));
		++m_size;
	}
    void reserve(size_type n) {
        if (n <= m_capacity) return;
        pointer storage = m_allocator.allocate(n);
        for (size_type i = 0; i < m_size; ++i) {
            m_allocator.construct(storage + i, std::move(m_storage[i]));
            m_allocator.destroy(m_storage + i);
        }
        m_storage = storage;
        m_capacity = n;
    }
	size_type size() const { return m_size; }
	size_type capacity() const { return m_capacity; }
    const_reference operator[](size_type i) const { return m_storage[i]; }
	const_reference at(size_type i) const {
        if (! i < m_size) throw std::out_of_range(__PRETTY_FUNCTION__);
		return m_storage[i];
	}
    const_reference top() const { return m_storage[0]; }

private:

private:
	allocator_type m_allocator;
    Comparator m_comp;
	pointer	m_storage;
	size_type m_size;
	size_type m_capacity;
};
=======
namespace heap {
	template <typename T, typename Allocator = std::allocator<T>>
	class heap {
	public:
		using value_type = T;
		using allocator_type = Allocator;
		using reference = value_type&;
		using const_reference = const value_type&;
		using __allocator_traits = std::allocator_traits<allocator_type>;
		using size_type = typename __allocator_traits::size_type;
		using pointer = typename __allocator_traits::pointer;
		
		heap() noexcept(std::is_nothrow_default_constructible<allocator_type>::value &&
						std::is_nothrow_default_constructible<pointer>::value)
		: m_allocator(), m_storage(), m_size(0), m_capacity(0) {}
		~heap() {
			for (auto i = 0; i < m_size; ++i)
				m_allocator.destroy(m_storage+i);
			m_allocator.deallocate(m_storage, m_capacity);
		}
		
		void push(const T& value) {
			if (m_size + 1 > m_capacity) reserve(m_size == 0 ? 1 : m_size<<1);
			m_allocator.construct(m_storage+m_size, value);
			++m_size;
		}
		void push(T&& value) {
			if (m_size + 1 > m_capacity) reserve(m_size == 0 ? 1 : m_size<<1);
			m_allocator.construct(m_storage+m_size, std::move(value));
			++m_size;
		}
		template <typename ...Args>
		void emplace(Args&&... args) {
			if (m_size + 1 > m_capacity) reserve(m_size == 0 ? 1 : m_size<<1);
			m_allocator.construct(m_storage+m_size, std::forward<Args...>(args...));
			++m_size;
		}
		void reserve(size_type n) {
			if (n <= m_capacity) return;
			if (m_size == 0) {
				m_storage = m_allocator.allocate(n);
				m_capacity = n;
				return;
			}
			pointer storage = m_allocator.allocate(n);
			try {
				std::uninitialized_copy(m_storage, m_storage+m_size, storage);
			} catch (...) {
				m_allocator.deallocate(storage, n);
				throw;
			}
			for (size_type i = 0; i < m_size; ++i)
				m_allocator.destroy(m_storage+i);
			m_storage = storage;
			m_capacity = n;
		}
		size_type size() const { return m_size; }
		size_type capacity() const { return m_capacity; }
		const_reference operator[](size_type i) const {
			return m_storage[i];
		}
		const_reference at(size_type i) const {
			if (! i < m_size) throw std::out_of_range("heap");
			return m_storage[i];
		}
		const_reference top() const {
			return m_storage[0];
		}
		
	private:
		allocator_type m_allocator;
		pointer	m_storage;
		size_type m_size;
		size_type m_capacity;
	};
}
>>>>>>> ab703f00fc1e1002e956538795856139bd1ae5e4

#endif /* heap_hpp */
