#include<cstdio>
#include<iostream>
#include<algorithm>
  
using namespace std;  
  
int cow[20010];  
  
int main(void)  
{  
    int n;cin>>n;  
    int b;cin>>b;  
    for ( int i = 0;i < n;i++ )  
    {  
        cin>>cow[i];  
    }  
    sort(cow,cow+n);  
    int sum = 0;  
    int i = n;  
    while ( sum < b )  
    {  
        i--;  
        sum+=cow[i];  
    }  
    cout<<n-i<<endl;  
  
  
  
    return 0;  
}  