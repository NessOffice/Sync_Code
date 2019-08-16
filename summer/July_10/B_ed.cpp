#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
const LL maxn = 1e5 + 5;
const LL maxv = 1e6 + 5;
const LL maxk = 505;
LL dp[maxn][maxk]; // the expectional probability of reaching node u in the k-th life
LL n, k, q;
LL supply[maxn], parent[maxn];
LL inv[maxv];
bool mark_supply[maxn];
LL prob_son[maxn], prob_mom[maxn];
LL sz[maxn], head[maxn], nxt[maxn], to[maxn], cnt_of_edge = 0;
void add_edge(LL u, LL v)
{
    cnt_of_edge++;
    to[cnt_of_edge] = v;
    nxt[cnt_of_edge] = head[u];
    head[u] = cnt_of_edge;
    sz[u]++;
}
void calc_inv(LL n)
{
    inv[0] = 0, inv[1] = 1;
	for(LL i = 2;i < n;i++)
		inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
}
void bfs(LL life)
{
    queue<LL> q;
    for(LL i = head[1];i;i = nxt[i])
    {
        LL v = to[i];
        parent[v] = 1;
        supply[v] = 1;
        q.push(to[i]);
    }
    while(!q.empty())
    {
        LL u = q.front();q.pop();
        LL fa = parent[u];
        LL prob_trans = dp[fa][life] * inv[sz[fa]] % MOD;
        dp[u][life] = prob_trans * prob_son[u] % MOD * inv[prob_mom[u]] % MOD;
        if(life) dp[supply[u]][life-1] = (dp[supply[u]][life-1] + prob_trans * (prob_mom[u] - prob_son[u]) % MOD * inv[prob_mom[u]] % MOD) % MOD;
        for(LL i = head[u];i;i = nxt[i])
        {
            LL v = to[i];
            parent[v] = u;
            supply[v] = mark_supply[u] ? u : supply[u];
            q.push(v);
        }
    }
}
int main()
{
    calc_inv(maxv);
    scanf("%lld%lld%lld", &n, &k, &q);
    mark_supply[1] = true;
    for(LL i = 2;i <= n;i++)
    {
        LL fi;
        scanf("%lld", &fi);
        add_edge(fi, i);
    }
    prob_son[1] = prob_mom[1] = 1LL;
    for(LL i = 2;i <= n;i++)
        scanf("%lld%lld", prob_son+i, prob_mom+i);
    for(LL i = 1;i <= q;i++)
    {
        LL qi;
        scanf("%lld", &qi);
        mark_supply[qi] = true;
    }
    dp[1][k] = 1;
    for(LL life = k;life >= 0;life--)
        bfs(life);
    LL ans = 0;
    for(LL leaf = 1;leaf <= n;leaf++)
        if(head[leaf] == 0)
        {
            for(LL life = 0;life <= k;life++)
                ans = (ans + dp[leaf][life]) % MOD;
        }
    printf("%lld", ans);
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

// printf("2/5: %lld\n", 2*inv[5]%MOD);
// printf("3/5: %lld\n", 3*inv[5]%MOD);
// printf("6/25: %lld\n", 6*inv[25]%MOD);
// printf("19/25: %lld\n", 19*inv[25]%MOD);
// printf("44/25: %lld\n", 44*inv[25]%MOD);