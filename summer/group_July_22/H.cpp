#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL maxn = 5e5 + 5;
LL ans[maxn];
struct Point{LL x, y, id;}track[maxn], rifle[maxn], rifle_uiq[maxn], hull[maxn];
bool cmp_by_theta(const Point& lhs, const Point& rhs){return (lhs.x * rhs.y) > (rhs.x * lhs.y);}
bool cmp_by_xy(const Point& lhs, const Point& rhs){return lhs.x < rhs.x || (lhs.x == rhs.x && lhs.y < rhs.y);}
int main()
{
	LL n, m, m_uiq = 0, top = 0;
	scanf("%lld", &n);
	for(LL i = 0;i < n;i++) scanf("%lld%lld", &track[i].x, &track[i].y), track[i].id = i+1;
	sort(track, track + n, cmp_by_theta);
	scanf("%lld", &m);
	for(LL i = 0;i < m;i++) scanf("%lld%lld", &rifle[i].x, &rifle[i].y);
	sort(rifle, rifle + m, cmp_by_xy);
	rifle_uiq[m_uiq++] = rifle[0];
	for(LL i = 1;i < m;i++)
	{
		if(rifle[i].x == rifle_uiq[m_uiq-1].x) continue;
		if(rifle[i].y >= rifle_uiq[m_uiq-1].y) continue;
		rifle_uiq[m_uiq++] = rifle[i];
	}
	hull[top++] = rifle_uiq[0];
	if(m_uiq > 1)
	{
		hull[top++] = rifle_uiq[1];
		for(LL i = 2;i < m_uiq;i++)
		{
			while(top>1 && (hull[top-2].y-rifle_uiq[i].y)*(rifle_uiq[i].x-hull[top-1].x) > (hull[top-1].y-rifle_uiq[i].y)*(rifle_uiq[i].x-hull[top-2].x)) top--;
			hull[top++] = rifle_uiq[i];
		}
	}
	LL ptr = 0;
	for(LL i = 0;i < n;i++)
	{
		while(ptr+1 < top && (track[i].x*(hull[ptr].x-hull[ptr+1].x)+track[i].y*(hull[ptr].y-hull[ptr+1].y) > 0)) ptr++;
		ans[track[i].id] = (track[i].x*hull[ptr].x)+(track[i].y*hull[ptr].y);
	}
	for(LL i = 1;i <= n;i++) printf("%lld ", ans[i]);
	return 0;
}
