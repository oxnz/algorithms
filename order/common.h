#ifndef COMMON_H
#define COMMON_H

#include <vector>
#include <random>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <benchmark/benchmark.h>
#include <gtest/gtest.h>

class random_generator {
public:
    random_generator() : m_random_dev(), m_engine(m_random_dev()), m_dist(0, 1<<3) {}
    int operator()() {
        return m_dist(m_engine);
    }
private:
    std::random_device m_random_dev;
    std::mt19937 m_engine;
    std::uniform_int_distribution<int> m_dist;
};

namespace m {

template <typename ForwardAccessIterator>
void echo(ForwardAccessIterator first, ForwardAccessIterator last) {
    for (; first != last; ++first) std::cout << *first << ' ';
}

template <typename T>
void print_array(T a[], size_t n) {
    m::echo(a, a+n);
}

template <typename Fn>
inline void verify_sort_algo(Fn fn, size_t size=1<<10, size_t nloop=1) {
    std::vector<int> v;
    std::generate_n(std::back_inserter(v), size, random_generator());
    do {
        fn(v.begin(), v.end());
        EXPECT_TRUE(std::is_sorted(v.begin(), v.end()));
        std::shuffle(v.begin(), v.end(), std::mt19937_64());
    } while (--nloop > 0);
}

}

template <typename Sort>
void BM_sorting(benchmark::State& state) {
    Sort sort;
    for (auto _ : state) {
        state.PauseTiming();
        auto n = state.range(0);
        std::vector<int> v;
        std::generate_n(std::back_inserter(v), n, random_generator());
        state.ResumeTiming();
        sort(v.begin(), v.end());
    }
}

#endif // COMMON_H
