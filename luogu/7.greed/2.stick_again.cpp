#include <cstdio>
#include <cstring>
#include <algorithm>
struct Stick{int L, W;}sticks[5050];
bool cmp(const Stick& lhs, const Stick& rhs){return lhs.L < rhs.L || (lhs.L == rhs.L && lhs.W <= rhs.W);}//caution
int main()
{
	freopen("in.txt", "r", stdin);
	int n, ans = 0, links[5050];
	scanf("%d", &n);
	for(int i = 0;i < n;i++)
		scanf("%d%d", &sticks[i].L, &sticks[i].W);
	std::sort(sticks, sticks+n, cmp);
	links[++ans] = 0;
	for(int i = 1;i < n;i++)
	{
		int W = sticks[i].W;
		if(W < sticks[links[ans]].W)
			links[++ans] = i;
		else{
			int l = 1, r = ans;
			while(r > l)
			{
				int m = (l+r)/2;
				if(W >= sticks[links[m]].W) r = m;
				else l = m+1;
			}
			links[l] = i;
		}
	}
	printf("%d", ans);
	return 0;
}
