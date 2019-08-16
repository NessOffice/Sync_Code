#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 310;
int ans, n, m, ptr[maxn], prefer[maxn][maxn], fav[maxn], mark_drop[maxn];
int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		ans = maxn;
		memset(ptr, 0, sizeof(ptr));
		memset(mark_drop, 0, sizeof(mark_drop));
		scanf("%d%d", &n, &m);
		for(int i = 0;i < n;i++)
			for(int j = 0;j < m;j++)
				scanf("%d", &prefer[i][j]);
		for(int j = 1;j <= m;j++)
		{
			int fav_max = 0;
			memset(fav, 0, sizeof(fav));
			for(int i = 0;i < n;i++)
				fav[prefer[i][ptr[i]]]++;
			for(int j2 = 1;j2 <= m;j2++)
				if(fav[j2] > fav[fav_max])
					fav_max = j2;
			ans = min(ans, fav[fav_max]);
			mark_drop[fav_max] = 1;
			for(int i = 0;i < n;i++)
				while(mark_drop[prefer[i][ptr[i]]])
					ptr[i]++;
		}
		printf("%d\n", ans);
	}
	return 0;
}
