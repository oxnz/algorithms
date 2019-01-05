//
//  parallel.cpp
//  Interview
//
//  Created by 云心逸 on 2019/1/3.
//  Copyright © 2019 Errpro,Inc. All rights reserved.
//

#include "parallel.hpp"
#include <vector>
#include <gtest/gtest.h>

using namespace std;

size_t proc(size_t nworker) {
	std::atomic<size_t> cnt{};
	vector<thread> workers;
	workers.reserve(nworker);
	for (size_t i = 0; i < nworker; ++i) {
		workers.emplace_back([&cnt]() {
			for (size_t i = 0; i < 100; ++i)
				cnt.fetch_add(1, memory_order_relaxed);
		});
	}
	// The thread joining provides the necessary synchronization point that ensures that the final load() sees the correct value.
	for (auto& worker : workers) {
		worker.join();
	}
	return cnt.load(memory_order_relaxed);
}

TEST(parallel, parallel) {
	EXPECT_EQ(1000, proc(10));
}
