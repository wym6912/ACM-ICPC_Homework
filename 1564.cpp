#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int n,t;
int num[101];
int r[101];
bool flag;
void dfs(int len,int k,int last)
{
    int result;
    if(last==0)
    {
        flag=false;
        for(int i=0;i<len;i++)
        if(i==0)printf("%d",r[i]);
        else printf("+%d",r[i]);
        printf("\n");
        return ;
    }
    for(int i=k;i<n;i++)
     {
          
         if(i==k||num[i]!=num[i-1]&&last-num[i]>=0)// È¥³ýÖØ¸´µÄ²Ù×÷
         {
         r[len]=num[i];
         dfs(len+1,i+1,last-num[i]);
         }      
     }
}
int main()
{
    while(scanf("%d%d",&t,&n)!=EOF)
    {
        if(t==n&&n==0)break;
        flag=true;
        for(int i=0;i<n;i++)
        scanf("%d",&num[i]);
        printf("Sums of %d:\n", t);
        dfs(0,0,t);
        if(flag)printf("NONE\n");
    }
     
}