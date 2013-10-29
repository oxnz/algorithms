int gcd(int p, int q) {
    if (!q)
        return p;
    return gcd(q, p%q);
}

#include <iostream>
int main(void) {
    std::cout << "gcd(20, 30)=" << gcd(20, 30) << std::endl;
    return 0;
}
