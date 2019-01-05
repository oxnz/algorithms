//
//  thread_pool.cpp
//  algorithms
//
//  Created by 云心逸 on 2019/1/4.
//  Copyright © 2019 云心逸. All rights reserved.
//

#include <algorithm>
#include <numeric>
#include <gtest/gtest.h>

#include "thread_pool.hpp"

using namespace std;
namespace mp = multiprocessing;

TEST(thread_pool, square) {
	mp::thread_pool pool(2);
	size_t n = 10;
	vector<int> v(n);
	vector<future<int>> rv;
	iota(v.begin(), v.end(), 0);
	auto squre = [](int i) { return i*i; };
	for (auto i : v) rv.emplace_back(pool.emplace(squre, v[i]));
	for (auto i = 0; i < v.size(); ++i)
		EXPECT_EQ(squre(v[i]), rv[i].get());
}

//TEST(thread_pool, sleep) {
void test_sleep() {
	mp::thread_pool pool(std::thread::hardware_concurrency());
	size_t n = 20;
	size_t ns = 1;
	auto msleep = [](size_t n) { std::this_thread::sleep_for(std::chrono::milliseconds(n*1000)); };
	auto t0 = chrono::steady_clock::now();
	for (int i = 0; i < n; ++i) pool.emplace(msleep, ns);
	pool.join();
	auto t1 = chrono::steady_clock::now();
	auto duration = chrono::duration_cast<chrono::duration<double>>(t1 - t0);
	EXPECT_TRUE(ns*n*1.0/pool.size() - duration.count() < 0.1);
}
