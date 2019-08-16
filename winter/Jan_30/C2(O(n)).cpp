#include <cstdio>
#include <cstring>
typedef long long LL;
const LL maxn = 100000000 + 10;
LL n, ans, P[maxn];
bool isP[maxn];
void SiftPrime(int m)
{
    int index = 0;
	memset(isP,true,sizeof(isP));
	memset(P,0,sizeof(P));
	isP[0] = false;
	isP[1] = false;
	for(int i = 2;i <= m;i++)
    {
		if(isP[i]) P[++index] = i;
		for(int j = 1;j <= index && i*P[j] <= m;j++)
        {
			isP[i*P[j]] = false;
			if(!(i%P[j])) break;
		}
	}
}
void dfs(int num, int prime, int sum, int e)
{
    ans += (n/num)*(sum*(e+1));
    if(num * P[prime] <= n)
        dfs(num * P[prime], prime, sum, e+1);
    for(int i = prime + 1;;i++)
    {
        if(num * P[i] > n) break;
        dfs(num * P[i], i, sum*(e+1), 1);
    }
}
int main()
{
    SiftPrime(maxn);
    while(scanf("%lld", &n) && n)
    {
        ans = 0;
        dfs(1, 1, 1, 0);
        printf("%d\n", ans);
    }
}
