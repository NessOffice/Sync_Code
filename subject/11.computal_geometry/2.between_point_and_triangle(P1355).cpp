#include <cstdio>
#include <cmath>
#include <algorithm>
const double EPS = 1e-10;
struct Point{double x, y;}tri[5], point;
double cross(Point p1, Point p2)
{
	return p1.x * p2.y - p1.y * p2.x;
}
double cross(double x1, double y1, double x2, double y2)
{
	return x1 * y2 - y1 * x2;
}
double get_square(Point p1, Point p2, Point p3)
{
	double dx1 = p1.x - p2.x;
	double dy1 = p1.y - p2.y;
	double dx2 = p1.x - p3.x;
	double dy2 = p1.y - p3.y;
	return fabs(cross(dx1, dy1, dx2, dy2));
}
bool identical(Point p1, Point p2)
{
	return (fabs(p1.x - p2.x) < EPS) && (fabs(p1.y - p2.y) < EPS);
}
bool identical(double a, double b)
{
	return fabs(a - b) < EPS;
}
int solve()
{
	for(int i = 0;i < 3;i++)
		if(identical(tri[i], point))
			return 4; // at the vertex of the triangle
	
	double S[5];//s[0] for S of the tri
	S[0] = get_square(tri[0], tri[1], tri[2]);
	S[1] = get_square(point, tri[0], tri[1]);
	S[2] = get_square(point, tri[0], tri[2]);
	S[3] = get_square(point, tri[1], tri[2]);
	if(!identical(S[1] + S[2] + S[3], S[0]))
		return 2; // outside the given triangle

	for(int i = 1;i <= 3;i++)
		if(identical(S[i], 0))
			return 3; // 3: at the border of the triangle

	return 1; // 1: inside the given triangle
}
int main()
{
	for(int i = 0;i < 3;i++)
		scanf("(%lf,%lf)\n", &tri[i].x, &tri[i].y);
	tri[3] = tri[0];
	scanf("(%lf,%lf)", &point.x, &point.y);
	printf("%d", solve());
	return 0;
}
