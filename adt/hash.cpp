//
//  hash.cpp
//  algorithms
//
//  Created by 云心逸 on 2019/1/9.
//  Copyright © 2019 云心逸. All rights reserved.
//

#include <gtest/gtest.h>
#include <unordered_map>
#include "hash.hpp"

using namespace std;

TEST(unordered_multimap, unordered_multimap) {
std::unordered_multimap<std::string,std::string> myumm = {
	{"John","Middle East"},
	{"John","Africa"},
	{"Adam","Europe"},
	{"Bill","Norh-America"}
};

for (auto& x: myumm) {
	std::cout << "Element [" << x.first << ":" << x.second << "]";
	std::cout << " is in bucket #" << myumm.bucket (x.first) << std::endl;
	}
	for (size_t i = 0; i < myumm.bucket_count(); ++i) {
		cout << "bucket " << i << ": ";
		for_each(myumm.begin(i), myumm.end(i), [](const pair<string, string>& p) { cout << p.second << ":"; });
	}
	cout << "\n";
}
