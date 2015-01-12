#include <stdio.h>
#include <math.h>

double N_sqrt( int m0, int n0, int m1, int n1 ) {
	return sqrt( pow((m0 - m1), 2) + pow((n0 - n1), 2) );
}

double line( int x0, int y0, int x1, int y1, int x2, int y2) {
double a, b, c, cos_a, temp;
a = N_sqrt( x0, y0, x1, y1);
b = N_sqrt( x0, y0, x2, y2);
c = N_sqrt( x1, y1, x2, y2);
cos_a = (b*b + c*c - a*a) / (2.0*b*c);
return 2*b*c*(1-cos_a*cos_a)/a;
}

int main() {
	int num;
	while (( scanf("%d", &num)!=EOF ) && ( num != 0 ) ) {
		double l[num];
		for(int i=0; i<num; i++) {
			int p[3][2];
			for (int j=0; j<3; j++)
				scanf("%d %d", &p[j][0], &p[j][1]);
			l[i] = line(p[0][0], p[0][1], p[1][0], p[1][1], p[2][0], p[2][1]);
			printf("%4.3f\n", l[i]);
		}
		return 0;
	}
}
