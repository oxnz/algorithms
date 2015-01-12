#include<stdio.h>

int main () {
    int n,t,total,i;
    while(scanf("%d",&n),n!=0) {
        scanf("%d",&total);
        for(i=1;i<n;i++) {
            scanf("%d",&t);
            if(t>total)total=t;
        }
        total%=2006; 
        while(n-1>=20) {
            total<<=20;total%=2006;
            n-=20;
        }
        total<<=n-1;total%=2006; 
        if(total<0)total+=2006; 
        printf("%d\n",total); 
    } 
    return 0; 
} 

