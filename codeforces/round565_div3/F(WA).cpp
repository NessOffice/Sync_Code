#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 2e5 + 5;
int dp[3*maxn];
int main()
{
	memset(dp, 0, sizeof(dp));
	int n, ans = 0, cnt = 0;
	scanf("%d", &n);
	while(n--)
	{
		int k;
		scanf("%d", &k);
		int c1[3] = {-1, -1, -1}, c2 = -1, c3 = -1; // ci for the greatest damage costing i
		while(k--)
		{
			int c, d;
			scanf("%d%d", &c, &d);
			if(c == 2 && d > c2) c2 = d;
			if(c == 3 && d > c3) c3 = d;
			if(c == 1)
			{
				if(d > c1[0]) // not ">=" !!!
				{
					c1[2] = c1[1];
					c1[1] = c1[0];
					c1[0] = d;
				}
				else if(d > c1[1])
				{
					c1[2] = c1[1];
					c1[1] = d;
				}
				else if(d > c1[2])
					c1[2] = d;
			}
		}
		int card1 = max(c1[0], max(c2, c3));
		int card2 = max(c1[0]+c1[1], c1[0]+c2);
		int card3 = c1[0]+c1[1]+c1[2];
		// cardi for the greatest damage by plaing i cards, and here's the detection of them:
		// not possible to play any card <=> card1 == -1
		// not possible to play two cards <=> card2 < card1
		// not possible to play three cards <=> c1[2] == -1
		for(int i = cnt;i >= max(0, cnt-10);i--)
		{
			if(card1 == -1) continue;
			dp[i+1] = max(dp[i+1], dp[i] + card1 + (i % 10 >= 9 ? card1 : 0));
			if(card2 < card1) continue;
			dp[i+2] = max(dp[i+2], dp[i] + card2 + (i % 10 >= 8 ? max(c1[0], c2) : 0));
			if(c1[2] == -1) continue;
			dp[i+3] = max(dp[i+3], dp[i] + card3 + (i % 10 >= 7 ? c1[0] : 0));
		}
		if(dp[cnt+3]) cnt += 3;
		else if(dp[cnt+2]) cnt += 2;
		else if(dp[cnt+1]) cnt += 1;
	}
	for(int i = cnt;i >= max(0, cnt-10);i--)
		ans = max(ans, dp[i]);
	printf("%d", ans);
    return 0;
}
