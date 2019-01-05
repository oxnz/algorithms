/*
 * Filename:	basic.cpp
 *
 * Author:		Oxnz
 * Email:		yunxinyi@gmail.com
 * Created:		2018-12-23 13:33:36 CST
 * Last-update:	2018-12-23 13:33:36 CST
 * Description: anchor
 *
 * Version:		0.0.1
 * Revision:	[NONE]
 * Revision history:	[NONE]
 * Date Author Remarks:	[NONE]
 *
 * License: 
 * Copyright (c) 2018 Oxnz
 *
 * Distributed under terms of the [LICENSE] license.
 * [license]
 *
 */

#include <iostream>
#include <vector>
#include <gtest/gtest.h>

using namespace std;

void test_sizeof() {
	vector<pair<string, size_t>> v;
	v.push_back({"char", sizeof(char)});
	v.push_back({"short", sizeof(short)});
	v.push_back({"int", sizeof(int)});
	v.push_back({"long", sizeof(long)});
	v.push_back({"float", sizeof(float)});
	v.push_back({"double", sizeof(double)});
	v.push_back({"long long", sizeof(long long)});
	v.push_back({"long double", sizeof(long double)});
	for (const auto& p : v)
		cout << "sizeof(" << p.first << ")\t= " << p.second << endl;
}
