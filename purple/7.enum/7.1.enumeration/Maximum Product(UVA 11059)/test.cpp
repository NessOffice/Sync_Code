#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	// freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	int n, flag, kase = 0;
	long long s, pi[2][20], ans;//pi[0] for max{postive}
	while(~scanf("%d", &n))
	{
		pi[0][0] = pi[1][0] = 0;
		for(int i = 1;i <= n;i++)
		{
			scanf("%lld", &s);
			if(s > 0){
				pi[0][i] = max(pi[0][i - 1] * s, s);
				pi[1][i] = pi[1][i - 1] * s;
			}else{
				pi[0][i] = pi[1][i - 1] * s;
				pi[1][i] = min(pi[0][i - 1] * s, s);
			}
		}
		ans = 0;
		for(int i = 1;i <= n;i++) ans = max(ans, pi[0][i]);
		printf("Case #%d: The maximum product is %lld.\n\n", ++kase, ans);
	}
	return 0;
}