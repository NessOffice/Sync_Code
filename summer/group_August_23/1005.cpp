#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <tr1/unordered_map>
using namespace std;
tr1::unordered_map<int, int> sum_f_big;
const int MOD = 1e9+7;
const int maxn = 5e6+5;
int sum_f[maxn];
bool isP[maxn];
int P[maxn];
int total = 0;
void calc_mu()
{
	memset(isP, true, sizeof(isP));
	memset(P, 0, sizeof(P));
	isP[0] = isP[1] = false;
    sum_f[1] = 1;
	for(int i = 2;i < maxn;i++)
	{
		if(isP[i])
        {
            P[++total] = i;
            sum_f[i] = -1;
        }
		for(int j = 1;j <= total && i*P[j] < maxn;j++)
		{
			isP[i*P[j]] = false;
			if(!(i%P[j])) break;
            else sum_f[i*P[j]] = -sum_f[i];
		}
	}
    for(int i = 1;i < maxn;i++)
        sum_f[i] = ((1LL*sum_f[i-1] + 1LL*sum_f[i]*i) % MOD + MOD) % MOD;
}
int sum(int l, int r){return (((1LL*r*(r+1)/2%MOD - 1LL*l*(l-1)/2%MOD) % MOD) + MOD) % MOD;}
int calc_sum_f(int n)
{
    if(n < maxn) return sum_f[n];
    if(sum_f_big[n]) return sum_f_big[n];
    int ans = 1;
    for(int l = 2, r;l <= n;l = r+1)
    {
        r = n/(n/l);
        ans = (((1LL*ans - 1LL*sum(l, r)*1LL*calc_sum_f(n/l) % MOD) % MOD) + MOD) % MOD;
    }
    return sum_f_big[n] = ans;
}
int main()
{
    printf("%d", (1LL*sizeof(sum_f)));
    calc_mu();
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n, nmsl, wsnd, ans = 0;
        scanf("%d%d%d", &n, &nmsl, &wsnd);
        for(int l = 1, r;l <= n;l = r + 1)
        {
            r = n/(n/l);
            int n_ = n/l;
            ans = (1LL*ans + 1LL*((1LL*calc_sum_f(r) - 1LL*calc_sum_f(l-1))%MOD+MOD)%MOD *1LL* n_ % MOD *1LL* (n_+1) % MOD *1LL* (n_-1) % MOD * 166666668LL % MOD) % MOD;
            ans = (1LL*ans % MOD + MOD) % MOD;
        }
        printf("%d\n", ans);
    }
    return 0;
}
