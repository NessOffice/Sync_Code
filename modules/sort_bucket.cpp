#include <cstdio>
#include <algorithm>
using namespace std;
#define MAXN 1010
int vis[MAXN];
int main()
{
	for(int i = 0;i < MAXN;i++)
		vis[i] = 0;
	int n, num, cnt = 0;
	scanf("%d",&n);
	for(int i = 0;i < n;i++)
	{
		scanf("%d",&num);
		if(!vis[num])
			cnt++,
			vis[num] = 1;
	}
	printf("%d\n", cnt);
	int cnt2 = cnt;
	for(int i = 1;i < MAXN;i++)
	{
		if(!vis[i]) continue;
		printf("%d", i), cnt2--;
		if(cnt2) putchar(' ');
		else break;
	}
	return 0;
}
