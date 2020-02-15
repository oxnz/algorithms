//
//  assert.cpp
//  lang
//
//  Created by Max Zhang on 2020/2/15.
//

#include <gtest/gtest.h>
#include "assert.hpp"

TEST(abort, abort) {
    verify(1 == 1, "failed");
}
