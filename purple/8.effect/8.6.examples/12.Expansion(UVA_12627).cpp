#include <cstdio>
long long red(int k){return k ? 3*red(k-1) : 1;}
long long above(int k, int i)
{
	if(i == 0) return 0;
	if(k == 0) return 1;
	int k2 = 1 << (k-1);
	if(i >= k2) return above(k-1, i-k2) + 2*red(k-1);
	else return 2*above(k-1, i);
}
int main()
{
	//   freopen("in.txt", "r", stdin);
	//   freopen("out.txt", "w", stdout);
	int T, k, a, b;
	scanf("%d", &T);
	for(int kase = 1;kase <= T;kase++)
	{
		scanf("%d%d%d", &k, &a, &b);
		printf("Case %d: %lld\n", kase, above(k, b) - above(k, a-1));
	}
	return 0;
}
