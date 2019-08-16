#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 5e4+5;
int sum_mu[maxn], mu[maxn];
bool isP[maxn];
int P[maxn];
int total = 0;
void calc_mu()
{
	memset(isP, true, sizeof(isP));
	memset(P, 0, sizeof(P));
	isP[0] = isP[1] = false;
    mu[1] = 1;
	for(int i = 2;i <= maxn;i++)
	{
		if(isP[i])
        {
            P[++total]=i;
            mu[i] = -1;
        }
		for(int j = 1;j <= total && i*P[j] < maxn;j++)
		{
			isP[i*P[j]] = false;
			if(!(i%P[j])) break;
            else mu[i*P[j]] = -mu[i];
		}
	}
    for(int i = 1;i < maxn;i++)
        sum_mu[i] = sum_mu[i-1] + mu[i];
}
int main()
{
    calc_mu();
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int a, b, d;
        LL ans = 0;
        scanf("%d%d%d", &a, &b, &d);
        for(int l = 1, r;l <= min(a, b);l = r+1)
        {
            r = min(a/(a/l), b/(b/l));
            ans += 1LL*(a/l/d)*(b/l/d)*(sum_mu[r] - sum_mu[l-1]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
