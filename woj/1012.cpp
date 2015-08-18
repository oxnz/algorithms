#include<cstdio>
#include <iostream>

using namespace std;

void zero(long a[], int n) {
		for(int i=1;i<=n;i++)
			a[i]=0;
}

int main() {
	char in[2001];
	long sign[2001];
	long min,sum[2001],sub[2001],j,k,n,m,s,p;
	long long out;
	long i;
	while (cin >> n >> m) {
		zero(sign, m);
		for(s=1,out=0;s<=n;s++) {
			gets(in);
			for(i=0;i<m;i++)
			{
				if(in[i]=='w')
					sign[i+1]++;
				else
					sign[i+1]=0;
			}
			for(i=1,sign[0]=sub[0]=0;i<=m;i++)
			{
				if(sign[i]>=sign[i-1])
				{sum[i]=sum[i-1]+sign[i];sub[i]=0;}
				else
				{ sub[i]=sub[i-1]+1;
					p=i-sub[i];
					while(p>0&&sign[p-1]>=sign[i]) p=p-sub[p-1]-1;
					if(p<=0) {sum[i]=sign[i]*i;sub[i]=0;}

					else {sum[i]=sign[i]*(i-p+1)+sum[p-1];sub[i]=i-p-1;}
				}
				out+=sum[i];
			}
		}
		cout << out << endl;
	}
	return 0;
}
