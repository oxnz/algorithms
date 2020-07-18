//
//  ipv4_addr.cpp
//  lang
//
//  Created by Max Zhang on 2020/2/15.
//
#include <gtest/gtest.h>
#include "ipv4_addr.hpp"

TEST(ipv4_addr, empty) {
    m::ipv4_addr addr;
    EXPECT_EQ(addr.str(), "0.0.0.0");
}

TEST(ipv4_addr, string) {
    const std::string ip = "172.10.14.234";
    m::ipv4_addr addr(ip);
    EXPECT_EQ(addr.str(), ip);
}

TEST(ipv4_addr, loopback) {
    m::ipv4_addr addr(m::ipv4_addr::LOOPBACK);
    EXPECT_EQ(addr.str(), "127.0.0.1");
}
