#include "cache.hpp"

#include <string>
#include <gtest/gtest.h>

TEST(LRU_Cache, LRU_Cache) {
    cache::LRUCache<std::string, std::string> cache(10);
    const std::string key = "Hello";
    const std::string value = "world";
    cache.put(key, value);
}
