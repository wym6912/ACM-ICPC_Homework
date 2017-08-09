#include<stdio.h>  
#include<string.h>  
#include<algorithm>  
using namespace std;  
#define MAXN 20020  
int a[MAXN];  
int main()  
{  
    int i,j,n,m,sum,temp;  
    while(scanf("%d %d",&n,&m)!=EOF)  
    {  
       memset(a,0,sizeof(a));  
       for(i=0;i<n;i++)  
       scanf("%d",&a[i]);  
       sort(a,a+n);  
       temp=n;  
       sum=0;  
       for(i=0;i<temp;i++)  
         for(j=i+1;j<temp;j++)  
         {  
            if(a[i]+a[j]<=m)  
            {  
               sum++;  
            }  
            else  
            {  
                temp=j;
            }  
         }  
       printf("%d",sum);  
    }  
    return 0;  
}  