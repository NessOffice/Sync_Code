#include <cstdio>
#include <cmath>
using namespace std;
typedef long long LL;
const LL maxn = 1e6+5; // sqrt(1e10)
const LL MOD = 1e9+7;
LL num_prime, prime[maxn], sum_p[maxn], sum_p2[maxn], g1[maxn], g2[maxn], num_w, w[maxn];
LL n, sqrt_n;
LL id1[maxn], id2[maxn];
bool isnt_prime[maxn];
void sift(LL maxn)
{
    for(LL i = 2;i <= maxn;i++)
    {
        if(!isnt_prime[i])
        {
            prime[++num_prime] = i;
            sum_p[num_prime] = (sum_p[num_prime-1] + i) % MOD;
            sum_p2[num_prime] = (sum_p2[num_prime-1] + i*i%MOD) % MOD;
        }
        for(LL j = 1;j <= num_prime && prime[j]*i <= maxn;j++)
        {
            isnt_prime[prime[j]*i] = true;
            if(i % prime[j] == 0) break;
        }
    }
}
LL S(LL m, LL j)
{
    if(prime[j] >= m) return 0;
    LL k = (m <= sqrt_n ? id1[m] : id2[n / m]);
    LL ans = (((g2[k]-g1[k])-(sum_p2[j]-sum_p[j]))%MOD+MOD)%MOD;
    for(LL i = j + 1;i <= num_prime && prime[i]*prime[i] <= m;i++)
        for(LL e = 1, p = prime[i];p <= m;e++, p *= prime[i])
        {
            LL p_ = p % MOD;
            ans = ((ans + p_*(p_-1)%MOD*(S(m/p, i)+(e!=1)))%MOD+MOD)%MOD;
        }
    return ans;
}
LL qpow(LL base, LL expo)
{
    LL ans = 1;
    base %= MOD;
    while(expo)
    {
        if(expo & 1LL)
            ans = ans * base % MOD;
        expo >>= 1LL;
        base = base * base % MOD;
    }
    return ans;
}
LL inv_6 = qpow(6, MOD-2);
void get_id()
{
    for(LL l = 1, r;l <= n;l = r + 1)
    {
        r = n/(n/l);
        w[++num_w] = n / l;
        g1[num_w] = w[num_w] % MOD;
        g2[num_w] = (g1[num_w]*(g1[num_w]+1)%MOD*(2*g1[num_w]+1)%MOD*inv_6%MOD+2*MOD-1)%MOD;
        g1[num_w] = (g1[num_w]*(g1[num_w]+1)/2-1)%MOD;
        if(n/l <= sqrt_n) id1[n/l] = num_w;
        else id2[n/(n/l)] = num_w;
    }
}
void get_g()
{
    for(LL i = 1;i <= num_prime;i++)
        for(LL j = 1;j <= num_w && prime[i]*prime[i] <= w[j];j++)
        {
            LL val = w[j] / prime[i];
            LL k = (val <= sqrt_n ? id1[val] : id2[n / val]);
            g1[j] = ((g1[j] - prime[i]*(g1[k]-sum_p[i-1])%MOD)%MOD+MOD)%MOD;
            g2[j] = ((g2[j] - prime[i]*prime[i]%MOD*(g2[k]-sum_p2[i-1]+MOD)%MOD)%MOD+MOD)%MOD;
        }
//    for(LL j = 1;j <= 1000;j++)
//    	printf("%lld %lld\n", g1[j], g2[j]);
}
int main()
{
//	freopen("o1.txt", "w", stdout);
    scanf("%lld", &n);
    sqrt_n = sqrt(n);
    sift(sqrt_n);
//    for(LL j = 1;j <= 10000;j++)
//    	printf("%lld\n", sum_p2[j]);
    get_id();
    get_g();
    
    printf("%lld\n", (S(n, 0)+1)%MOD);
    return 0;
}
