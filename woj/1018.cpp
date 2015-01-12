#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int h1[65537];
int h2[65537];
int a[5001];
int b[5001];
bool sign[5001];

int main() {
	int n,i,k,tp,cost,q;
	int min;
	while(scanf("%d",&n)!=EOF && n!=0) {
		min=65538;
		memset(sign,0,sizeof(sign));
		cost=0;
		for (i=1;i<=n;i++) {
			scanf("%d",&a[i]);
			if (a[i]<min) min=a[i];
			cost+=a[i];
			h1[a[i]]=i;
		}
		for (i=1;i<=n;i++) {
			scanf("%d",&b[i]);
			h2[b[i]]=i;
		}
		for (i=1;i<=n;i++)
			if (!sign[i]) {
				tp=65538;
				q=i;
				k=0;
				do {
					sign[q]=true;
					if (b[q]<tp)
						tp=b[q];
					q=h1[b[q]];
					k++;
				} while (q!=i);
				cost+=(k-2)*tp<tp+(k+1)*min?(k-2)*tp:tp+(k+1)*min;
			}
		printf("%d\n",cost);
	}

	return 0;
}
