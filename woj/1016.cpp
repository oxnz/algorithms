#include <stdio.h> 
#include <stdlib.h> 

#define MAXN 1010 

typedef struct node { 
    int x,y;
} Node;

Node s[MAXN],r[MAXN];   // s,r分别为升序和降序后点的信息 
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
        if(s[i].y+r[i].y!=sum) return(0);   // 两点不对称的情况 

        if(s[i].x!=r[i].x) return(0);       // 关于y对称但是x不一样 
    }
    return 1;
}

int main() {
    int i;
    while(scanf("%d",&n)!=EOF) {
        for(i=0;i<n;i++) {
            scanf("%d%d",&s[i].x,&s[i].y);
            r[i]=s[i];
        }
        qsort(s,n,sizeof(s[0]),cmp1);
        qsort(r,n,sizeof(r[0]),cmp2);
        if (isym()==1)
			printf("YES\n");
        else
			printf("NO\n"); 
    }

    return 0;
}

