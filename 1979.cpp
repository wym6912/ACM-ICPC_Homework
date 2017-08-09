//#define LOCAL
#include <stdio.h>
#include <string.h>

#define MAXN 20 + 10

char graph[MAXN][MAXN];
int m, n;
int result;

void DFS(int p, int q);

int main()
{
#ifdef LOCAL
	freopen("C:\\Users\\Administrator\\Desktop\\Temp\\ACMTempIn.txt", "r", stdin);
	//freopen("C:\\Users\\Administrator\\Desktop\\Temp\\ACMTempOut.txt", "w", stdout);
#endif


    int i, j;
    int p, q;
    while(scanf("%d%d", &n, &m) && m != 0)
    {
        // Êý¾ÝµÄ³õÊ¼»¯
        result = 0;
        memset(graph, 0, sizeof(graph));

        // Êý¾ÝÊäÈë
        for(i = 0; i < m; i++)
            for(j = 0; j < n; j++)
            {
                scanf("\n%c", &graph[i][j]);
                if(graph[i][j] == '@')
                {
                   p = i;
                   q = j;
                   graph[i][j] = '.';
                }
            }
         // Ëã·¨Ö÷Ìå
         DFS(p , q);
         
         // Êý¾ÝÊä³ö
         printf("%d\n", result);
    }

    return 0;
}

void DFS(int p, int q)
{
   if(p <= m - 1 && p >= 0 && q >= 0 && q <= n - 1 && graph[p][q] == '.')
   {
        result++;
        graph[p][q] = '#';
   }else {
        return;
   }
   
   DFS(p - 1, q);
   DFS(p, q - 1);
   DFS(p, q + 1);
   DFS(p + 1, q);
}