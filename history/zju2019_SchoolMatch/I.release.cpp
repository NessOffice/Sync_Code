#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
const LL MAXN = 40 + 3;
LL n, m, w[MAXN], exc[MAXN];
LL sum_x2, sum_x, num_total;
LL temp_x2, temp_x, temp_num;
LL pre[MAXN], id;
vector<int> tree[MAXN];
LL qpow(LL base,LL expo)
{
	base %= MOD;
	LL ans = 1;
    while(expo)
    {
        if(expo & 1)
            ans = ans * base % MOD;
        expo >>= 1;
        base = base * base % MOD;
    }
    return ans % MOD;
}
LL inv(LL num)
{
	return qpow(num, MOD-2) % MOD;
}
LL find(LL u)
{
	LL v = u;
    while(v != pre[v])
        v = pre[v];
    return pre[u] = v;
}
void dfs(LL num, LL choose, LL x)
{
	if(num >= tree[id].size())
	{
		temp_x2 = (temp_x2 + x*x%MOD) % MOD;
		temp_x = (temp_x + x) % MOD;
		temp_num++;
		return;
	}
	LL v = tree[id][num];
	if((choose & exc[v]) == 0)
		dfs(num + 1, choose | (1 << v), x*w[v]%MOD);
	dfs(num + 1, choose, x);
}
int main()
{
	scanf("%lld%lld", &n, &m);
	for(LL i = 1;i <= n;i++)
	{
		scanf("%lld", &w[i]);
		exc[i] = 0;
		pre[i] = i;
		tree[i].clear();
	}
	while(m--)
	{
		LL xi, yi;
		scanf("%lld%lld", &xi, &yi);
		exc[xi] |= (1 << yi);
		exc[yi] |= (1 << xi);
		pre[find(xi)] = find(yi);
	}
	for(LL u = 1;u <= n;u++)
		tree[pre[find(u)]].push_back(u);

	sum_x2 = sum_x = num_total = 1;
	for(LL u = 1;u <= n;u++)
	{
		if(tree[u].size() == 0) continue;
		temp_x2 = temp_x = temp_num = 0;
		id = u;
		dfs(0, 0, 1);
		sum_x2 = sum_x2 * temp_x2 % MOD;
		sum_x = sum_x * temp_x % MOD;
		num_total = num_total * temp_num % MOD;
	}
	LL ave = sum_x * inv(num_total) % MOD;
	LL ans = (sum_x2 * inv(num_total) % MOD) - (ave * ave % MOD);
	ans = (ans + MOD) % MOD;
	printf("%lld\n", ans);
	return 0;
}
