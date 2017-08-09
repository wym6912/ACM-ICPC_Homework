#include<stdio.h>
int fi[30];
int di[30];
int ti[30];
int cfi[30];
int h,n;
struct st
{
	int max;
	int num[30];
}lake[30];
int getmax(int p[],int i,int j)
{
	int l=i,max=p[i];
	for(int m=i+1;m<=j;m++)
	{
		if(max<p[m])
		{
			max=p[m];
			l=m;
		}
	}
	return l;
}
void getfish()
{
	for(int i=1;i<=n;i++)
	{
		lake[i].max=0;
		for(int j=1;j<=n;j++)
		{
			lake[i].num[j]=0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		int t=0;
		int T=h*60;
		for(int j=1;j<=i;j++)
		{
			cfi[j]=fi[j];
			if(j<i)
			T=T-ti[j]*5;
		}
		while(t<T)
		{
			int k=getmax(cfi,1,i); 
			lake[i].num[k]+=5;
			lake[i].max+=cfi[k];
			cfi[k]=(cfi[k]>di[k])?cfi[k]-di[k]:0;
			t+=5;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cfi[i]=lake[i].max;
	}
	int l=getmax(cfi,1,n);
	for(int i=1;i<=n;i++)
	{
		if(i!=n)
			printf("%d, ",lake[l].num[i]);
		else
			printf("%d\n",lake[l].num[i]); 
	}
	printf("Number of fish expected: %d\n\n",lake[l].max);
}
int main()
{
	while(scanf("%d",&n),n)
	{
		scanf("%d",&h);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&fi[i]);
		}
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&di[i]);
		}
		for(int i=1;i<n;i++)
		{
			scanf("%d",&ti[i]);
		}
		getfish(); 
	}
}  