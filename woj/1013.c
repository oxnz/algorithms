
#include <stdio.h> 
#include <string.h> 

int main() 
{ 
    char s[204],a; 
    int i,len,p[102],j,k,ch; 

    while(scanf("%s",s)!=EOF) 
    { 
        len=strlen(s); 
        for(i=len;i<2*len;i++) 
            s=s[i-len]; 
        a=s[0];  
        p[0]=0; 
        j=1;  
        for(i=1;i<len;i++) 
            if(s<a) 
            { 
                a=s; 
                j=0; 
                p[j++]=i; 
            }  
            else if(s==a) 
            { 
                p[j++]=i; 
            } 
        if(j==1) 
        { 
            ch=p[0]; 
            goto EXIT; 
        } 
        ch=p[0]; 
        for(i=1;i<j;i++) 
            for(k=0;k<len;k++) 
                if(s[p+k]<s[ch+k]) 
                { 
                    ch=p; 
                    break; 
                }  
                else if(s[p+k]>s[ch+k]) 
                    break; 

        EXIT: for(i=ch;i<len+ch;i++) 
        printf("%c",s); 
        printf("\n"); 
    } 
}  

