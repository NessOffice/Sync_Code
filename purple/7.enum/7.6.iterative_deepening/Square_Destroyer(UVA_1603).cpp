#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;
const int maxn = 2*5*6 + 5;
struct Stick{
	bool invalid;
	int squares;
	set<int> sid;
}sticks[maxn];
int n, m, T;
int rank[maxn];
bool cmp(int i, int j){return sticks[i].squares > sticks[j].squares;}
int row(int x, int y){return (2*n+1)*(x-1)+y;}
int col(int x, int y){return (2*n+1)*(x-1)+y+n;}
/*int h(int d)
{
	int r2 = 0;
	for(int i = 1;i <= d;i++)
		r2 += sticks[rank[i]].squares;
	return r2;
}
bool dfs(int d, int maxd, int remain)
{
	if(remain == 0) return true;
	if(h(maxd - d) > remain) return false;
	if(sticks[rank[1]] == 1) return true;
}*/
int main()
{
	int del, cnt;
	scanf("%d", &T);
	while(T--)
	{
		for(int i = 0;i < maxn;i++)
		{
			sticks[i].invalid = false;
			sticks[i].squares = 0;
			sticks[i].sid.clear();
			rank[i] = i;
		}
		scanf("%d%d", &n, &m);
		while(m--){scanf("%d", &del);sticks[del].invalid = true;}
		cnt = 0;
		for(int sz = 1;sz <= n;sz++)
		for(int i = 1;i <= n - sz + 1;i++)
		for(int j = 1;j <= n - sz + 1;j++)
		{
			bool flag = true;
			for(int j2 = j;j2 < j + sz && flag;j2++)
				printf("%d ", row(i + sz, j2));
			// for(int i2 = i;i2 < i + sz && flag;i2++)
				// printf("%d ", col(i2, j));
			printf("\n");
			for(int i2 = i;i2 < i + sz && flag;i2++)
				if(sticks[col(i2, j)].invalid || sticks[col(i2, j + sz)].invalid) flag = false;
			for(int j2 = j;j2 < j + sz && flag;j2++)
				if(sticks[row(i, j2)].invalid || sticks[row(i + sz, j2)].invalid) flag = false;
			if(flag)
			{
				for(int i2 = i;i2 < i + sz;i2++)
					sticks[col(i2, j)].sid.insert(cnt), sticks[col(i2, j + sz)].squares++;
				for(int j2 = j;j2 < j + sz;j2++)
					sticks[row(i, j2)].sid.insert(cnt), sticks[row(i + sz, j2)].squares++;
				cnt++;
			}
		}
		sort(rank + 1, rank + maxn, cmp);
		// for(int maxd = 1;;maxd++)
			// if(dfs(0, maxd, cnt)) {printf("%d\n", maxd);break;}
		for(int d = 1;;d++)
		{
			cnt -= sticks[rank[1]].squares;
			for(set<int>::iterator iter = sticks[rank[1]].sid.begin();iter != sticks[rank[1]].sid.end();iter++)
			{
				// printf("%d ", *iter);
			for(int i = 1;i < maxn;i++)
				if(i != rank[1] && sticks[i].sid.count(*iter)) sticks[i].sid.erase(*iter), sticks[i].squares--;
			}
			sticks[rank[1]].squares = 0;
			// printf("\n");
			sort(rank + 1, rank + maxn, cmp);
			if(cnt == 0){printf("%d\n", d);break;}
		}
	}
	return 0;
}
