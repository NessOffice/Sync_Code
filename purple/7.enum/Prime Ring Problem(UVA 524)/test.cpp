#include <cstdio>
const int maxn = 40;
int ring[maxn], n;
bool isP[maxn], vis[maxn];
void init()
{
	for(int i = 0;i < maxn;i++)
		isP[i] = true;
	for(int i = 2;i < maxn;i++)
	{
		if(!isP[i]) continue;
		for(int j = 2*i;j < maxn;j += i)
			isP[j] = false;
	}
}
void primeDFS(int cur)
{
	if(cur == n && isP[ring[0]+ring[n-1]]){
		printf("1");
		for(int i = 1;i < n;i++)
			printf(" %d", ring[i]);
		printf("\n");
	}else{
		for(int i = 2;i <= n;i++)
		if(!vis[i] && isP[i+ring[cur-1]]){
			vis[i] = true;
			ring[cur] = i;
			primeDFS(cur+1);
			vis[i] = false;
		}
	}
}
int main()
{
	// freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	init();
	int kase = 0;
	while(~scanf("%d", &n))
	{
		for(int i = 0;i <= n;i++) vis[i] = false;
		if(kase++) printf("\n");
		printf("Case %d:\n", kase);
		ring[0] = 1;
		primeDFS(1);
	}
	return 0;
}
