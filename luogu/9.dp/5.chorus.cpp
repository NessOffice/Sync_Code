#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int T[120], len[2][120];
int main()
{
	int n, ans = 0;
	scanf("%d", &n);
	for(int i = 1;i <= n;i++)
	{
		scanf("%d", &T[i]);
		len[0][i] = len[1][i] = 1;
	}
	for(int i = 1;i <= n;i++)
		for(int j = i+1;j <= n;j++)
			if(T[j] > T[i]) len[0][j] = max(len[0][j], len[0][i]+1);
	for(int i = n;i >= 1;i--)
		for(int j = i-1;j >= 1;j--)
			if(T[j] > T[i]) len[1][j] = max(len[1][j], len[1][i]+1);
	for(int i = 1;i <= n;i++)
		ans = max(ans, len[0][i] + len[1][i] - 1);
	printf("%d\n", n - ans);
	return 0;
}
