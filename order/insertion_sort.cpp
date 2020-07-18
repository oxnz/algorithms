#include "common.h"

template <typename RandomAccessIterator, typename Compare>
void insertion_sort(RandomAccessIterator first, RandomAccessIterator last, Compare cmp) {
    for (auto it = first; it != last; ++it) {
        auto p = it; // 0 8 2 -> 0 2 8
        auto tmp = *p;
        for (; p != first && cmp(tmp, *(p-1)); --p)
            *p = *(p-1);
        *p = tmp;
    }
}

template <typename RandomAccessIterator>
void insertion_sort(RandomAccessIterator first, RandomAccessIterator last) {
    insertion_sort(first, last, std::less<>());
}

TEST(insertion_sort, insertion_sort) {
    auto f = insertion_sort<std::vector<int>::iterator>;
    m::verify_sort_algo(f);
}

template <typename T, typename Container = std::vector<T>>
struct _insertion_sort {
    using iterator = typename Container::iterator;
    void operator()(iterator first, iterator last) {
        insertion_sort(first, last);
    }
};

BENCHMARK_TEMPLATE(BM_sorting, _insertion_sort<int>)->Range(8, 8<<10);
