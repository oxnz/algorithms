//
//  arr.hpp
//  algorithms
//
//  Created by 云心逸 on 2019/1/6.
//  Copyright © 2019 云心逸. All rights reserved.
//

#ifndef arr_hpp
#define arr_hpp

#include <memory>

namespace m {
template <typename T, typename Allocator = std::allocator<T>>
class array {
public:
    using size_type = size_t;
    using value_type = T;
    using pointer = value_type*;
    using const_pointer = const pointer;
    using reference = value_type&;
    using const_reference = value_type const&;
    using iterator = pointer;
    using reverse_iterator = std::reverse_iterator<iterator>;
private:
    using __allocator_type = Allocator;
    using __allocator_traits = std::allocator_traits<__allocator_type>;
private:
    __allocator_type m_allocator;
    size_type m_size;
    std::unique_ptr<value_type[]> m_store;
public:
    array(size_type size) : m_size(size), m_store(std::make_unique<value_type[]>(size)) {}
    array(array&) = delete;
    array(array&&) = default;
    array& operator=(array&) = delete;
    array& operator=(array&&) = default;
    
    size_type size() const { return m_size; }
    bool empty() const { return m_size == 0; }
    pointer data() { return m_store.get(); }
    const_pointer data() const { return m_store.get(); }
    reference operator[](size_type i) { return m_store[i]; }
    const_reference operator[](size_type i) const { return m_store[i]; }
    reference at(size_type i) { if (i < size()) return m_store[i];  throw std::out_of_range(__PRETTY_FUNCTION__); }
    const_reference at(size_type i) const { if (i < size()) return m_store[i]; throw std::out_of_range(__PRETTY_FUNCTION__);  }
    
    iterator begin() { return data(); }
    iterator end() { return std::next(data(), size()); }
    
    reverse_iterator rbegin() { return std::make_reverse_iterator(end()); }
    reverse_iterator rend() { return std::make_reverse_iterator(begin()); }
};

}

#endif /* arr_hpp */
