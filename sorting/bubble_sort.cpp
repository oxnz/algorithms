#include "common.h"

template <typename RandomAccessIterator, typename Compare>
void bubble_sort(RandomAccessIterator first, RandomAccessIterator last, Compare cmp) {
    for (auto it = first; it != last; ++it) {
        for (auto rit = std::reverse_iterator(last); rit != std::reverse_iterator(it); ++rit)
            if (cmp(*rit, *it)) std::iter_swap(it, rit);
    }
}

template<typename RandomAccessIterator>
void bubble_sort(RandomAccessIterator first, RandomAccessIterator last) {
    typedef typename std::iterator_traits<RandomAccessIterator>::value_type T;
    bubble_sort(first, last, std::less<T>());
}

template <typename T>
void bubble_sort_r(T& v, int n) {
	for (int i = 0; i < n-1; ++i) {
		for (int j = n-1; j > i; --j) {
			if (v[j-1] > v[j])
				std::swap(v[j-1], v[j]);
		}
	}
}

TEST(bubble_sort, bubble_sort_a) {
    int v[10] = {95, 45, 15, 79, 84, 51, 24, 12, 1, 100};
    bubble_sort_r(v, 10);
    EXPECT_TRUE(std::is_sorted(std::begin(v), std::end(v)));
}

TEST(bubble_sort, bubble_sort) {
    m::verify_sort_algo(bubble_sort<std::vector<int>::iterator>);
}
