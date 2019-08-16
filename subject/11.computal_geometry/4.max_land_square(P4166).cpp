#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const double EPS = 1e-10;
const double INF = 1e20;
const int MAXN = 2e3 + 5;
struct Point
{
	double x, y;
	Point(double x = 0, double y = 0):x(x), y(y){}
}p[MAXN];
Point hull[MAXN];
int top = 0;
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
bool geq(double a, double b)
{
	return a > b || identical(a, b);
}
void graham()
{
	int n, minv = 0;
	scanf("%d", &n);
	double y_min = INF, x_min = INF;
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
	hull[top++] = p[0];
	hull[top++] = p[1];
	for(int i = 2;i < n;i++)
	{
		if(oneline(hull[top-1], p[i])) continue;
		while(top && !is_convex(hull[top-2], hull[top-1], p[i]))
			top--;
		if(is_convex(hull[top-2], hull[top-1], p[i]))
			hull[top++] = p[i];
	}
	for(int i = 0;i < top;i++)
		hull[top+i] = hull[i]; // to avoid mod
}
void rotate_caliper()
{
	double ans = 0;
	for(int i = 0;i < top;i++)
	{
		int a = i + 1;
		int b = i + 3;
		for(int j = i + 2;j < top;j++)
		{
			while((a+1 < j) && geq(area(hull[i], hull[j], hull[a+1]), area(hull[i], hull[j], hull[a]))) a++;
			while((b+1 < (i+top)) && geq(area(hull[i], hull[j], hull[b+1]), area(hull[i], hull[j], hull[b]))) b++;
			ans = max(ans, area(hull[i], hull[j], hull[a]) + area(hull[i], hull[j], hull[b]));
		}
	}
	printf("%.3lf", ans / 2);
}
int main()
{
	graham();
	rotate_caliper();
	return 0;
}
