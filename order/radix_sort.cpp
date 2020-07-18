/*
* Filename:    radix_sort.c
*
* Author:        Oxnz
* Email:        yunxinyi@gmail.com
* Created:        2016-07-16 15:52:43 CST
* Last-update:    2016-07-16 15:52:43 CST
* Description: anchor
*
* Version:        0.0.1
* Revision:    [NONE]
* Revision history:    [NONE]
* Date Author Remarks:    [NONE]
*
* License:
* Copyright (c) 2016 Oxnz
*
* Distributed under terms of the [LICENSE] license.
* [license]
*
* References: https://brilliant.org/wiki/radix-sort/
*
*/

#include "common.h"


// MAXLEN: array max length
// COL: decimal bits count
#define ROW 10
#define MAXLEN 100
#define COL 4
int buf[ROW][MAXLEN];

void radix_sort(int a[], int n, int r) {
    int ix;
    for (int c = 0; c < r; ++c) {
        // clear buffer
        for (int i = 0; i < ROW; ++i)
            for (int j = 0; j < n; ++j)
                buf[i][j] = 0;

        for (int i = 0; i < n; ++i) {
            ix = (a[i] / (int)pow(10, c)) % 10;
            int j = 0;
            while (buf[ix][j])
                ++j;
            buf[ix][j] = a[i];
        }
        ix = 0;
        for (int i = 0; i < ROW; ++i)
            for (int j = 0; j < n; ++j)
                if (buf[i][j])
                    a[ix++] = buf[i][j];
    }
}

TEST(radixsort, radixsort_r) {
    int a[20];
    for (int i = 0; i < 20; ++i)
        if (a[i] == 0)
            a[i] = 1;
    m::print_array(a, 20);
    radix_sort(a, 20, 2);
    m::print_array(a, 20);
}

void count_sort(char **A, int n, int offset) {
	int R = 256;
	int count[R];
	char* T[n];
	int i;
	memset(count, 0, sizeof(int)*R);
	for (i = 0; i < n; ++i)
		++count[A[i][offset]];
	for (i = 0; i < R-1; ++i)
		count[i+1] += count[i];
	for (i = n-1; i >=0; --i)
		T[--count[A[i][offset]]] = A[i];
	for (i = 0; i < n; ++i)
		A[i] = T[i];
}

void radix_sort(char **A, int n, int width) {
	for (int i = width-1; i >= 0; --i) {
		count_sort(A, n, i);
	}
}

template <typename Iter>
size_t _radix(Iter it, size_t offset) {
    return (*it)[offset];
}

template <typename Iter, size_t radix=256>
/**
 * @brief counting_sort
 * time complexity: O(n+radix)
 * space complexity: O(n+radix)
 * @param first
 * @param last
 * @param offset
 */
void counting_sort(Iter first, Iter last, size_t offset) {
    static_assert (radix > 1, "invalid radix");
    size_t n = std::distance(first, last);
    if (n < 2) return;
    size_t count[radix] = {0};
    for (auto it = first; it != last; ++it)
        ++count[_radix(it, offset)];
    std::partial_sum(std::begin(count), std::end(count), std::begin(count));
    std::vector<Iter> v(n);
    for (auto it = first; it != last; ++it)
        v[--count[_radix(it, offset)]] = it;
    for (size_t i = 0; i < n; ++i) {
        std::cout << "swap(" << *v[i] << ", " << *first << ")\n";
        std::iter_swap(v[i], first++);
    }
}

template <typename Iter, typename Compare, size_t R=1<<8>
/**
 * @brief radix_sort
 * Radix sort is an integer sorting algorithm that sorts data with integer keys
 * by grouping the keys by individual digits that share the same significant position and value (place value).
 * Radix sort uses counting sort as a subroutine to sort an array of numbers.
 *
 * Radix sort incorporates the counting sort algorithm so that it can sort larger,
 * multi-digit numbers without having to potentially decrease the efficiency
 * by increasing the range of keys the algorithm must sort over (since this might cause a lot of wasted time).
 * @param first
 * @param last
 * @param cmp
 */
void radix_sort(Iter first, Iter last, Compare cmp) {

}

template <typename Iter>
void radix_sort(Iter first, Iter last) {
    radix_sort(first, last, std::less<>());
}

TEST(radix_sort, counting_sort) {
    std::vector<std::string> v = {"ABC", "ACB", "BAC", "BCA", "CAB", "CBA"};
    counting_sort(v.begin(), v.end(), 2);
    m::echo(v.begin(), v.end()); std::cout << "\n";
}

TEST(radixsort, radixsort) {
    std::vector<std::string> v = {"DABC", "DACB", "DBAC", "DBCA", "DCAB", "DCBA",
		"CABD", "CADB", "CBAD", "CBDA", "CDAB", "CDBA",
		"BACD", "BADC", "BCAD", "BCDA", "BDAC", "BDCA",
		"ABCD", "ABDC", "ACBD", "ACDB", "ADBC", "ADCB",
		"ABCD", "BCDA", "CDAB", "DABC"
    };
    radix_sort(v.begin(), v.end());
    m::echo(v.begin(), v.end());
    EXPECT_TRUE(std::is_sorted(std::begin(v), std::end(v)));
}
