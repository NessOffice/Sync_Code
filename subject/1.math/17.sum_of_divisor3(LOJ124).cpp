#include <cstdio>
#include <cstring>
typedef long long LL;
const LL maxn = 1e7+5;
const LL MOD = 1e9+7;
LL n, k, a[maxn], sum[maxn];
bool isP[maxn];
LL P[maxn], total = 0;
LL qpow(LL base, LL expo)
{
    LL ans = 1LL;
    while(expo)
    {
        if(expo & 1LL)
            ans = ans * base % MOD;
        expo >>= 1LL;
        base = base * base % MOD;
    }
    return ans;
}
LL calc(LL num){return qpow(num, k);}
void sift(LL maxm)
{
	memset(isP, true, sizeof(isP));
	memset(P, 0, sizeof(P));
	isP[0] = isP[1LL] = false;
	for(LL i = 2LL;i <= maxm;i++)
	{
		if(isP[i])
        {
            P[++total] = i;
            a[i] = calc(i);
        }
		for(LL j = 1LL;j <= total && i*P[j] <= maxm;j++)
		{
			isP[i*P[j]] = false;
            a[i*P[j]] = a[i] * a[P[j]] % MOD;
			if(!(i%P[j])) break;
		}
	}
    sum[1LL] = 1LL;
	for(LL i = 2LL;i <= maxm;i++)
        sum[i] = (sum[i-1LL] + a[i]) % MOD;
}
int main()
{
    scanf("%lld%lld", &n, &k);
    sift(n);
    LL ans = 0;
    for(LL l = 1LL, r;l <= n;l = r + 1LL)
    {
        r = n / (n / l);
        ans = (ans + (n / l) * (sum[r] - sum[l-1LL] + MOD) % MOD) % MOD; // sum[r] - sum[l-1] may be negative!!!
    }
    printf("%lld", ans);
    return 0;
}
