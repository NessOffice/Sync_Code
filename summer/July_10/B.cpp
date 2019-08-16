#include <cstdio>
#include <cstring>
#include <cmath>
typedef long long LL;
const LL MOD = 1e9 + 7;
const LL maxn = 1e5 + 5;
const LL maxv = 1e6 + 5;
const LL maxk = 505;
LL dp[maxn][maxk]; // the expectional probability of reaching u u in the k-th life
LL n, k, q;
LL supply[maxn];
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
    inv[0] = 0;
	inv[1] = 1;
	for(LL i = 2;i < n;i++)
		inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
}
void dfs(LL u, LL life)
{
    for(LL i = head[u];i;i = nxt[i])
    {
        LL v = to[i];
        dp[v][life] = dp[u][life] * prob_son[v] % MOD * inv[prob_mom[v]] % MOD * inv[sz[u]] % MOD;
        if(life) dp[supply[v]][life-1] += (dp[u][life] * inv[sz[u]] % MOD * (prob_mom[v] - prob_son[v]) % MOD * inv[prob_mom[v]] % MOD);
        dfs(v, life);
    }
}
void find_supply(LL u, LL sup)
{
    for(LL i = head[u];i;i = nxt[i])
    {
        LL v = to[i];
        supply[v] = sup;
        find_supply(v, mark_supply[v] ? v : sup);
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
    find_supply(1, 1);
    dp[1][k] = 1;
    for(LL life = k;life >= 0;life--)
        dfs(1, life);
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