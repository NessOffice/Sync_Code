#include <cstdio>
#include <cstring>
#include <bitset>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 1e6+5;
bitset<105> ans[maxn];
int n, a[maxn], b[maxn], f[maxn], vis[maxn];
bool solve(int *a, int *b)
{
	memset(f, 0, sizeof(f));
	memset(vis, 0, sizeof(vis));
	vis[0] = 1;
	int top = 0;
	for(int i = 1;i <= n;i++)
		for(int j = top;j >= 0;j--)
		{
			if(!vis[j]) continue;
			// f[j + a[i]] = max(f[j + a[i]], f[j] + b[i]);
			if(j + a[i] < a[0] && f[j] + b[i] > f[j + a[i]])
			{
				vis[j + a[i]] = 1;
				f[j + a[i]] = f[j] + b[i];
				ans[j + a[i]] = ans[j];
				ans[j + a[i]].set(i);
				top = max(top, j + a[i]);
				if(f[j + a[i]] >= b[0])
				{
					printf("NO\n");
					for(int k = 1;k <= n;k++)
						printf("%d", ans[j + a[i]][k] ? 1 : 0);
					putchar('\n');
					return true;
				}
			}
		}
	return false;
}
int main()
{
	scanf("%d", &n);
	for(int i = 0;i <= n;i++) scanf("%d", a+i);
	for(int i = 0;i <= n;i++) scanf("%d", b+i);
	if(!solve(a, b) && !solve(b, a)) printf("YES\n");
	return 0;
}
