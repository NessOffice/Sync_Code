#include <cstdio>
#include <map>
using namespace std;
typedef long long LL;
const LL maxn = 2e6+10;
const LL MOD = 1e9+7;
LL head[maxn], to[maxn], nxt[maxn], sz[maxn], dep[maxn], dep_max, cnt;
LL qpow(LL base, LL expo)
{
	LL ans = 1;
	while(expo)
	{
		if(expo & 1LL)
			ans = ans * base % MOD;
		expo >>= 1LL;
		base = base * base % MOD;
	}
	return ans;
}
void add_edge(LL u, LL v)
{
	cnt++;
	to[cnt] = v;
	nxt[cnt] = head[u];
	head[u] = cnt;
}
LL calc_p(LL u, LL pa)
{
//	printf("[DBEUG]%lld %lld\n", u, sz[u]);
	if(sz[u] == 0)
		return dep[u] == dep_max ? 0 : 1;
	LL ans = 0;
	LL mom = qpow(sz[u], MOD-2);
	for(LL i = head[u];i;i = nxt[i])
	{
		LL v = to[i];
		if(v == pa) continue;
		ans = (ans + calc_p(v, u) * mom % MOD) % MOD;
//		printf("[DBEUG]%lld %lld\n", u, mom);
	}
	return qpow(ans, sz[u]);
}
void dfs(LL u, LL pa, LL d)
{
	dep[u] = d;
	dep_max = max(dep_max, d);
	for(LL i = head[u];i;i = nxt[i])
	{
		LL v = to[i];
		if(v == pa) continue;
		dfs(v, u, d + 1);
		sz[u]++;
	}
}
int main()
{
	LL n;
	scanf("%lld", &n);
	for(LL i = 0;i < n-1;i++)
	{
		LL u, v;
		scanf("%lld%lld", &u, &v);
		add_edge(u, v);
		add_edge(v, u);
	}
	dfs(1, 0, 0);
	printf("%lld", (1-calc_p(1, 0)+MOD) % MOD);
	return 0;
}
