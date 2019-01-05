//
//  hash.cpp
//  Interview
//
//  Created by 云心逸 on 2019/1/3.
//  Copyright © 2019 Errpro,Inc. All rights reserved.
//

#include "hash.hpp"

#include <gtest/gtest.h>
#include <unordered_map>

using namespace std;

class T {
public:
	T(const string& name) : m_name(name) {}
	friend struct hash<T>;
	bool operator==(const T& rhs) const {
		return this->m_name == rhs.m_name;
	}
private:
	string m_name;
};

template <>
struct hash<T> {
	size_t operator()(const T& v) const {
		return std::hash<string>()(v.m_name);
	}
};

TEST(hash, hash) {
	unordered_map<T, int> m;
	for (int i = 0; i < 4; ++i) {
		m[T(to_string(i))] = i;
	}
	EXPECT_EQ(m[T("1")], 1);
	EXPECT_EQ(m[T("2")], 2);
}
