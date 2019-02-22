#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 10000 + 10;
int ans[2][2*maxn], cnt;
int T, n, a[maxn];
void change(int L, int R)
{
	for(int i = L, j = L+(R-L+1)/2;j <= R;i++, j++)
		swap(a[i], a[j]);
}
int main()
{
	//   freopen("in.txt", "r", stdin);
	//   freopen("out.txt", "w", stdout);
	scanf("%d", &T);
	while(T--)
	{
		cnt = 0;
		scanf("%d", &n);
		for(int i = 1;i <= n;i++)
			scanf("%d", &a[i]);
		for(int i = 1;i <= n;i++)
		{
			int p = find(a+i, a+n+1, i) - a;
			if(p == i) continue;
			if(2*p-i-1 > n)
			{
				change(i+1-((p-i)&1), p);//replace p with n results in WA? Why?
				ans[0][cnt] = i+1-((p-i)&1);
				ans[1][cnt] = p;
				cnt++;
				p = find(a+i, a+n+1, i) - a;
				if(p == i) continue;
			}
			change(i, 2*p-i-1);
			ans[0][cnt] = i;
			ans[1][cnt] = 2*p-i-1;
			cnt++;
		}
		printf("%d\n", cnt);
		for(int i = 0;i < cnt;i++)
			printf("%d %d\n", ans[0][i], ans[1][i]);
	}
	return 0;
}
