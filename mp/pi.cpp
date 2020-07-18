//
//  pi.cpp
//  algorithms
//
//  Created by 云心逸 on 2019/3/13.
//  Copyright © 2019 云心逸. All rights reserved.
//

#include <random>
#if defined(HAVE_OMP_H)
#include <omp.h>
#endif
#include <thread>
#include <future>
#include <gtest/gtest.h>
#include <benchmark/benchmark.h>
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
    const size_t nbatch = std::thread::hardware_concurrency();
    nloop /= nbatch;
    double pi = 0.0;
#pragma omp parallel for shared(nloop, nbatch) reduction(+:pi)
    for (size_t i = 0; i < nbatch; ++i)
        pi += sequence_pi(nloop);
    return pi/nbatch;
}

double threaded_pi(size_t nloop) {
    const size_t nbatch = std::thread::hardware_concurrency();
    nloop /= nbatch;
    double pi = 0.0;
    std::vector<std::future<double>> v;
    for (size_t i = 0; i < nbatch; ++i)
        v.emplace_back(std::async(&sequence_pi, nloop));
    for (auto it = v.begin(); it != v.end(); ++it)
        pi += it->get();
    return pi/nbatch;
}

TEST(calc_pi, sequential) {
    auto pi = sequence_pi(1<<10);
    EXPECT_GT(pi, 3.0);
    EXPECT_LT(pi, 3.2);
}

TEST(calc_pi, openmp_pi) {
    auto pi = threaded_pi(std::thread::hardware_concurrency()<<10);
    EXPECT_GT(pi, 3.0);
    EXPECT_LT(pi, 3.2);
}

TEST(calc_pi, threaded_pi) {
    auto pi = threaded_pi(std::thread::hardware_concurrency()<<10);
    EXPECT_GT(pi, 3.0);
    EXPECT_LT(pi, 3.2);
}

static void BM_sequential(benchmark::State& state) {
    for (auto _ : state)
        sequence_pi(state.range(0));
}

static void BM_OpenMP(benchmark::State& state) {
    for (auto _ : state)
        openmp_pi(state.range(0));
}

static void BM_thread(benchmark::State& state) {
    for (auto _ : state)
        threaded_pi(state.range(0));
}

BENCHMARK(BM_sequential)->Range(1<<4, 1<<25);

BENCHMARK(BM_OpenMP)->Range(1<<4, 1<<25);

BENCHMARK(BM_thread)->Range(1<<4, 1<<25);
