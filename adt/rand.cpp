/*
 * Filename:	random_string_generator.cpp
 *
 * Author:		Oxnz
 * Email:		yunxinyi@gmail.com
 * Created:		2018-12-25 17:54:35 CST
 * Last-update:	2018-12-25 17:54:35 CST
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

#include "rand.h"
#include <vector>
#include <gtest/gtest.h>

TEST(randint_generator, fixed_value) {
    m::randint_generator<> gen(1234, 1234);
    EXPECT_EQ(gen(), 1234);
}

TEST(randint_generator, range) {
    m::randint_generator<> gen(0, 1);
    for (int i = 0; i < 1024; ++i) {
        auto v = gen();
        EXPECT_TRUE(v==0 || v == 1);
    }
}

TEST(randstr_generator, empty) {
    m::randstr_generator gen("-", 0);
    EXPECT_TRUE(gen().empty());
}

TEST(randstr_generator, range) {
    m::randstr_generator gen("abcdefghijklmnopqrstuvwxyz", 26);
    for (int i = 0; i < 1024; ++i) {
        EXPECT_EQ(gen().size(), 26);
    }
}
