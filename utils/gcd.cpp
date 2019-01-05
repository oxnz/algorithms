int gcd(int p, int q) {
    if (!q)
        return p;
    return gcd(q, p%q);
}

// tail-call elimination
int gcd2(int p, int q) {
	int t;
	while (q) {
		t = p;
		p = q;
		q = t % q;
	}
	return p;
}

#include <gtest/gtest.h>
TEST(gcd, gcd) {
	EXPECT_EQ(gcd(20, 30), 10) << "gcd(20, 30) != 10";
	EXPECT_EQ(gcd2(20, 30), 10) << "gcd2(20, 30) != 10";
}
