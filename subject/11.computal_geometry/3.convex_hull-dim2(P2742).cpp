#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const double EPS = 1e-10;
const int MAXN = 1e4 + 5;
struct Point
{
	double x, y;
	Point(double x = 0, double y = 0):x(x), y(y){}
}p[MAXN];
double dist(Point p1, Point p2)
{
	return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}
double cross(Point p1, Point p2)
{
	return p1.x * p2.y - p1.y * p2.x;
}
double cross(double x1, double y1, double x2, double y2)
{
	return x1 * y2 - y1 * x2;
}
double area(Point p1, Point p2, Point p3)
{
	Point v1 = Point(p2.x - p1.x, p2.y - p1.y);
	Point v2 = Point(p3.x - p2.x, p3.y - p2.y);
	return fabs(cross(v1, v2));
}
bool identical(double a, double b)
{
	return fabs(a - b) < EPS;
}
bool identical(Point p1, Point p2)
{
	return identical(p1.x, p2.x) && identical(p1.y, p2.y);
}
bool oneline(Point p1, Point p2)
{
	return identical(cross(p1, p2), 0);
}
bool cmp_angle(Point p1, Point p2)
{
	return (cross(p1, p2) > 0) || (oneline(p1, p2) && (p1.x > p2.x || p1.y > p2.y));
}
bool is_convex(Point p1, Point p2, Point p3)
{
	Point v1 = Point(p2.x - p1.x, p2.y - p1.y);
	Point v2 = Point(p3.x - p2.x, p3.y - p2.y);
	return cmp_angle(v1, v2);
}
int main()
{
	int n, minv = 0;
	scanf("%d", &n);
	double y_min = 1.0/EPS, x_min = 1.0/EPS;
	for(int i = 0;i < n;i++)
	{
		scanf("%lf%lf", &p[i].x, &p[i].y);
		if(p[i].y < y_min || (p[i].y == y_min && p[i].x < x_min))
			minv = i,
			y_min = p[i].y,
			x_min = p[i].x;
	}
	for(int i = 0;i < n;i++)
		p[i].x -= x_min,
		p[i].y -= y_min;
	swap(p[minv], p[0]);
	sort(p+1, p+n, cmp_angle);
	Point ps[MAXN]; //ps for point_stack
	int top = 0;
	ps[top++] = p[0];
	ps[top++] = p[1];
	for(int i = 2;i < n;i++)
	{
		if(oneline(ps[top-1], p[i])) continue;
		while(top && !is_convex(ps[top-2], ps[top-1], p[i]))
			top--;
		if(is_convex(ps[top-2], ps[top-1], p[i]))
			ps[top++] = p[i];
	}
	ps[top] = p[0];
	double ans = 0;
	while(top)
		ans += dist(ps[top], ps[top-1]),
		top--;
	printf("%.2lf", ans);
	return 0;
}
