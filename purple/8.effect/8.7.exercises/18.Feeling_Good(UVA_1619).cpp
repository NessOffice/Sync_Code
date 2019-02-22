#include <cstdio>
#include <cstring>
typedef long long LL;
const int maxn = 100000 + 10;
int data[maxn], L[maxn], R[maxn], s[maxn];
LL sum[maxn];
int main()
{
	// freopen("in.txt", "r", stdin);
	//   freopen("out.txt", "w", stdout);
	int first = 0, n;
	while(~scanf("%d", &n))
	{
		sum[0] = 0;
		for(int i = 1;i <= n;i++)
		{
			scanf("%d", &data[i]);
			sum[i] = sum[i-1] + data[i];
		}
		int t = 0;
		for(int i = 1;i <= n;i++)
		{
			while(t && data[s[t]] >= data[i]) t--;
			L[i] = t ? s[t]+1 : 1;
			s[++t] = i;
		}
		t = 0;
		for(int i = n;i > 0;i--)
		{
			while(t && data[s[t-1]] >= data[i]) t--;
			R[i] = t ? s[t-1]-1 : n;
			s[t++] = i;
		}
		int ansL = 1, ansR = 1;
		LL ans = 0, temp;
		for(int i = 1;i <= n;i++)
		{
			temp = (sum[R[i]]-sum[L[i]-1])*data[i];
			if(temp > ans || (ans == temp && ansR-ansL > R[i]-L[i]))
			{
				ans = temp;
				ansL = L[i];
				ansR = R[i];
			}
		}
		if(first++) putchar('\n');
		printf("%lld\n%d %d\n", ans, ansL, ansR);
	}
	return 0;
}
