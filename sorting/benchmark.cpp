//
//  benchmark.cpp
//  algorithms
//
//  Created by Max Zhang on 2020/2/18.
//

#include "common.h"

template <typename T, typename Container = std::vector<T>>
struct _std_sort {
    using iterator = typename Container::iterator;
    void operator()(iterator first, iterator last) {
        std::sort(first, last);
    }
};

BENCHMARK_TEMPLATE(BM_sorting, _std_sort<int>)->Range(8, 8<<20);

template <typename T, typename Container = std::vector<T>>
struct _std_stable_sort {
    using iterator = typename Container::iterator;
    void operator()(iterator first, iterator last) {
        std::stable_sort(first, last);
    }
};

BENCHMARK_TEMPLATE(BM_sorting, _std_stable_sort<int>)->Range(8, 8<<20);
