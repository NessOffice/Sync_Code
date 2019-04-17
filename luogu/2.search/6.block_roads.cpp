#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 1e4+7;
int col[maxn], sum[2], ok = 1, ans = 0;
vector<int> G[maxn];
int bfs(int i)
{
    queue<int> q;
    q.push(i);
    col[i] = 0;
    sum[0]++;
    while(!q.empty())
    {
        int u = q.front();q.pop();
        int c = col[u] ^ 1;
        for(int j = G[u].size()-1;j >= 0;j--)
        {
            int v = G[u][j];
            if(col[v] != -1 && col[v] != c)
                return ok = 0;
            if(col[v] == -1)
            {
                col[v] = c;
                sum[c]++;
                q.push(v);
            }
        }
    }
    return 1;
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1;i <= n;i++)
        col[i] = -1;
    while(m--)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i = 1;i <= n && ok;i++)
    {
        if(col[i] != -1 || G[i].empty()) continue;
        sum[0] = sum[1] = 0;
        if(!bfs(i)) ok = 0;
        ans += min(sum[0], sum[1]);
    }
    if(ok) printf("%d\n", ans);
    else printf("Impossible\n");
	return 0;
}
