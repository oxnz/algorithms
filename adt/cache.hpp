#ifndef CACHE_HPP
#define CACHE_HPP

#include <list>
#include <utility>
#include <unordered_map>

namespace cache {

template <typename Key, typename Value>
class LRUCache {
    using Entry = std::pair<Key, Value>;
    using size_type = size_t;
private:
    size_type m_capacity;
    std::list<Entry> m_cache;
    std::unordered_map<Key, typename std::list<Entry>::iterator> m_hash;
public:
    LRUCache(size_type capacity) : m_capacity(capacity) {
        m_hash.reserve(capacity);
    }

    Value get(const Key& key) {
        auto it = m_hash.find(key);
        if (it == m_hash.end()) return -1;
        m_cache.splice(m_cache.begin(), m_cache, it->second);
        return it->second->second;
    }

    void put(const Key& key, const Value& value) {
        const auto it = m_hash.find(key);
        if (it != m_hash.end()) {
            m_cache.splice(m_cache.begin(), m_cache, it->second);
            it->second->second = value;
            return;
        }
        if (m_cache.size() == m_capacity) {
            m_hash.erase(m_cache.back().first);
            m_cache.pop_back();
        }
        m_cache.emplace_front(key, value);
        m_hash[key] = m_cache.begin();
    }
};

}

#endif // CACHE_HPP
