#include <cstdio>
#include <ctime>
// typedef long long LL;
int ans[1000];
int gcd(int a, int b){return b % a == 0 ? a : gcd(b%a, a);}
bool dfs(int d, int maxd, int a, int b)
{
	if(d == maxd){
		if(b % a) return false;
		else return true;
	}else{
		int k = b / a;
		if(b % a == 0){ans[d] = k;return dfs(d + 1, maxd, a, b);}
		while(ans[d] = ++k)
		{
			if(a * k > b * (maxd - d)) return false;
			int a2 = a*k - b, b2 = b * k;
			int D = gcd(a2, b2);
			a2 /= D, b2 /= D;
			if(dfs(d + 1, maxd, a2, b2)) return true;
		}
	}
}
int main()
{
	int a, b;
	// while(scanf("%d%d", &a, &b), a)
	for(int b = 44;b <= 45;b++)
	for(int a = 1;a < b;a++)
	{
		bool ok = false;
		int maxd = 1;
		for(;maxd < 5;maxd++)
			if(dfs(0, maxd, a, b)){ok = true;break;}
		printf("%d/%d =", a, b);
		if(ok) for(int i = 0;i < maxd;i++) printf("%s1/%d", i ? " + " : " ", ans[i]);
		else printf(" UNCALCUTABLE");
		printf("\n");
	}
	// printf("%d, Time used = %.2lf", tot, double(clock() / CLOCKS_PER_SEC));
	return 0;
}