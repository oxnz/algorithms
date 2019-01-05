#include <stdio.h>

#define EPSILON 0.0000001

unsigned int abs(int n) {
	if (n < 0)
		return -n;
	else
		return n;
}
 
int main() {
	double s[200];
	double a, b, c;
	long double aa, bb;
	char sa[100], sb[100], sc[100];
	s['t'] = 45.72 * 18 * 1 * 1.5;
	s['n'] = 0.4572 * 18 * 1 * 1.5;
	s['c'] = 0.4572 * 45.72 * 1 * 1.5;
	s['b'] = 0.4572 * 45.72 * 18 * 1.5;
	s['e'] = 0.4572 * 45.72 * 18 * 1;
	while (scanf("%lf", &a) != EOF)
	{
		scanf("%s\n%lf %s\n%lf %s\n\n", sa, &b, sb, &c, sc);
		aa = a * s[sa[2]];
		bb = b * s[sb[2]];
		if (abs(aa - bb) < EPSILON)
			printf("Spin\n\n");
		else if (abs(aa / 6.0 - bb) < EPSILON)
			printf("Excellent\n\n");
		else
			printf("Neither\n\n");
	};
	return 0;
}
