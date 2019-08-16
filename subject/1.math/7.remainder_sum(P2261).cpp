#include <cstdio>
typedef long long LL;
LL min(LL a, LL b){return a < b ? a : b;}
int main()
{
	//   freopen("in.txt", "r", stdin);
	//   freopen("out.txt", "w", stdout);
	LL n, k, p, ans;
	scanf("%lld%lld", &n, &k);
	ans = n*k;
	for(LL l = 1, r;l < n;l = r+1)
	{
		LL p = k/l;
		r = p ? min(k/p, n) : n;
		ans -= p*(r-l+1)*(l+r)/2;
	}
	printf("%lld\n", ans);
	return 0;
}
