/*
 * Filename:	test.cc
 *
 * Author:		Oxnz
 * Email:		yunxinyi@gmail.com
 * Created:		2016-08-25 02:10:55 CST
 * Last-update:	2016-08-25 02:10:55 CST
 * Description: anchor
 *
 * Version:		0.0.1
 * Revision:	[NONE]
 * Revision history:	[NONE]
 * Date Author Remarks:	[NONE]
 *
 * License:
 * Copyright (c) 2016 Oxnz
 *
 * Distributed under terms of the [LICENSE] license.
 * [license]
 *
 */

#include <iostream>
#include <iterator>
#include <vector>
#include "algorithm.h"

using namespace std;

TEST(copy, copy) {
	std::vector<int> v;
}

bool test_copy() {
	vector<int> v;
	nz::copy(istream_iterator<int>(cin), istream_iterator<int>(),
			back_inserter(v));
	nz::copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	return true;
}

int main(int argc, char *argv[]) {
	if (argc > 1) {
		cout << "too many arguments" << endl;
		return 1;
	}
	cout << argv[0] << endl;
	test_copy();
	return 0;
}
