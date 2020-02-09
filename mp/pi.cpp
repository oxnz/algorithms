//
//  pi.cpp
//  algorithms
//
//  Created by 云心逸 on 2019/3/13.
//  Copyright © 2019 云心逸. All rights reserved.
//

#include <random>
//#include <omp.h>
#include <gtest/gtest.h>
#include "pi.hpp"

using namespace std;

double sequence_pi(size_t nloop) {
	mt19937 engine;
	uniform_real_distribution<double> distribution(-1.0, 1.0);
	size_t cnt = 0;
	for (size_t i = 0; i < nloop; ++i) {
		double x = distribution(engine);
		double y = distribution(engine);
		if (x*x + y*y < 1) ++cnt;
	}
	return 4.0*cnt/nloop;
}

double openmp_pi(size_t nloop) {
    const size_t nbatch = 1<<3;
    nloop /= nbatch;
    double pi = 0.0;
#pragma omp parallel for shared(nloop, nbatch) reduction(+:pi)
    for (size_t i = 0; i < nbatch; ++i)
        pi += sequence_pi(nloop);
    return pi/nbatch;
}

TEST(sequence_pi, sequence_pi) {
	auto pi = sequence_pi(1<<25);
	cout << (1<<20) << ":  " << pi << "\n"; // 4291 ms
}

TEST(openmp_pi, openmp_pi) {
	auto pi = openmp_pi(1<<25);
	cout << (1<<20) << ":  " << pi << "\n"; // 4291 ms
}
