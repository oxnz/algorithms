/*
 * Filename:	bit-count.cpp
 *
 * Author:		Oxnz
 * Email:		yunxinyi@gmail.com
 * Created:		2015-08-21 14:40:24 CST
 * Last-update:	2015-08-21 14:40:24 CST
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
#include <cstdlib>
#include <ctime>

using namespace std;

int f1(unsigned int num);
int f2(unsigned int num);
int f3(unsigned int num);
int f4(unsigned int num);
int f5(unsigned int num);

void correctness_test();
void performance_test();
void prepare_test_data(unsigned int data[], int size);

int test_main() {
	//correctness_test();
	performance_test();

	return 0;
}

int f1(unsigned int num) {
	int count = 0;
	while(num) {
		if(num & 1) ++count;
		num >>= 1;
	}
	return count;
}

int f2(unsigned int num) {
	const unsigned int M1 = 0x55555555;
	const unsigned int M2 = 0x33333333;
	const unsigned int M4 = 0x0f0f0f0f;
	const unsigned int M8 = 0x00ff00ff;
	const unsigned int M16 = 0x0000ffff;

	num = (num & M1) + ((num >> 1) & M1);
	num = (num & M2) + ((num >> 2) & M2);
	num = (num & M4) + ((num >> 4) & M4);
	num = (num & M8) + ((num >> 8) & M8);
	num = (num & M16) + ((num >> 16) & M16);
	return num;
}

int f3(unsigned int num) {
	int count = 0;
	while(num) {
		num &= (num - 1);
		++count;
	}
	return count;
}

int f4(unsigned int num) {
	int count = 0;
		/*
	while(num) {
		int n;
		__asm {
			bsr eax, num
				mov n, eax
		}
		++count;
		num ^= (1 << n);
	}
		*/
	return count;
}

int f5(unsigned int num) {
	static const signed char TABLE[256] = {
		0, 1, 1, 2, 1, 2, 2, 3,	1, 2, 2, 3, 2, 3, 3, 4,
		1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
		1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
		2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
		1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
		2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
		2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
		3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
		1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
		2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
		2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
		3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
		2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
		3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
		3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
		4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8
	};

	unsigned char* p = reinterpret_cast<unsigned char*>(&num);
	int count = 0;
	while(p != reinterpret_cast<unsigned char*>(&num + 1)) {
		count += TABLE[*p++];
	}
	return count;
}

void correctness_test() {
	cout << "in" << endl;
	unsigned int test_data[] = {0, 1, 2, 3, 0x01234567, 0x89abcdef, 0xffffffff};
	unsigned int corect_result[] = {0, 1, 1, 2, 12, 20, 32};

	int (*fn[])(unsigned int) = {f1, f2, f3, f4, f5};
	for(int i = 0; i < sizeof(fn) / sizeof(*fn); ++i) {
		cout << "do" << endl;
		for(int j = 0; j < sizeof(test_data) / sizeof(*test_data); ++j) {
			if(fn[i](test_data[j]) != corect_result[j]) {
				cout << "f" << (i + 1) << " failed!" << endl;
				exit(-1);
			}
			cout << "in" << endl;
		}
	}
	cout << "All methods passed correctness test." << endl;
}

void performance_test() {
	const int TEST_DATA_SIZE = 100000000;
	unsigned int* test_data = new unsigned int[TEST_DATA_SIZE];
	prepare_test_data(test_data, TEST_DATA_SIZE);

	int (*fn[])(unsigned int) = {f1, f2, f3, f4, f5};
	for(int i = 0; i < sizeof(fn) / sizeof(*fn); ++i) {
		clock_t start = clock();
		for(int j = 0; j < TEST_DATA_SIZE; ++j) {
			fn[i](test_data[j]);
		}
		size_t ticks = clock() - start;
		double seconds = ticks * 1.0 / CLOCKS_PER_SEC;

		cout << "f" << (i + 1) << " consumed " << seconds << " seconds." << endl;
	}
	delete[] test_data;
}

void prepare_test_data(unsigned int* data, int len) {
	srand(0);
	for(int i = 0; i < len; ++i) {
		data[i] = static_cast<unsigned int>(rand() * 1.0 / RAND_MAX * 0xffffffff);
	}
}
