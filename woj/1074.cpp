/*
 * Filename:	1074.cpp
 *
 * Author:		Oxnz
 * Email:		yunxinyi@gmail.com
 * Created:		[2015-01-12 20:40:48 CST]
 * Last-update:	2015-01-12 20:40:48 CST
 * Description: anchor
 *
 * Version:		0.0.1
 * Revision:	[NONE]
 * Revision history:	[NONE]
 * Date Author Remarks:	[NONE]
 *
 * License: 
 * Copyright (c) 2013 Oxnz
 *
 * Distributed under terms of the [LICENSE] license.
 * [license]
 *
 */

#include <iostream>
#include <set>

using namespace std;

int main() {
	int t;
	int n;
	int m = -1;

	cin >> t;
	while (t--) {
		long e;
		cin >> n;
		set<long> s;
		while (n--) {
			cin >> e;
			s.insert(e);
		}
		for (set<long>::iterator it = s.begin();
				it != s.end(); ++it) {
		}
	}

	return 0;
}
