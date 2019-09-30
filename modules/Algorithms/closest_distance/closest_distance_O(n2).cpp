#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const double eps = 1e-10;
const double INF = 1e100;
const int maxn = 2e5 + 7;
const int near = 8;
int n;
struct Point{double x, y;}Points_x[maxn], Points_y[maxn];
bool identical(double &lhs, double &rhs)
{
	return fabs(lhs - rhs) < eps;
}
bool cmp_x(Point &lhs, Point &rhs)
{
	return lhs.x < rhs.x;
}
bool cmp_y(Point &lhs, Point &rhs)
{
	return lhs.y < rhs.y;
}
double dist(Point &lhs, Point &rhs)
{
	return sqrt((lhs.x - rhs.x)*(lhs.x - rhs.x) + (lhs.y - rhs.y)*(lhs.y - rhs.y));
}
double merge(int low, int mid, int high, double d)
{
	int len = 0;
	Point temp[n + 5];
	for(int i = 1;i <= n;i++)
	{
		double &temp_x = Points_y[i].x;
		double &mid_x = Points_x[i].x;
		if(temp_x >= mid_x - d && temp_x <= mid_x + d)
			temp[len++] = Points_y[i];
	}
	for(int i = 0;i < len;i++)
		for(int j = 1;j <= near && i + j < len;j++)
			d = min(d, dist(temp[i], temp[i+j]));
	return d;
}
double closest(int low, int high)
{
	if(high == low) return INF;
	if(high - low == 1) return dist(Points_x[low], Points_x[low+1]);
	if(high - low == 2)
	{
		double d1 = dist(Points_x[low], Points_x[low+1]);
		double d2 = dist(Points_x[low], Points_x[low+2]);
		double d3 = dist(Points_x[low+1], Points_x[low+2]);
		if(d1 > d2) swap(d1, d2);
		if(d2 > d3) swap(d2, d3);
		if(d1 > d2) swap(d1, d2);
		return d1;
	}
	int mid = (low + high) / 2;
	double d1 = closest(low, mid);
	double d2 = closest(mid + 1, high);
	double d = min(d1, d2);
	return merge(low, mid, high, d);
}
int main()
{
	freopen("debug_closest_input.txt", "r", stdin);
	freopen("debug_closest_n2.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for(int i = 1;i <= n;i++)
			scanf("%lf %lf", &Points_x[i].x, &Points_x[i].y);
		int x, y;
		double d = INF;
		for(int i = 1;i <= n;i++)
			for(int j = i+1;j <= n;j++)
			{
				if(dist(Points_x[i], Points_x[j]) < d)
				{
					d = dist(Points_x[i], Points_x[j]);
					x = i, y = j;
				}
			}
//		printf("%.4lf %d %d\n", d, x, y);
		printf("%.4lf\n", d);
	}
	// for(int i = 1;i <= n;i++)
	// 	printf("%lf %lf %lf %lf\n", Points_x[i].x, Points_x[i].y, Points_y[i].x, Points_y[i].y);
	return 0;
}
