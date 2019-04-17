#include <cstdio>
const int maxn = 1e5 + 5;
int pre[3*maxn];
int find(int u)
{
    int v = u;
    while(v != pre[v])
        v = pre[v];
    return pre[u] = v;
}
void join(int u, int v)
{
    pre[find(u)] = find(v);
}
int main()
{
    int n, k, q, x, y, ans = 0;
    scanf("%d%d", &n, &k);
    for(int i = 1;i <= 3*n;i++)
        pre[i] = i;
    while(k--)
    {
        scanf("%d%d%d", &q, &x, &y);
        if(x > n || y > n){ans++;continue;}
        if(q == 1)
        {
            if(find(x+2*n) == find(y) || find(x+n) == find(y)){ans++;continue;}
            join(x, y);join(x+n, y+n);join(x+2*n, y+2*n);
        }
        if(q == 2)
        {
            if(x == y){ans++;continue;}
            if(find(x) == find(y) || find(x+2*n) == find(y)){ans++;continue;}
            join(x+n, y);join(x+2*n, y+n);join(x, y+2*n);
        }
    }
    printf("%d", ans);
	return 0;
}
