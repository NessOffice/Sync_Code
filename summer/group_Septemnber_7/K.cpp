#include <cstdio>
#include <map>
using namespace std;
typedef long long LL;
map<LL, LL> mp;
const int MAXN = 1e6 + 10;
const LL BASE = 1e9;
struct Point{int x, y;}point[1010];
LL encode(int a, int b){return 1LL*a*BASE+b;}
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0;i < n;i++)
	{
		scanf("%d%d", &point[i].x, &point[i].y);
		point[i].x += MAXN;
		point[i].x *= 2;
		point[i].y *= 2;
	}
	for(int i = 0;i < n;i++)
	for(int j = 0;j < n;j++)
	{
		int x_new = point[i].x + point[j].x >> 1;
		int y_new = point[i].y + point[j].y >> 1;
		LL val = encode(x_new, y_new);
		if(!mp.count(val)) mp[val] = 1;
		else mp[val]++;
	}
	LL ans = MAXN;
	for(map<LL, LL>::iterator iter = mp.begin();iter != mp.end();iter++)
		ans = min(ans, n - iter->second);
	printf("%lld", ans);
	return 0;
}
