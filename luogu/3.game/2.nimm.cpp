#include <cstdio>
const int maxn = 5e5 + 5;
int k, res = 0, a[maxn];
void solve()
{
	for(int i = 0;i < k;i++)
	if((res^a[i]) < a[i])
	{
		printf("%d %d\n", a[i]-(res^a[i]), i+1);
		a[i] ^= res;
		for(int j = 0;j < k;j++)
		{
			if(j) putchar(' ');
			printf("%d", a[j]);
		}
		putchar('\n');
		break;
	}
}
int main()
{
	//   freopen("in.txt", "r", stdin);
	//   freopen("out.txt", "w", stdout);
	scanf("%d", &k);
	for(int i = 0;i < k;i++)
	{
		scanf("%d", &a[i]);
		res ^= a[i];
	}
	if(res) solve();
	else printf("lose\n");
	return 0;
}
