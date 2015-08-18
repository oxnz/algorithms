#include <cstdio> 
#include <cstdlib> 
#include <iostream>

using namespace std;

#define MAXN 1010 

typedef struct { 
    int x,y;
} Node;

Node s[MAXN],r[MAXN];   // dot info
int n;

int cmp1(const void *a,const void *b) { 
    Node *aa=(Node *)a;
    Node *bb=(Node *)b;
    return((aa->y==bb->y)?(aa->x-bb->x):(aa->y-bb->y));
}

int cmp2(const void *a,const void *b) {
    Node *aa=(Node *)a; 
    Node *bb=(Node *)b; 
    return((aa->y==bb->y)?(aa->x-bb->x):(bb->y-aa->y)); 
} 

int isym() {
    int i,k,sum;
    k=n/2+1;
    sum=s[0].y+r[0].y;
    for(i=0;i<k;i++) {
        if(s[i].y+r[i].y!=sum) return(0);   // yes, sym

        if(s[i].x!=r[i].x) return(0);       // otherwise
    }
    return 1;
}

int main() {
	while (cin >> n) {
        for(int i=0;i<n;i++) {
			cin >> s[i].x >> s[i].y;
            r[i]=s[i];
        }
		size_t ss = sizeof s[0];
		size_t sr = sizeof r[0];
        qsort(s,n,ss,cmp1);
        qsort(r,n,sr,cmp2);
        if (isym()==1)
			cout << "YES" << endl;
        else
			cout << "NO" << endl;
    }

    return 0;
}

