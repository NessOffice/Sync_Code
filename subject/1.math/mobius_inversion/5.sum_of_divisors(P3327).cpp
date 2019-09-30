#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL maxn = 5e4+5;
LL sum_mu[maxn], mu[maxn], g[maxn];
bool isP[maxn];
LL P[maxn];
LL total = 0;
void calc_mu()
{
	memset(isP, true, sizeof(isP));
	memset(P, 0, sizeof(P));
	isP[0] = isP[1] = false;
    mu[1] = 1;
	for(LL i = 2;i < maxn;i++)
	{
		if(isP[i])
        {
            P[++total]=i;
            mu[i] = -1;
        }
		for(LL j = 1;j <= total && i*P[j] < maxn;j++)
		{
			isP[i*P[j]] = false;
			if(!(i%P[j])) break;
            else mu[i*P[j]] = -mu[i];
		}
	}
    for(LL i = 1;i < maxn;i++)
        sum_mu[i] = sum_mu[i-1] + mu[i];
}
void calc_g()
{
    for(LL n = 1;n < maxn;n++)
    {
        for(LL l = 1, r;l <= n;l = r + 1)
        {
            r = n/(n/l);
            g[n] += (r-l+1)*(n/l);
        }
    }
}
int main()
{
    calc_mu();
    calc_g();
    LL T;
    scanf("%lld", &T);
    while(T--)
    {
        LL n, m;
        LL ans = 0;
        scanf("%lld%lld", &n, &m);
        for(LL l = 1, r;l <= min(n, m);l = r + 1)
        {
            r = min(n/(n/l), m/(m/l));
            ans += (sum_mu[r] - sum_mu[l-1])*g[n/l]*g[m/l];
        }
        printf("%lld\n", ans);
    }
    return 0;
}
