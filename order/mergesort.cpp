#include "common.h"

template <typename OutputIterator, typename ForwardIterator1, typename ForwardIterator2, typename Compare>
OutputIterator merge(OutputIterator output, ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2, ForwardIterator2 last2, Compare cmp) {
    while (first1 != last1 && first2 != last2) {
        if (cmp(*first1, *first2)) *output++ = *first1++;
        else *output++ = *first2++;
    }
    if (first1 != last1) std::copy(first1, last1, output);
    else if (first2 != last2) std::copy(first2, last2, output);
    return output;
}

template <typename ForwardIterator, typename Compare>
void mergesort(ForwardIterator first, ForwardIterator last, Compare cmp) {
    typedef typename std::iterator_traits<ForwardIterator>::value_type T;
    auto it = std::next(first, std::distance(first, last)/2);
    if (it == first) return;
    mergesort(first, it, cmp);
    mergesort(it, last, cmp);
    std::vector<T> v;
    merge(std::back_inserter(v), first, it, it, last, cmp);
    std::copy(v.begin(), v.end(), first);
}

template <typename ForwardIterator>
void mergesort(ForwardIterator first, ForwardIterator last) {
    return mergesort(first, last, std::less<>());
}

TEST(mergesort, mergesort) {
    m::verify_sort_algo(mergesort<std::vector<int>::iterator>);
}

template <typename T, typename Container = std::vector<T>>
struct _mergesort {
    using iterator = typename Container::iterator;
    void operator()(iterator first, iterator last) {
        mergesort(first, last);
    }
};

BENCHMARK_TEMPLATE(BM_sorting, _mergesort<int>)->Range(8, 1<<20);
