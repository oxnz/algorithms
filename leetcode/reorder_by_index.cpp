//
//  reorder_by_index.cpp
//  leetcode
//
//  Created by Max Zhang on 2020/2/21.
//

#include "leetcode.hpp"

template <typename T>
void reorder_by_indexes_v1(std::vector<T>& v, std::vector<size_t>& indexes) {
    for (size_t i = 0; i < indexes.size(); ++i) {
        size_t idx = i;
        for (; i != indexes[idx]; ) {
            std::swap(v[idx], v[indexes[idx]]);
            std::swap(idx, indexes[idx]);
        }
        indexes[idx] = idx;
    }
}

template <typename T>
void reorder_by_indexes(std::vector<T>& v, std::vector<size_t>& indexes) {
    for (size_t i = 0; i < indexes.size();) {
        auto p = indexes[i];
        if (i != p) {
            std::swap(v[indexes[i]], v[indexes[p]]);
            std::swap(indexes[i], indexes[p]);
        } else ++i;
    }
}

template <typename Iter>
/**
 * @brief reorder_by_indexes
 * time complexity: O(n)
 * @param first
 * @param indexes
 */
void reorder_by_indexes(Iter first, std::vector<Iter> indexes) {
    for (size_t i = 0; i < indexes.size();) {
        size_t p = std::distance(first, indexes[i]);
        if (i != p) {
            std::iter_swap(indexes[i], indexes[p]);
            std::swap(indexes[i], indexes[p]);
        } else ++i;
    }
}

TEST(reorder_by_index, case_1) {
    std::vector<int> v = {24, 56, 74, -23, 87, 89}, expected = {56, 74, -23, 24, 87, 89};
    std::vector<size_t> indexes = {1, 2, 3, 0, 4, 5};
    reorder_by_indexes(v, indexes);
    EXPECT_EQ(v, expected);
}

TEST(reorder_by_index, case_2) {
    std::vector<int> v = {10, 11, 12}, expected = {11, 10, 12};
    std::vector<size_t> indexes = {1, 0, 2};
    reorder_by_indexes(v, indexes);
    EXPECT_EQ(v, expected);
}

TEST(reorder_by_index_v1, random) {
    std::vector<size_t> v;
    size_t n = 1<<10;
    for (size_t i = 0; i < n; ++i) v.emplace_back(i);
    std::shuffle(v.begin(), v.end(), std::mt19937());
    std::vector<int> in;
    std::generate_n(std::back_inserter(in), n, std::mt19937());
    auto oi = in;
    auto ov = v;
    reorder_by_indexes_v1(in, v);
    for (size_t i = 0; i < v.size(); ++i)
        EXPECT_EQ(in[i], oi[ov[i]]);
}

TEST(reorder_by_index, random) {
    std::vector<size_t> v;
    size_t n = 1<<10;
    for (size_t i = 0; i < n; ++i) v.emplace_back(i);
    std::shuffle(v.begin(), v.end(), std::mt19937());
    std::vector<int> in;
    std::generate_n(std::back_inserter(in), n, std::mt19937());
    auto oi = in;
    auto ov = v;
    reorder_by_indexes(in, v);
    for (size_t i = 0; i < v.size(); ++i)
        EXPECT_EQ(in[i], oi[ov[i]]);
}

TEST(reorder_by_index, random_iter) {
    size_t n = 1<<10;
    std::vector<int> in;
    std::generate_n(std::back_inserter(in), n, std::mt19937());
    std::vector<std::vector<int>::iterator> indexes;
    std::vector<size_t> v;
    for (size_t i = 0; i < n; ++i) v.emplace_back(i);
    std::shuffle(v.begin(), v.end(), std::mt19937());
    for (auto i : v) indexes.push_back(std::next(in.begin(), i));
    auto oi = in;
    auto ov = v;
    reorder_by_indexes(in.begin(), indexes);
    for (size_t i = 0; i < v.size(); ++i)
        EXPECT_EQ(in[i], oi[ov[i]]);
}
