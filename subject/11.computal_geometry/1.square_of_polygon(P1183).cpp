#include <cstdio>
#include <algorithm>
struct Point{
	double x, y;
}points[150];
double cross(Point p1, Point p2)
{
	return p1.x * p2.y - p1.y * p2.x;
}
bool cmp(Point lhs, Point rhs)
{
	return cross(lhs, rhs) > 0;
}
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0;i < n;i++)
		scanf("%lf%lf", &points[i].x, &points[i].y);
	// std::sort(points, points + n, cmp);
	points[n] = points[0];
	double ans = 0;
	for(int i = 0;i < n;i++)
		ans += cross(points[i], points[i+1]);
	printf("%d", int(ans/2 + 0.5));
	return 0;
}
