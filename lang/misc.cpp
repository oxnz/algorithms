//
//  misc.cpp
//  algorithms
//
//  Created by 云心逸 on 2019/1/19.
//  Copyright © 2019 云心逸. All rights reserved.
//

#include <gtest/gtest.h>
#include "misc.hpp"

TEST(print_tuple, print_tuple) {
    std::tuple<int, std::string, const char*> t(1234, "hello", "world");
    std::cout << t << "\n";
}
