//
//  experiment.cpp
//  Interview
//
//  Created by 云心逸 on 2018/12/31.
//  Copyright © 2018 Errpro,Inc. All rights reserved.
//

#include "experiment.hpp"

#include <vector>
#include <tuple>
#include <gtest/gtest.h>

using namespace std;

namespace safety {
class User {
public:
	User(string username, string password) : m_username(username), m_password(password) {}
	void foo(){}
	void bar(){}
	bool verify(string username, string password) const {
		return username == m_username and password == m_password;
	}
private:
	string m_username;
	string m_password;
};

struct T {
	string username;
	string password;
};

TEST(safety, safety) {
	string username = "hello";
	string password = "world";
	User user(username, password);
	T* p = reinterpret_cast<T*>(&user);
	EXPECT_TRUE(user.verify(p->username, p->password)) << "hack failed";
}
}

TEST(experiment, experiment) {
	unique_ptr<int> up;
	shared_ptr<int> sp;
	EXPECT_EQ(8, sizeof(up));
	EXPECT_EQ(16, sizeof(sp));
}

TEST(array, array) {
	int a[]{1,2,3,4,5,6};
	auto p = a+1;
	EXPECT_EQ(24, sizeof(a));
	EXPECT_EQ(a[1], p[0]);
}

TEST(endian, endian) {
	uint32_t endian = 0x12345678;
	uint32_t i = 1;
	EXPECT_EQ(0x5678, *reinterpret_cast<uint16_t*>(&endian));
	EXPECT_TRUE(*reinterpret_cast<uint8_t*>(&i)&i);
}

