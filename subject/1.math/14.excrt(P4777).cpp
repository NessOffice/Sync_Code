#include <cstdio>
typedef long long LL;
const LL MAXN = 1e5 + 10;
LL a[MAXN], b[MAXN];
LL euclid(LL a, LL b)
{
    return b == 0 ? a : euclid(b, a % b);
}
LL LCM(LL a, LL b)
{
    return a / euclid(a, b) * b;
}
LL extend_euclid(LL a, LL b, LL &x, LL &y)
{
    if(b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    LL r = extend_euclid(b, a%b, x, y);
    LL temp = y;
    y = x - (a/b)*y;
    x = temp;
    return r;
}
LL qmul(LL a,LL b, LL MOD)
{
	a %= MOD;
    LL ans = 0;
    while(b)
    {
        if(b & 1)
            ans = (ans + a) % MOD;
        b >>= 1;
        a = (a + a) % MOD;
    }
    return ans % MOD;
}
LL exCRT(LL n)// x === bi(mod ai)
{
    LL M, ans;
    M = a[1];
    ans = b[1] % a[1];
    for(LL i = 2;i <= n;i++)
    {
        LL t, temp_y, gcd;
        gcd = extend_euclid(M, a[i], t, temp_y); // t * M[k-1] + a[k] * temp_y = 1
		LL c = (b[i] - ans % a[i] + a[i]) % a[i];
		if(c % gcd) return -1;
		
        t = qmul(t, c / gcd, a[i]); // caution!
        ans += (t*M);
        M = LCM(M, a[i]);
        ans = (ans % M + M) % M;
    }
    return (ans % M + M) % M;
}
int main()
{
    LL n;
    scanf("%lld", &n);
    for(LL i = 1;i <= n;i++)
        scanf("%lld%lld", &a[i], &b[i]);
    printf("%lld\n", exCRT(n));
    return 0;
}
