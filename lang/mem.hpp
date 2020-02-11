//
//  mem.hpp
//  lang
//
//  Created by Max Zhang on 2020/2/10.
//

#ifndef mem_hpp
#define mem_hpp

#include <cstdio>
#include <vector>
#include <unordered_map>

namespace m {
template <typename T>
class mem_pool {
    using index = int;
    using size_type = size_t;
    using value_type = T;
    using pointer = value_type*;
    
    std::unordered_map<index, bool> m_map;
    size_type m_capacity;
    std::unique_ptr<value_type[]> m_store;
public:
    mem_pool(size_type capacity) : m_capacity(capacity), m_store(std::make_unique<value_type>(capacity)) {}
    mem_pool(mem_pool&) = delete;
    mem_pool(mem_pool&&) = default;
    mem_pool& operator=(mem_pool&) = delete;
    mem_pool& operator=(mem_pool&&) = default;

    size_type size() const { return m_map.size(); }
    size_type capacity() const { return m_capacity; }
    bool empty() const { return m_map.empty(); }
    void used(index idx) { m_map[idx] = true; }
    void free(index idx) { m_map.erase(idx); }
    pointer acquire() {
    }
    void  release(pointer ptr) {
    }
};

}
#endif /* mem_hpp */
