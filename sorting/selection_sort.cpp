#include "common.h"

template <typename RandomAccessIterator, typename Compare>
void selection_sort(RandomAccessIterator first, RandomAccessIterator last, Compare cmp) {
    for (auto it = first; it != last; ++it)
        std::iter_swap(it, std::min_element(it, last, cmp));
}

template <typename RandomAccessIterator>
void selection_sort(RandomAccessIterator first, RandomAccessIterator last) {
    selection_sort(first, last, std::less<>());
}

TEST(selection_sort, selection_sort) {
    m::verify_sort_algo(selection_sort<std::vector<int>::iterator>);
}

template <typename T, typename Container = std::vector<T>>
struct _selection_sort {
    using iterator = typename Container::iterator;
    void operator()(iterator first, iterator last) {
        selection_sort(first, last);
    }
};

BENCHMARK_TEMPLATE(BM_sorting, _selection_sort<int>)->Range(8, 8<<10);

template <typename Sort>
struct fx {
    fx(Sort sort) : sort(sort) {}
    Sort sort;
    void operator()(benchmark::State& state) {
        for (auto _ : state) {
            state.PauseTiming();
            auto n = state.range(0);
            std::vector<int> v;
            std::generate_n(std::back_inserter(v), n, random_generator());
            state.ResumeTiming();
            sort(v.begin(), v.end());
        }
    }
};

void foo() {
//    m::verify_sort_algo(std::sort<std::vector<int>::iterator>);
    m::verify_sort_algo(selection_sort<std::vector<int>::iterator>);
    benchmark::RegisterBenchmark("disabled-at-runtime", fx(selection_sort<std::vector<int>::iterator>));
}
