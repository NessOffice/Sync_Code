#include <cstdio>
#include <cmath>
#include <functional>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL maxn = 1e6+5;
const LL MOD = 167772161LL;
LL a[maxn], b[maxn], inv[maxn], inv_fac[maxn];
LL qpow(LL base, LL expo)
{
	base %= MOD;
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
void NTT(LL *a, LL len, bool inv = false)
{
	LL w = 1, d = qpow(3, (MOD-1)/len), t;
	LL i, j, c, s;
	if(inv)
	{
		for(i = 1, j = len-1;i < j;swap(a[i++], a[j--]));
		for(t = qpow(len, MOD-2), i = 0;i < len;i++) a[i] = a[i] % MOD * t % MOD;
	}
	for(s = len>>1;s;s >>= w = 1, d = d * d % MOD)
		for(c = 0;c < s;c++, w = w * d % MOD)
			for(i = c;i < len;i += s<<1)
			{
				a[i|s] = (a[i] + MOD - (t = a[i|s])) * w % MOD;
				a[i] = (a[i] + t) % MOD;
			}
	for(i = 1;i < len;i++)
	{
		for(j = 0, s = i, c = len>>1;c;c >>= 1, s >>= 1)
			j = j<<1 | s&1;
		if(i < j) swap(a[i], a[j]);
	}
}
int main()
{
	LL n;
	scanf("%lld", &n);
	inv[1] = inv_fac[0] = inv_fac[1] = 1;
	for(LL i = 2;i <= n;i++)
	{
		inv[i] = (MOD - MOD/i) * inv[MOD%i] % MOD;
		inv_fac[i] = inv_fac[i-1] * inv[i] % MOD;
	}
	for(LL i = 0, flag = 1;i <= n;i++, flag = MOD-flag)
	{
		a[i] = flag * inv_fac[i] % MOD,
		b[i] = qpow(i, n) * inv_fac[i] % MOD;
	}
	LL len = 2;
	for(;len <= 2*n + 10;len <<= 1);
	NTT(a, len, false);
	NTT(b, len, false);
	for(LL i = 0;i < len;i++)
		a[i] = a[i] * b[i] % MOD;
	NTT(a, len, true);
	for(LL i = 0;i <= n;i++)
		printf("%lld ", a[i]);
	return 0;
}
