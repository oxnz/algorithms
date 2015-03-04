#include<iostream>
#include <cstdio>

using namespace std;

int main () {
    int n;
	int tmp;
	int total;
	int i;
    while(scanf("%d",&n),n!=0) {
        scanf("%d",&total);
        for(i=1;i<n;i++) {
            scanf("%d",&tmp);
            if(tmp>total)
				total=tmp;
        }
        total%=2006;
        while(n>20) {
			total = (total << 20) % 2006;
            n-=20;
        }
		total = (total << (n-1))%2006;
        if(total<0)
			total+=2006;
		cout << total << endl;
    }
    return 0;
}

