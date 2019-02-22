#include <cstdio>
const int maxn = 100000 + 10;
int gas[maxn][2], T, n;
int go(int s)
{
	int fin = (s+1)%n, vol;
	vol = gas[s][0]-gas[s][1];
	for(;fin != s;fin = (fin+1) % n)
	{
		if(vol < 0) return fin;
		vol += gas[fin][0]-gas[fin][1];
	}
	if(vol < 0) return -1;
	return s;
}
int main()
{
	     freopen("in.txt", "r", stdin);
	     freopen("out.txt", "w", stdout);
	scanf("%d", &T);
	for(int kase = 1;kase <= T;kase++)
	{
		scanf("%d", &n);
		for(int i = 0;i < 2;i++)
		for(int j = 0;j < n;j++)
			scanf("%d", &gas[j][i]);
		int ans = -1, start = 0;
		while(ans < 0)
		{
			int fin = go(start);
			if(fin < start) break;
			if(fin == start) ans = start;
			start = fin;
		}
		printf("Case %d: ", kase);
		if(ans == -1) printf("Not possible\n");
		else printf("Possible from station %d\n", ans+1);
	}
	return 0;
}
