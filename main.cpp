#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <string>
#include <random>
#include <deque>
#include <list>
#include <forward_list>
#include <utility>

#include <gtest/gtest.h>

using namespace std;

template<typename ForwardIterator>
void echo(ForwardIterator first, ForwardIterator last) {
	std::copy(first, last, std::ostream_iterator<typename iterator_traits<ForwardIterator>::value_type>(std::cout, ", "));
	std::cout << "\n";
}

template<typename Container>
void echo(Container container) {
	echo(container.begin(), container.end());
}
