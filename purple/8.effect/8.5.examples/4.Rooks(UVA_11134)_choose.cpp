#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 5000 + 10;
struct Interval{
	int index, L, R;
}rect[2][maxn];
int pos[2][maxn], n;
bool solve(int type)
{
	for(int i = 1;i <= n;i++)
	{
		int rook = i;
		for(int j = i;j <= n;j++)
		{
			if(rect[type][j].L < rect[type][rook].L) rook = j;
			if(rect[type][j].L == rect[type][rook].L
			&& rect[type][j].R < rect[type][rook].R) rook = j;
		}
		if(rect[type][rook].L == i)
			pos[type][rect[type][rook].index] = i;
		else return true;
		if(i != rook) swap(rect[type][i], rect[type][rook]);
		for(int j = i+1;j <= n;j++)
			if(rect[type][j].L <= i && rect[type][j].R > i) rect[type][j].L = i+1;
	}
	return false;
}
int main()
{
//	 freopen("in.txt", "r", stdin);
//	 freopen("out.txt", "w", stdout);
	while(scanf("%d", &n) && n)
	{
		for(int i = 1;i <= n;i++)
			scanf("%d%d%d%d", &rect[0][i].L, &rect[1][i].L, &rect[0][i].R, &rect[1][i].R),
			rect[0][i].index = rect[1][i].index = i;
		if(solve(0) || solve(1)) printf("IMPOSSIBLE\n");
		else for(int i = 1;i <= n;i++)
			printf("%d %d\n", pos[0][i], pos[1][i]);
	}
	return 0;
}
