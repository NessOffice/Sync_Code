#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 5000 + 10;
struct Interval{
	int index, L, R;
	bool occupy;
}rect[2][maxn];
int pos[2][maxn], n;
bool cmp_pos(Interval a, Interval b){return a.R < b.R;}
bool solve(int type)
{
	sort(rect[type]+1, rect[type]+n+1, cmp_pos);
	for(int i = 1;i <= n;i++)
	{
		int rook = 1;
		for(;rook <= n;rook++)
		if(!rect[type][rook].occupy)
		if(rect[type][rook].L <= i)
		if(rect[type][rook].R >= i)
		{
			rect[type][rook].occupy = true;
			pos[type][rect[type][rook].index] = i;
			break;
		}
		if(rook > n) return true;
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
			rect[0][i].occupy = rect[1][i].occupy = false,
			rect[0][i].index = rect[1][i].index = i;
		if(solve(0) || solve(1)) printf("IMPOSSIBLE\n");
		else for(int i = 1;i <= n;i++)
			printf("%d %d\n", pos[0][i], pos[1][i]);
	}
	return 0;
}
