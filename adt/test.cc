/*
 * Filename:	test.c
 *
 * Author:		Oxnz
 * Email:		yunxinyi@gmail.com
 * Created:		2016-08-27 10:55:07 CST
 * Last-update:	2016-08-27 10:55:07 CST
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

#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct hotel_review {
	int _id;
	int _score;
	hotel_review() {}
	hotel_review(int id, int score) : _id(id), _score(score) {}
	bool operator<(const hotel_review& rhs) const {
		return _score < rhs._score || _id < rhs._id;
	}
	friend ostream& operator<<(ostream& os, const hotel_review& rv);
};

ostream& operator<<(ostream& os, const hotel_review& rv) {
	os << "[" << rv._id << ":" << rv._score << "]";
	return os;
}

void foo() {
	vector<hotel_review> v;
	for (int i = 0; i < 10; ++i) {
		hotel_review rv(i, i);
		v.push_back(rv);
	}
	v[5]._score = 8;
	v[6]._score = 9;
	sort(v.begin(), v.end());
	copy(v.begin(), v.end(), ostream_iterator<hotel_review>(cout, " "));
	cout << endl;
	unordered_map<int, hotel_review> m;
	for (auto & rv : v)
		m[rv._id] = rv;
	for (auto & it : m)
		cout << it.second << ' ';
	cout << endl;
	if (m.find(-1) != m.end())
		cout << "ERROR" << endl;
	if (m.find(0) == m.end())
		cout << "ERROR" << endl;
}

int main() {
	cout << sizeof(string) << endl;

	return 0;
}
