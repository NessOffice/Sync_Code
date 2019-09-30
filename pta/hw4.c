#include <stdio.h>
#include <string.h>
const int maxn = 1010;
int tree[maxn], vis[maxn];
int lowbit(int x){return x & (-x);}
void update(int id, int delta){for(;id < maxn;id += lowbit(id)) tree[id] += delta;}
int query(int id){int ans = 0;for(;id;id -= lowbit(id)) ans += tree[id];return ans;}
int main()
{
    int m, n, q, ok, lst, now;
    int i;
    scanf("%d%d%d", &m, &n, &q);
    while(q--)
    {
        memset(tree, 0, sizeof(tree));
        memset(vis, 0, sizeof(vis));
        ok = 1, lst = 0;
        for(i = 0;i < n;i++)
        {
            scanf("%d", &now);
            update(now, 1);
            // printf("[DEBUG]query: %d\n", query(now-1));
            now -= query(now-1);
            if(vis[now] || now > m) ok = 0;
            if(now < lst - 1) ok = 0;
            lst = now;
        }
        printf("%s\n", ok ? "YES" : "NO");
    }
    return 0;
}
/*
5 7 5
1 2 3 4 5 6 7
3 2 1 7 5 6 4
7 6 5 4 3 2 1
5 6 4 3 7 2 1
1 7 6 5 4 3 2
*/