#include <cstdio>
const int MOD = 10007;
const int maxn = 1007;
int fac[maxn];
int qpow(int base,int expo)
{
    int ans = 1;
    base %= MOD;
    while(expo)
    {
        if(expo & 1)
            ans = ans*base % MOD;
        expo >>= 1;
        base = base*base % MOD;
    }
    return ans;
}
void init()
{
    fac[0] = 1;
    for(int i = 1;i < maxn;i++)
        fac[i] = fac[i-1]*i % MOD;
}
int main()
{
//	  freopen("in.txt", "r", stdin);
//	  freopen("out.txt", "w", stdout);
    init();
    int a, b, k, n, m, ans = 1;
    scanf("%d%d%d%d%d", &a, &b, &k, &n, &m);
    ans = qpow(a, n) * qpow(b, m) % MOD;
    ans = ans * (fac[k] * qpow(fac[m]*fac[k-m] % MOD, MOD-2) % MOD) % MOD;
    printf("%d\n", ans);
	return 0;
}
