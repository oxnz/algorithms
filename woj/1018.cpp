#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <cmath>
#include <iostream>

using namespace std;

int h1[65537];
int h2[65537];
int a[5001];
int b[5001];
bool sign[5001];

int main() {
	int n,k,tp,cost,q;
	int min;
	while ((cin >> n) && n) {
		min=65538;
		memset(sign,0,sizeof(sign));
		cost=0;
		for (int i=1;i<=n;i++) {
			cin >> a[i];
			if (a[i]<min)
				min=a[i];
			cost+=a[i];
			h1[a[i]]=i;
		}
		for (int i=1;i<=n;i++) {
			cin >> b[i];
			h2[b[i]]=i;
		}
		for (int i=1;i<=n;i++)
			if (!sign[i]) {
				tp=65538;
				q=i;
				k=0;
				do {
					sign[q]=1;
					if (b[q]<tp)
						tp=b[q];
					q=h1[b[q]];
					k++;
				} while (q!=i);
				cost+=(k-2)*tp<tp+(k+1)*min?(k-2)*tp:tp+(k+1)*min;
			}
		cout << cost << endl;
	}

	return 0;
}
