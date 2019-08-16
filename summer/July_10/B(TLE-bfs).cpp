#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;
const int MOD = 1e9 + 7;
const int maxn = 1e5 + 5;
const int maxv = 1e6 + 5;
const int maxk = 505;
int dp[maxn][maxk]; // the expectional probability of reaching node u in the k-th life
int n, k, q;
int supply[maxn], parent[maxn];
int inv[maxv];
bool mark_supply[maxn];
int prob_son[maxn], prob_mom[maxn];
int sz[maxn], head[maxn], nxt[maxn], to[maxn], cnt_of_edge = 0;
void add_edge(int u, int v)
{
    cnt_of_edge++;
    to[cnt_of_edge] = v;
    nxt[cnt_of_edge] = head[u];
    head[u] = cnt_of_edge;
    sz[u]++;
}
void calc_inv(int n)
{
    inv[0] = 0, inv[1] = 1;
	for(int i = 2;i < n;i++)
		inv[i] = 1LL * (MOD - MOD / i) * inv[MOD % i] % MOD;
}
void bfs(int life)
{
    queue<int> q;
    for(int i = head[1];i;i = nxt[i])
    {
        int v = to[i];
        parent[v] = 1;
        supply[v] = 1;
        q.push(to[i]);
    }
    while(!q.empty())
    {
        int u = q.front();q.pop();
        int fa = parent[u];
        int prob_trans = 1LL * dp[fa][life] * inv[sz[fa]] % MOD;
        dp[u][life] = 1LL * prob_trans * prob_son[u] % MOD * inv[prob_mom[u]] % MOD;
        if(life) dp[supply[u]][life-1] = (1LL * dp[supply[u]][life-1] + 1LL * prob_trans * (prob_mom[u] - prob_son[u]) % MOD * inv[prob_mom[u]] % MOD) % MOD;
        for(int i = head[u];i;i = nxt[i])
        {
            int v = to[i];
            parent[v] = u;
            supply[v] = mark_supply[u] ? u : supply[u];
            q.push(v);
        }
    }
}
int main()
{
    calc_inv(maxv);
    scanf("%d%d%d", &n, &k, &q);
    mark_supply[1] = true;
    for(int i = 2;i <= n;i++)
    {
        int fi;
        scanf("%d", &fi);
        add_edge(fi, i);
    }
    prob_son[1] = prob_mom[1] = 1LL;
    for(int i = 2;i <= n;i++)
        scanf("%d%d", prob_son+i, prob_mom+i);
    for(int i = 1;i <= q;i++)
    {
        int qi;
        scanf("%d", &qi);
        mark_supply[qi] = true;
    }
    dp[1][k] = 1;
    for(int life = k;life >= 0;life--)
        bfs(life);
    int ans = 0;
    for(int leaf = 1;leaf <= n;leaf++)
        if(head[leaf] == 0)
        {
            for(int life = 0;life <= k;life++)
                ans = (ans + dp[leaf][life]) % MOD;
        }
    printf("%d", ans);
    return 0;
}
/*
3 1 1
1 1
1 2
1 2
1

3 1 1
1 2
2 5
3 5
1
*/

// printf("2/5: %d\n", 2*inv[5]%MOD);
// printf("3/5: %d\n", 3*inv[5]%MOD);
// printf("6/25: %d\n", 6*inv[25]%MOD);
// printf("19/25: %d\n", 19*inv[25]%MOD);
// printf("44/25: %d\n", 44*inv[25]%MOD);