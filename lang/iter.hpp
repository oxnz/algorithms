//
//  iter.hpp
//  algorithms
//
//  Created by 云心逸 on 2019/1/20.
//  Copyright © 2019 云心逸. All rights reserved.
//

#ifndef iter_hpp
#define iter_hpp

#include <iterator>
#include <utility>
#include <numeric>

template <typename Iterable>
class enumerate {
	Iterable& m_iterable;
public:
	using value_type = std::pair<size_t, typename Iterable::value_type>;
    using reference = std::pair<size_t, typename Iterable::reference>;
	class iterator {
		using iter = typename Iterable::iterator;
		using size_type = typename Iterable::size_type;
		iter m_iter;
		size_type m_index;
	public:
        using value_type = enumerate::value_type;
		explicit iterator(iter it) : m_iter(it), m_index(0) {}
		iterator& operator++() {
			++m_index;
			++m_iter;
			return *this;
		}
		iterator operator++(int) { // postfix increment
			iterator iter(*this);
			++m_index;
			++m_iter;
			return iter;
		}
		bool operator==(const iterator& rhs) const { return m_iter == rhs.m_iter; }
		bool operator!=(const iterator& rhs) const { return !(*this == rhs); }
		auto operator*() const { return std::make_pair(m_index, *m_iter); }
	};
public:
    explicit enumerate(Iterable& iter) : m_iterable(iter) {}
	iterator begin() { return  iterator(m_iterable.begin()); }
	iterator end() { return  iterator(m_iterable.end()); }
};

template <typename T>
class sequence {
	T m_start;
	T m_stop;
	T m_step;
public:
	class iterator {
		sequence& m_seq;
        T m_curr;
	public:
		using iterator_category = std::forward_iterator_tag;
		using value_type = T;
		using difference_type = decltype(m_seq.m_stop - m_seq.m_start);
		using reference = T&;
		using pointer = T*;
        iterator(sequence& seq, const T& pos) : m_seq(seq), m_curr(pos) {}
		iterator(sequence& seq) : iterator(seq, seq.start) {}
        bool operator==(const iterator& rhs) const { return m_curr == rhs.m_curr; }
		bool operator!=(const iterator& rhs) const { return !(*this == rhs); }
        iterator& operator++() { m_curr += m_seq.m_step; return *this; }
		iterator operator++(int) {
			iterator iter(*this);
            m_curr += m_seq.m_step;
			return iter;
		}
        auto operator*() const { return m_curr; }
	};
    sequence(const T& start, const T& stop, const T& step)
        : m_start(start), m_stop(stop), m_step(step) {}
    sequence(const T& start, const T& stop)
        : sequence(start, stop, start < stop ? 1 : -1) {}

	iterator begin() { return iterator(*this); }
	iterator end() { return iterator(*this, m_stop); }
};

template <typename InputIterator>
struct Iterator {
    InputIterator m_curr;
    InputIterator m_last;
    Iterator(InputIterator first, InputIterator last) : m_curr(first), m_last(last) {}
    bool hasNext() const {
        return m_curr != m_last;
    }
    typename std::iterator_traits<InputIterator>::value_type next() {
        return *m_curr++;
    }
};

#endif /* iter_hpp */
