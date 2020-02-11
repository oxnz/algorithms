/*
 * Filename:	algorithm.h
 *
 * Author:		Oxnz
 * Email:		yunxinyi@gmail.com
 * Created:		[2016-08-25 02:10:29 CST]
 * Last-update:	2016-08-25 02:10:29 CST
 * Description: anchor
 *
 * Version:		0.0.1
 * Revision:	[NONE]
 * Revision history:	[NONE]
 * Date Author Remarks:	[NONE]
 *
 * License: 
 * Copyright (c) 2013 Oxnz
 *
 * Distributed under terms of the [LICENSE] license.
 * [license]
 *
 */

#ifndef _ALGORITHM_H_
#define _ALGORITHM_H_

#include <iterator>
#include <utility>

namespace m {

/*
 * Non-modifying sequence operations
 */
template <class InputIterator, class UnaryPredicate>
bool all_of(InputIterator first, InputIterator last, UnaryPredicate pred) {
	for (; first != last; ++first)
		if (!pred(*first)) return false;
	return true;
}

template <class InputIterator, class UnaryPredicate>
bool any_of(InputIterator first, InputIterator last, UnaryPredicate pred) {
	for (; first != last; ++first)
		if (pred(*first)) return true;
	return false;
}

template <class InputIterator, class UnaryPredicate>
bool none_of(InputIterator first, InputIterator last, UnaryPredicate pred) {
	return !any_of(first, last, pred);
}

template <class InputIterator, class Function>
Function for_each(InputIterator first, InputIterator last, Function fn) {
	for (; first != last; ++first)
		fn(*first);
	return fn;
}

template <class InputIterator, class T>
InputIterator find(InputIterator first, InputIterator last, const T& val) {
	for (; first != last; ++first)
		if (*first == val) return first;
	return last;
}

template <class InputIterator, class UnaryPredicate>
InputIterator find_if(InputIterator first, InputIterator last, UnaryPredicate pred) {
	for (; first != last; ++first)
		if (pred(*first)) return first;
	return last;
}

template <class InputIterator, class UnaryPredicate>
InputIterator find_if_not(InputIterator first, InputIterator last, UnaryPredicate pred) {
	for (; first != last; ++first)
		if (!pred(*first)) return first;
	return last;
}

template <class InputIterator, class T>
typename std::iterator_traits<InputIterator>::difference_type
count(InputIterator first, InputIterator last, const T& val) {
	typename std::iterator_traits<InputIterator>::difference_type cnt = 0;
	for (; first != last; ++first)
		if (*first == val) ++cnt;
	return cnt;
}

template <class InputIterator, class UnaryPredicate>
typename std::iterator_traits<InputIterator>::difference_type
count_if(InputIterator first, InputIterator last, UnaryPredicate pred) {
	typename std::iterator_traits<InputIterator>::difference_type cnt = 0;
	for (; first != last; ++first)
		if (pred(*first)) ++cnt;
	return cnt;
}

/*
 * Modifying sequence operations
 */

template <class InputIterator, class OutputIterator>
OutputIterator copy(InputIterator first, InputIterator last, OutputIterator dst) {
	for (; first != last; ++first)
		*dst++ = *first;
	return dst;
}

template <class InputIterator, class Size, class OutputIterator>
OutputIterator copy_n(InputIterator src, Size n, OutputIterator dst) {
	while (n--)
		*dst++ = *src++;
	return dst;
}

template <class ForwardIterator, class T>
ForwardIterator remove(ForwardIterator first, ForwardIterator last, const T& val) {
	ForwardIterator it = first;
	for (; first != last; ++first)
		if (!(*first == val))
			*it++ = std::move(*first);
	return it;
}

template <class ForwardIterator, class UnaryPredicate>
ForwardIterator remove_if(ForwardIterator first, ForwardIterator last,
		UnaryPredicate pred) {
	ForwardIterator it = first;
	for (; first != last; ++first)
		if (!pred(*first))
			*it++ = std::move(*first);
	return it;
}

/*
 * Min/Max
 */
template <class T>
const T& min(const T& a, const T& b) {
	return !(b < a) ? a : b;
}

template <class T>
const T& max(const T&a, const T& b) {
	return a < b ? b : a;
}

template <class T>
std::pair<const T&, const T&> minmax(const T&a, const T& b) {
	return (b < a) ? std::make_pair(b, a) : std::make_pair(a, b);
}

template <class ForwardIterator>
ForwardIterator min_element(ForwardIterator first, ForwardIterator last) {
	if (first == last) return last;
	ForwardIterator it = first++;
	for (; first != last; ++first)
		if (*first < *it) it = first;
	return it;
}

template <class ForwardIterator>
ForwardIterator max_element(ForwardIterator first, ForwardIterator last) {
	if (first == last) return last;
	ForwardIterator it = first++;
	for (; first != last; ++first)
		if (*it < *first) it = first;
	return it;
}

template <class ForwardIterator>
std::pair<ForwardIterator, ForwardIterator> minmax_element(
		ForwardIterator first, ForwardIterator last) {
	if (first == last) return std::make_pair(last, last);
	ForwardIterator smallest = first, largest = first;
	for (++first; first != last; ++first)
		if (*first < *smallest) smallest = first;
		else if (*largest < *first) largest = first;
	return std::make_pair(smallest, largest);
}

/*
 * Other
 */

}

#endif//_ALGORITHM_H_
