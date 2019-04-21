#include <cstdio>
#include <cstring>
typedef long long LL;
const LL MOD = 1e9 + 7;
const LL MAXN = 40 + 3;
LL n, m, w[MAXN], exc[MAXN];
LL sum_x2, sum_x, num_total;
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
void dfs(LL num, LL choose, LL x)
{
	if(num > n)
	{
		sum_x2 = (sum_x2 + x*x%MOD) % MOD;
		sum_x = (sum_x + x) % MOD;
		num_total++;
		return;
	}
	if((choose & exc[num]) == 0)
		dfs(num + 1, choose | (1 << num), x*w[num]%MOD);
	dfs(num + 1, choose, x);
}
int main()
{
//	freopen("debug_I_input.txt", "r", stdin);
//	freopen("debug_I_out_2.txt", "w", stdout);
	LL T;
	scanf("%lld", &T);
	while(T--)
	{
		memset(exc, 0, sizeof(exc));
		scanf("%lld%lld", &n, &m);
		for(LL i = 1;i <= n;i++)
			scanf("%lld", &w[i]);
		while(m--)
		{
			LL xi, yi;
			scanf("%lld%lld", &xi, &yi);
			exc[xi] |= (1 << yi);
			exc[yi] |= (1 << xi);
		}
	
		sum_x2 = sum_x = num_total = 0;
		dfs(1, 0, 1);
		LL ave = sum_x * inv(num_total) % MOD;
		LL ans = (sum_x2 * inv(num_total) % MOD) - (ave * ave % MOD);
		ans = (ans + MOD) % MOD;
		printf("%lld\n", ans);
	}
	return 0;
}
