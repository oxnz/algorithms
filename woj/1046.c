#include<stdio.h> 

int main() 
{ 
    int T,N,count; 
    int array[255]; 
    scanf("%d",&T); 
    for(int z=0;z<T;z++) 
    { 
        count=0; 
        scanf("%d",&N); 
        if  ((N<=0)||(N>3000)) return(1); 
        for(int i=0;i<N;i++) 
        { 
            scanf("%d",&array[i]); 
        }     
        for(int j=0;j<N;j++) 
         {          
            int exchange=0; 
            for(int k=0;k<N-1-j;k++) 
            { 
                if(array[k]>array[k+1]) 
                { 
                    exchange=1; 
                    count++; 
                    int temp; 
                    temp=array[k]; 
                    array[k]=array[k+1]; 
                    array[k+1]=temp; 
                } 
            } 
            if(exchange==0) break; 
        } 
        printf("%d\n",count); 
    } 
} 
