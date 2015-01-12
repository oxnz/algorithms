#include<stdio.h>  

int main() {
	char in[2001];
	long sign[2001],i,min,sum[2001],pre[2001],j,k,n,m,s,p;  
	long long out;     
	while(scanf("%ld %ld\n",&n,&m)!=EOF)  
	{ for(i=1;i<=m;i++) sign[i]=0;  
		for(s=1,out=0;s<=n;s++)  
		{ gets(in);   
			for(i=0;i<m;i++)  
			{   
				if(in[i]=='w') sign[i+1]++;  
				else sign[i+1]=0;            
			}  
			for(i=1,sign[0]=pre[0]=0;i<=m;i++)   
			{ if(sign[i]>=sign[i-1]) {sum[i]=sum[i-1]+sign[i];pre[i]=0;}   
				else  
				{ pre[i]=pre[i-1]+1;  
					p=i-pre[i];  
					while(p>0&&sign[p-1]>=sign[i]) p=p-pre[p-1]-1;  
					if(p<=0) {sum[i]=sign[i]*i;pre[i]=0;}          

					else {sum[i]=sign[i]*(i-p+1)+sum[p-1];pre[i]=i-p-1;}    
				}  
				out+=sum[i];  
			}  
		}  
		printf("%lld\n",out);  
	}  
	return 0;  
}  
