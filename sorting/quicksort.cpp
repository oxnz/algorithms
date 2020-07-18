#include "common.h"

template <typename Iter, typename Comparator>
/**
 * @brief partition_s dutch national flag
 * | lt | eq | gt |
 * @param first
 * @param last
 * @param cmp
 * @return
 */
std::pair<Iter, Iter> partition_s(Iter first, Iter last, Comparator cmp) {
    for (auto it = first; it != last;) {
        auto v = cmp(*it);
        if (v < 0) std::iter_swap(first++, it++);
        else if (v == 0) ++it;
        else std::iter_swap(it, --last);
    }
    return {first, last};
}

template <typename RandomAccessIterator, typename Comparator>
std::pair<RandomAccessIterator, RandomAccessIterator> partition(RandomAccessIterator first, RandomAccessIterator last, Comparator cmp) {
    auto it = std::partition(first, last, [&cmp](const auto& v) { return cmp(v) < 0; });
    return {it, std::partition(it, last,  [&cmp](const auto& v) { return cmp(v) == 0; })};
}

template <typename RandomAccessIterator, typename Compare>
void quicksort(RandomAccessIterator first, RandomAccessIterator last, Compare cmp) {
    if (first == last) return;
    auto pivot = *std::next(first, std::distance(first, last)/2);
    auto it0 = std::partition(first, last,
                          [pivot](const auto& em){ return em < pivot; });
    auto it1 = std::partition(it0, last,
                              [pivot](const auto& em){ return !(pivot < em); });
    quicksort(first, it0, cmp);
    quicksort(it1, last, cmp);
}

template <typename RandomAccessIterator>
void quicksort(RandomAccessIterator first, RandomAccessIterator last) {
    quicksort(first, last, std::less<>());
}

template <typename T>
void qsort(T array[], int left, int right) {
    if (left < right) {
        int l = left;
        int r = right;
        T m = array[l];
        while (l < r) {
            while (l < r && array[r] >= m)
                --r;
            if (l < r)
                array[l++] = array[r];
            while (l < r && array[l] < m)
                ++l;
            if (l < r)
                array[r--] = array[l];
        }
        array[l] = m;
        qsort(array, left, l-1);
        qsort(array, l+1, right);
    }
}

TEST(partition, dutch_national_flag) {
    std::vector<int> i = {2, 0, 0, 1, 2, 1}, o = {0, 0, 1, 1, 2, 2};
    partition_s(i.begin(), i.end(), [](auto i) { return i - 1; });
    EXPECT_EQ(i, o);
}

TEST(quicksort, qsort) {
    int a[20] = {0, 4, 332232, 434, 5454, 423, 7, 32132131, 4343, 434};
    qsort(a, 0, 19);
    EXPECT_TRUE(std::is_sorted(std::begin(a), std::end(a)));
}

TEST(quicksort, quicksort) {
    m::verify_sort_algo(quicksort<std::vector<int>::iterator>);
}

template <typename T, typename Container = std::vector<T>>
struct _quicksort {
    using iterator = typename Container::iterator;
    void operator()(iterator first, iterator last) {
        quicksort(first, last);
    }
};

BENCHMARK_TEMPLATE(BM_sorting, _quicksort<int>)->Range(8, 8<<20);

