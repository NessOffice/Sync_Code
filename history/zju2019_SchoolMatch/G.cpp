#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL MAXN = 1e6 + 5;
LL len[2], pos[2][MAXN], pos_max[2];
int main()
{
	LL T, n, k;
	scanf("%lld", &T);
	while(T--)
	{
		LL ans = 0, temp;
		len[0] = len[1] = 0;
		scanf("%lld%lld", &n, &k);
		while(n--)
		{
			scanf("%lld", &temp);
			if(temp == 0) continue;
			LL flag = (temp > 0 ? 0 : 1);
			pos[flag][len[flag]++] = (temp > 0 ? temp : -temp);
		}
		for(LL i = 0;i <= 1;i++)
		{
			sort(pos[i], pos[i] + len[i]);
			pos_max[i] = len[i] ? pos[i][len[i]-1] : 0;
			for(LL j = (len[i]+k-1) % k;j < len[i];j += k)
				ans += 2*pos[i][j];
		}
		ans -= max(pos_max[0], pos_max[1]);
		printf("%lld\n", ans);
	}
	return 0;
}
