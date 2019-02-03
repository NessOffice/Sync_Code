#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL maxn = 4000 + 10;
LL T, n, data[4][maxn], sum[maxn*maxn], targets[maxn*maxn];
int main()
{
//	 freopen("in.txt", "r", stdin);
//	 freopen("out.txt", "w", stdout);
	scanf("%lld", &T);
	while(T--)
	{
		scanf("%lld", &n);
		LL num = 0, cnt = 0;
		for(LL i = 0;i < n;i++)
		{
			for(LL j = 0;j < 4;j++)
				scanf("%lld", &data[j][i]);
			for(LL j = 0;j < i;j++)
			{
				sum[num] = data[0][i] + data[1][j];
				targets[num++] = -data[2][i]-data[3][j];
				sum[num] = data[0][j] + data[1][i];
				targets[num++] = -data[2][j]-data[3][i];
			}
			sum[num] = data[0][i] + data[1][i];
			targets[num++] = -data[2][i]-data[3][i];
		}
		sort(sum, sum + num);
		for(LL i = 0;i < num;i++)
			cnt += (upper_bound(sum, sum + num, targets[i]) - lower_bound(sum, sum + num, targets[i]));
		printf("%lld\n", cnt);
		if(T) printf("\n");
	}
	return 0;
}
