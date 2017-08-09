#include <stdio.h>
int n;  
int a[1001][1001];  
int t;  
int main()  
{  
    int i,j;  
    while(~scanf("%d",&n)&&n)  
    {  
        t=1;  
        for(i=1;i<=n;++i)  
            for(j=1;j<=n;++j)  
                scanf("%d",&a[i][j]);  
        for(i=1;t&&i<n;i++)  
            for(j=1;t&&j<n;j++)  
                if(a[i][j]+a[i+1][j+1]!=a[i][j+1]+a[i+1][j])  
                    t=0;  
        if(t)  
            puts("homogeneous");  
        else  
            puts("not homogeneous");  
    }  
    return 0;  
}