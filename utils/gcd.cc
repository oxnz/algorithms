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

#include <iostream>
int main(void) {
    std::cout << "gcd(20, 30)=" << gcd(20, 30) << std::endl;
    std::cout << "gcd(20, 30)=" << gcd2(20, 30) << std::endl;
    return 0;
}
