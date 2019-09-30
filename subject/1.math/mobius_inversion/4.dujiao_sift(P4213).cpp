#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include<tr1/unordered_map>
using namespace std;
typedef long long LL;
tr1::unordered_map<int, LL> sum_phi_big;
tr1::unordered_map<int, int> sum_mu_big;
const int maxn = 5e6+5;
LL sum_phi[maxn];
int sum_mu[maxn];
bool isP[maxn];
int P[maxn];
int total = 0;
void init()
{
	memset(isP, true, sizeof(isP));
	memset(P, 0, sizeof(P));
	isP[0] = isP[1] = false;
    sum_mu[1] = sum_phi[1] = 1;
	for(int i = 2;i < maxn;i++)
	{
		if(isP[i])
        {
            P[++total]=i;
            sum_mu[i] = -1;
            sum_phi[i] = i-1;
        }
		for(int j = 1, prime = P[j];j <= total && i*prime < maxn;j++, prime = P[j])
		{
			isP[i*prime] = false;
			if(!(i%prime))
            {
                sum_phi[i*prime] = prime * sum_phi[i];
                break;
            }
            sum_phi[i*prime] = sum_phi[prime] * sum_phi[i];
            sum_mu[i*prime] = -sum_mu[i];
		}
	}
    for(int i = 1;i < maxn;i++)
        sum_phi[i] += sum_phi[i-1],
        sum_mu[i] += sum_mu[i-1];
}
int calc_sum_mu(int n)
{
    if(n < maxn) return sum_mu[n];
    if(sum_mu_big[n]) return sum_mu_big[n];
    int ans = 1;
    for(int l = 2, r;l <= n;l = r+1)
    {
        r = n/(n/l);
        ans -= (r-l+1)*calc_sum_mu(n / l);
    }
    return sum_mu_big[n] = ans;
}
LL calc_sum_phi(int n)
{
    if(n < maxn) return sum_phi[n];
    if(sum_phi_big[n]) return sum_phi_big[n];
    LL ans = n*1LL*(n+1)/2LL;
    for(int l = 2, r;l <= n;l = r+1)
    {
        r = n/(n/l);
        ans -= 1LL*(r-l+1)*calc_sum_phi(n / l);
    }
    return sum_phi_big[n] = ans;
}
int main()
{
    init();
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n;
        scanf("%d", &n);
        printf("%lld %d\n", calc_sum_phi(n), calc_sum_mu(n));
    }
    return 0;
}
/*
input:
5
1880071
7261727
9181941
8084555
3730126

output:
1074410833926 128
16028815320048 -534
25626574566284 -323
19867070122580 -2
4229300550230 -187
*/