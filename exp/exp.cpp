#include <iostream>
<<<<<<< HEAD
#include <typeinfo>
=======
#include <array>
#include <vector>
#include <queue>
#include <list>
#include <forward_list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <random>
#include <tuple>
#include <iterator>
#include <algorithm>
#include <utility>
>>>>>>> ab703f00fc1e1002e956538795856139bd1ae5e4
#include <gtest/gtest.h>

using namespace std;

TEST(hexo, hexo) {
    vector<int> v = {3, -7, 3, -7, 3};
//    v = {5, 5, 4, 5, 4};
//    v = {7, 4, -2, 4, -2, 9};
//    v = {7, -5, -5, -5, 7, -1, 7};
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
    os << typeid (v).name() << "<" << std::addressof(v) << ">[";
    auto it = v.begin();
    if (it != v.end()) os << *it++;
    for (; it != v.end(); ++it) os << ", " << *it;
    return os << "]";
}

TEST(ostream, vector) {
    std::vector<int> v;
    for (int i = 0; i < 10; ++i) v.push_back(i);
    std::cout << v << "\n";
}
