#include <cstdio>
#include <cstring>
#include <map>
typedef long long LL;
const int maxn = 10000 + 10;
LL ans[maxn], v[maxn];
std::map<LL, int> forbidden;
bool ok;
LL gcd(LL a, LL b){return a == 0 ? b : gcd(b % a, a);}
bool updata(int d)
{
	for(int i = d - 1;i >= 0;i--) if(v[i] != ans[i])
		return ans[i] == -1 || v[i] < ans[i];
	return false;
}
void dfs(int d, int maxd, LL a, LL b)
{
	if(d == maxd){
		if(b % a) return;
		if(updata(d))
		{
			for(LL i = 0;i < d;i++)
				ans[i] = v[i];
			ok = true;
		}
	}else{
		LL k = b / a;
		int cnt = 0;
		while(1)
		{
			if(a == 1) v[d] = k + cnt;
			else v[d] = ++k;
			LL a2, b2;
			if(a == 1 && !cnt++) a2 = a, b2 = b;
			else a2 = a*v[d] - b, b2 = b*v[d];
			LL D = gcd(a2, b2);
			a2 /= D, b2 /= D;
			if(forbidden.count(v[d])) continue;
			if(d && v[d] <= v[d-1]) continue;
			if(a * v[d] > b * (maxd - d)) return;
			dfs(d + 1, maxd, a2, b2);
		}
	}
}
int main()
{
	// freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	LL T, a, b, k, f, kase = 0;
	scanf("%lld\n", &T);
	while(T--)
	{
		forbidden.clear();
		scanf("%lld%lld%lld", &a, &b, &k);
		while(k--) scanf("%lld", &f), forbidden[f] = 1;
		ok = false;
		int maxd = 1;
		for(;;maxd++)
		{
			memset(ans, -1, sizeof(ans));
			dfs(0, maxd, a, b);
			if(ok) break;
		}
		printf("Case %lld: %d/%d",++kase, a, b);
		for(int i = 0;i < maxd;i++) printf("%c1/%lld", i ? '+' : '=', ans[i]);
		printf("\n");
	}
	return 0;
}