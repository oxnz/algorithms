//
//  bitmap.hpp
//  algorithms
//
//  Created by Max Zhang on 2020/2/10.
//

#ifndef bitmap_hpp
#define bitmap_hpp

#include <cstdio>
#include <cstddef>
#include <memory>
#include <bitset>
#include <vector>

template <typename Unit=uint64_t, typename Allocator=std::allocator<Unit>>
class bitvec {
    using size_type = size_t;
    using value_type = Unit;
    using iterator = class __iterator {
        size_type __index;
    public:
        using iterator_category = std::bidirectional_iterator_tag;
        __iterator(size_type index) : __index(index) {}
        bool operator==(const __iterator& o) { return __index == o.__index; }
        bool operator!=(const __iterator& o) { return ! (*this == o); }
        __iterator& operator++() { ++__index; return *this; }
        __iterator operator++(int) { return __index++; }
        __iterator& operator--() { --__index; return *this; }
        __iterator operator--(int) { return __index--; }
    };
    using reverse_iterator = std::reverse_iterator<__iterator>;
    size_type m_size;
    size_type m_capacity;
    std::unique_ptr<std::byte[]> m_store;
public:
    bitvec(size_type capacity) : m_size(), m_capacity(capacity), m_store(std::make_unique<std::byte[]>(capacity)) {}
    bitvec(bitvec&) = delete;
    bitvec(bitvec&&) = default;
    bitvec& operator=(bitvec&) = delete;
    bitvec& operator=(bitvec&&) = default;
    
    size_type size() const { return m_size; }
    size_type capacity() const { return m_capacity; }
    bool empty() const { return size() == 0; }
    
    bool test(size_type index) const {
        
    }
    void set(size_type index) {
        
    }
    void clear(size_type index) {
        
    }
    bool flip(size_type index) {
        
    }

    friend std::istream operator>>(std::istream&is, bitvec&);
    friend std::ostream operator<<(std::ostream&os, const bitvec& m);
};

#endif /* bitmap_hpp */
