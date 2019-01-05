/*
 * Filename:	SingleNumberIII.cpp
 *
 * Author:		Oxnz
 * Email:		yunxinyi@gmail.com
 * Created:		2015-08-18 19:47:35 CST
 * Last-update:	2015-08-18 19:47:35 CST
 * Description: anchor
 *
 * Version:		0.0.1
 * Revision:	[NONE]
 * Revision history:	[NONE]
 * Date Author Remarks:	[NONE]
 *
 * License: 
 * Copyright (c) 2015 Oxnz
 *
 * Distributed under terms of the [LICENSE] license.
 * [license]
 *
 */

#include <iostream>
#include <set>
#include <vector>

using namespace std;


class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		int sum;
		for (int i : nums)
			sum ^= i;
		int bit = 0;
		while (sum > 0) {
			if (((sum >> bit) & 1) != 0)
				break;
			else
				++bit;
		}
		int sep = 1 << bit;
		cout << "sep = " << sep << ", bit = " << bit << endl;
		set<int> a, b;
		for (int i : nums) {
			if ((i & sep) == 0) {
				a.insert(i);
				cout << "a:" << i << endl;
			} else {
				b.insert(i);
				cout << "b:" << i << endl;
			}
		}

		vector<int> ret;
		int n = 0;
		for (int i : a)
			n ^= i;
		ret.push_back(n);
		n = 0;
		for (int i : b)
			n ^= i;
		ret.push_back(n);
		return ret;
	}
};

int main(int argc, char* argv[]) {
	Solution sol;
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(1);
	v.push_back(3);
	v.push_back(2);
	v.push_back(5);
	vector<int> r = sol.singleNumber(v);
	for (int i : r)
		cout << i << endl;
	return 0;
}
