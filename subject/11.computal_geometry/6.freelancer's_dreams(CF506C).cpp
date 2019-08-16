#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const double EPS = 1e-10;
const double INF = 1e20;
const int MAXN = 1e5 + 5;
struct Point
{
	double x, y;
	Point(double x = 0, double y = 0):x(x), y(y){}
}p[MAXN];
Point hull[MAXN];
int top = 0, n, coord_x, coord_y;
double dist(Point p1, Point p2){return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));}
double cross(Point p1, Point p2){return p1.x * p2.y - p1.y * p2.x;}
double cross(double x1, double y1, double x2, double y2){return x1 * y2 - y1 * x2;}
double area(Point p1, Point p2, Point p3){return fabs(cross(Point(p2.x-p1.x, p2.y-p1.y), Point(p3.x-p2.x, p3.y-p2.y)));}
bool eq(double a, double b){return fabs(a - b) < EPS;}
bool eq(Point p1, Point p2){return eq(p1.x, p2.x) && eq(p1.y, p2.y);}
bool geq(double a, double b){return a > b || eq(a, b);}
bool oneline(Point p1, Point p2){return eq(cross(p1, p2), 0);}
bool cmp_angle(Point p1, Point p2){return (cross(p1, p2) > 0) || (oneline(p1, p2) && (p1.x > p2.x || p1.y > p2.y));}
bool is_convex(Point p1, Point p2, Point p3){return cmp_angle(Point(p2.x-p1.x, p2.y-p1.y), Point(p3.x-p2.x, p3.y-p2.y));}
Point calc_intersection(Point p1, Point p2, Point p3, Point p4) // p1: (0, 0)
{
	double k1 = p2.y / p2.x;
	if(eq(p3.x, p4.x)) return Point(p3.x, k1*p3.x);
	double k2 = (p4.y - p3.y) / (p4.x - p3.x);
	double b = p3.y - k2*p3.x;
	if(eq(k1, k2)) return Point(2*p4.x-p3.x, 2*p4.y-p3.y); // a point that isn't between p3 and p4
	return Point(b/(k1-k2), k1*b/(k1-k2));
}
double x_min, y_min, x_max, y_max;
void graham()
{
	y_min = 0, x_min = 0;
	x_max = -INF, y_max = -INF;
	for(int i = 0;i < n;i++)
	{
		scanf("%lf%lf", &p[i].x, &p[i].y);
		y_max = max(y_max, p[i].y);
		x_max = max(x_max, p[i].x);
	}
	y_min = y_max;
	for(int i = 0;i < n;i++)
		p[i].x -= x_min,
		p[i].y -= y_min;
	y_max -= y_min;
	x_max -= x_min;
	p[n++] = Point(x_max, -y_min);
	p[n++] = Point(-x_min, y_max);
	swap(p[n-1], p[0]); // the point that is the most left: p[n-1]
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
		hull[i].x += x_min,
		hull[i].y += y_min;
	y_max += y_min;
	x_max += x_min;
	hull[top++] = hull[0];
}
bool in_section(Point p1, Point p2, Point p3)
{
	if(eq(p1, p2) || eq(p1, p3)) return true;
	if(geq(0, (p1.x-p2.x)*(p1.x-p3.x)) && geq(0, (p1.y-p2.y)*(p1.y-p3.y))) return true;
	return false;
}
bool exclude_special_case(Point p1, Point p2)
{
	if(eq(p1, Point(x_max, 0)) && eq(p2, Point(0, y_max))) return true;
	if(eq(p2, Point(x_max, 0)) && eq(p1, Point(0, y_max))) return true;
	return false;
}
void find_intersection()
{
	int len = 0;
	double ans = INF;
	Point origin = Point(0, 0), target = Point(coord_x, coord_y);
	for(int i = 0;i < top-1;i++)
	{
		Point point_in_hull1 = hull[i], point_in_hull2 = hull[i+1];
		if(exclude_special_case(point_in_hull1, point_in_hull2)) continue;
		Point current_intersection = calc_intersection(origin, target, point_in_hull1, point_in_hull2);
		if(in_section(current_intersection, point_in_hull1, point_in_hull2))
			ans = min(ans, min(coord_x / current_intersection.x, coord_y / current_intersection.y)); // caution
	}
	printf("%lf", ans);
}
int main()
{
	scanf("%d%d%d", &n, &coord_x, &coord_y);
	graham();
	find_intersection();
	return 0;
}
