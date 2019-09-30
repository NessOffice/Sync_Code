#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = (1 << 20);
int head[maxn], nxt[maxn], to[maxn], cnt;
int sz[maxn], deg_out[maxn], maxp[maxn], maxd[maxn], sum, root;
bool ok = true;
vector<int> ans;
void add_edge(int u, int v)
{
    cnt++;
    to[cnt] = v;
    nxt[cnt] = head[u];
    head[u] = cnt;
}
void get_root(int u, int fa)
{
	sz[u] = 1, maxp[u] = 0;
	for(int i = head[u];i;i = nxt[i])
	{
		int v = to[i];
		if(v == fa) continue;
		get_root(v, u);
		sz[u] += sz[v];
		maxp[u] = max(maxp[u], sz[v]);
	}
	maxp[u] = max(maxp[u], sum-sz[u]);
	if(maxp[u] < maxp[root]) root = u;
}
void get_info(int u, int fa, int d) // get deg_out, maxd
{
    maxd[u] = d;
    for(int i = head[u];i;i = nxt[i])
	{
		int v = to[i];
		if(v == fa) continue;
        maxd[u] = max(maxd[u], get_info(v, u, d+1));
        deg_out[u]++;
	}
}
bool is_full_binary(int u, int fa)
{
    if(deg_out[u] != 0 && deg_out[u] != 2) return false;
    for(int i = head[u];i;i = nxt[i])
    {
        int v = to[i];
        if(v == fa) continue;
        if(!is_full_binary(v, u)) return false;
    }
    return true;
}
int main()
{
    int n;
    scanf("%d", &n);
    sum = (1 << n) - 2;
    for(int i = sum-1;i;i--)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }
    get_root(1, 0);
    get_max_depth(root, 0, 0);
    if(sz[root] == 3){
        int node = -1;
        for(int i = head[root];i;i = nxt[i])
        {
            int v = to[i];
            if(node == -1) node = v;
            if(maxd[v] > maxd[node]) node = v;
            if(!is_full_binary(to[i]), root)
                ok = false;
        }
        ans.push_back(root);
        ans.push_back(node);
    }else if(sz[root] == 2){
        ;
    }else{
        ok = false;
    }
    if(ok){
        printf("%d\n", ans.size());
        sort(ans.begin(), ans.end());
        for(int i = 0, len = ans.size();i < len;i++)
            printf("%d ", ans[i]);
    }else
        printf("0");
    return 0;
}
