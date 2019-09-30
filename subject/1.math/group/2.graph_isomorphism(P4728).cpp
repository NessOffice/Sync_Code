#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL maxn = 60;
LL n, m, MOD, ans, num[maxn], gcd[maxn][maxn], tot, fac[maxn], inv[maxn], inv_fac[maxn];
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
void calc()
{
    LL sum = 0, cnt = fac[n], same = 1;
    for(LL i = 1;i <= tot;i++)
    {
        sum += num[i] / 2; // no MOD!!!
        for(LL j = i+1;j <= tot;j++)
            sum += gcd[num[i]][num[j]];
        cnt = cnt * inv[num[i]] % MOD;
        if(i > 1 && num[i] == num[i-1]) same++;
        else cnt = cnt * inv_fac[same] % MOD, same = 1;
    }
    cnt = cnt * inv_fac[same] % MOD;
    ans = (ans + cnt % MOD * qpow(m, sum) % MOD) % MOD;
}
void dfs(LL d, LL lst)
{
    if(d == n){calc();return;}
    for(LL i = lst;i <= n - d;i++)
    {
        num[++tot] = i;
        dfs(d + i, i);
        tot--;
    }
}
void init()
{
    fac[1] = inv[1] = inv_fac[1] = 1;
    for(LL i = 2;i < maxn;i++)
    {
        fac[i] = fac[i-1] * i % MOD;
        inv[i] = (MOD - MOD/i) * inv[MOD%i] % MOD;
        inv_fac[i] = qpow(fac[i], MOD-2);
    }
    
    for(LL i = 1;i < maxn;i++)
    for(LL j = 1;j < maxn;j++)
        gcd[i][j] = __gcd(i, j);
}
int main()
{
    scanf("%lld%lld%lld", &n, &m, &MOD);
    init();
    dfs(0, 1);
    printf("%lld", ans * inv_fac[n] % MOD);
    return 0;
}
