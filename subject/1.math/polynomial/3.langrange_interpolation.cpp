#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL MOD = 998244353;
const LL maxn = 2e3 + 5;
LL calc_mod(LL num)
{
	num %= MOD;
	num += MOD;
	num %= MOD;
	return num;
}
LL qpow(LL base, LL expo)
{
	LL ans = 1LL;
	while(expo)
	{
		if(expo & 1)
			ans = ans * base % MOD;
		expo >>= 1;
		base = base * base % MOD;
	}
	return ans;
}
LL inv(LL num)
{
	num = calc_mod(num);
	return qpow(num, MOD - 2);
}
int main()
{
	LL n, k, ans = 0;
	LL x[maxn], y[maxn];
	scanf("%lld%lld", &n, &k);
	for(LL i = 0;i < n;i++)
		scanf("%lld%lld", &x[i], &y[i]);
	for(LL i = 0;i < n;i++)
	{
		LL son = 1, mom = 1;
		for(LL j = 0;j < n;j++)
			if(i != j)
			{
				son = calc_mod(son * (k - x[j]));
				mom = calc_mod(mom * inv(x[i] - x[j]));
			}
		ans += y[i] * son % MOD * mom % MOD;
		ans %= MOD;
	}
	printf("%lld", ans);
	return 0;
}
