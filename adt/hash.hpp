//
//  hash.hpp
//  algorithms
//
//  Created by 云心逸 on 2019/1/9.
//  Copyright © 2019 云心逸. All rights reserved.
//

#ifndef hash_hpp
#define hash_hpp

#include <list>
#include <vector>
#include <shared_mutex>

template <typename Key, typename Value, typename Hash = std::hash<Key>>
class concurrent_map {
public:
	using size_type = size_t;
	using key_type = Key;
	using value_type = Value;
	using hash_type = Hash;
private:
    struct bucket {
    private:
        using entry = std::pair<Key, Value>;
        using list_type = std::list<entry>;
		using iterator = typename list_type::iterator;

        list_type m_list;
        mutable std::shared_mutex m_mutex;
        iterator find_entry(const Key& key) const {
			return std::find_if(m_list.begin(), m_list.end(), [&key] (const entry& entry) {
				return key == entry.first;
			});
        }
	public:
		Value at(const Key& key, const Value& default_value) const {
			std::shared_lock<std::shared_mutex> slock(m_mutex);
			iterator it = find_entry(key);
			return it != m_list.end() ? it->second : default_value;
		}
		void upsert(const Key& key, const Value& val) {
			std::unique_lock<std::shared_mutex> xlock(m_mutex);
			iterator it = find_entry(key);
			if (it != m_list.end()) {
				it->second = val;
			} else {
				m_list.emplace_back(key, val);
			}
		}
		void erase(const Key& key) {
			std::unique_lock<std::shared_mutex> xlock(m_mutex);
			iterator it = find_entry(key);
			if (it != m_list.end()) {
				m_list.erase(it);
			}
		}
    };
	std::vector<std::unique_ptr<bucket>> m_buckets;
	Hash m_hash;
	bucket& get_bucket(const Key& key) const {
		return *m_buckets[m_hash(key)];
	}
public:
	concurrent_map(size_type nbucket = 19,
				   const hash_type& hash = Hash())
	: m_buckets(nbucket), m_hash(hash) {
		for (auto& ptr : m_buckets) {
			ptr.reset(new bucket);
		}
	}
	concurrent_map(const concurrent_map&) = delete;
	concurrent_map& operator=(concurrent_map) = delete;

	value_type at(const key_type& key) const {
		return get_bucket(key).at(key);
	}
	void upsert(const key_type& key, const value_type& val) {
		get_bucket(key).upsert(key, val);
	}
	void erase(const key_type& key) {
		get_bucket(key).erase(key);
	}
	
};

#endif /* hash_hpp */
