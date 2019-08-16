#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tr1/unordered_map>
using namespace std;
typedef long long LL;
const LL MOD = 1e9+7;
const LL maxn = 2e4+5;
LL inv[maxn];
void pre_inv()
{
	inv[1] = 1;
	for(LL i = 2;i < maxn;i++)
		inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
}
LL qpow(LL base, LL expo)
{
    LL res = 1LL;
    while(expo)
    {
        if(expo & 1LL)
            res = res * base % MOD;
        expo >>= 1LL;
        base = base * base % MOD;
    }
    return res;
}
LL calc_inv(LL num)
{
    if(num < maxn) return inv[num];
    else return qpow(num, MOD-2);
}
LL E[maxn], n, border;
tr1::unordered_map<LL, LL> hash_table;
LL calc_E(LL num, bool pre)
{
    if(pre == false && num <= border) return E[num];
    if(pre == false && hash_table[num]) return hash_table[num];
    LL ans = num*calc_inv(num-1)%MOD, temp = 0;
    for(LL l = 2LL, r;l <= num;l = r + 1)
    {
        r = num / (num / l);
        temp = (temp + ((r - l + 1) * calc_E(num / l, false)) % MOD) % MOD;
    }
    temp = temp*calc_inv(num-1)%MOD;
    ans = (ans + temp) % MOD;
    if(num > border) return hash_table[num] = ans;
    return ans;
}
int main()
{
    pre_inv();
    scanf("%lld", &n);
    border = (LL)sqrt(n);
    E[1] = 1LL;
    for(LL i = 2LL;i <= border;i++)
        E[i] = calc_E(i, true);
    printf("%lld\n", calc_E(n, false));
    return 0;
}
