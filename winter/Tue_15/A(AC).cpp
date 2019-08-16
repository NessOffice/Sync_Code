#include <cstdio>
#include <cstring>
const int maxn = 1e2 + 5;
int n;
char grids[maxn][maxn];
int tot_A, tot_B;
int A[maxn][maxn], B[maxn][maxn];
int book[maxn*maxn], couple[maxn*maxn];
struct Node{int to, next;}edges[maxn*maxn];
int head[maxn*maxn], cnt_of_edges;
void add_edge(int u, int v)
{
    edges[cnt_of_edges].to = v;
    edges[cnt_of_edges].next = head[u];
    head[u] = cnt_of_edges++;
}
void init()
{
    cnt_of_edges = 0;
    tot_A = tot_B = 0;
    memset(head, -1, sizeof(head));
}
bool hungary_dfs(int lft)
{
    for(int i = head[lft];i != -1;i = edges[i].next)
	{
        int rgt = edges[i].to;
		if(book[rgt]) continue;
		book[rgt] = 1;
		if(couple[rgt] == -1 || hungary_dfs(couple[rgt]))
		{
			couple[rgt] = lft;
			return true;
		}
	}
	return false;
}
int hungary()
{
    memset(couple, -1, sizeof(couple));
    int matches = 0;
    for(int i = 0;i < tot_A;i++)
    {
        memset(book, 0, sizeof(book));
        if(hungary_dfs(i))
            matches++;
    }
    return matches;
}
void solve()
{
    for(int i = 0;i < n;i++)
        scanf("%s", grids[i]);
    for(int i = 0;i < n;i++)
    for(int j = 0;j < n;j++)
        if(grids[i][j] == 'S')
        {
            if(j == 0 || grids[i][j-1] == 'W')
                A[i][j] = tot_A++;
            else
                A[i][j] = A[i][j-1];
        }
    for(int j = 0;j < n;j++)
    for(int i = 0;i < n;i++)
        if(grids[i][j] == 'S')
        {
            if(i == 0 || grids[i-1][j] == 'W')
                B[i][j] = tot_B++;
            else
                B[i][j] = B[i-1][j];
        }

    for(int i = 0;i < n;i++)
    for(int j = 0;j < n;j++)
        if(grids[i][j] == 'S')
            add_edge(A[i][j], B[i][j]);
    
    printf("%d\n", hungary());
}
int main()
{
    while(1)
    {
        scanf("%d", &n);
        if(n == 0) break;
        init();
        solve();
    }
    return 0;
}