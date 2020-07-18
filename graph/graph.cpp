//
//  graph.cpp
//  graph
//
//  Created by 云心逸 on 8/4/16.
//  Copyright © 2016 Errpro,Inc. All rights reserved.
//

#include <gtest/gtest.h>
#include <fstream>
#include "graph.hpp"

TEST(graph, adj) {
    m::graph<int> g;
    const std::string fpath = "tinyG.txt";
    {
    std::ifstream ifs(fpath);
    EXPECT_TRUE(ifs.is_open()) << "failed to open: " + fpath;
    EXPECT_TRUE(ifs >> g) << "read failed: " + fpath;
    }
    std::ostringstream oss;
    oss << g;
    EXPECT_FALSE(oss.str().empty());
//    std::cout << oss.str() << "\n";
}
