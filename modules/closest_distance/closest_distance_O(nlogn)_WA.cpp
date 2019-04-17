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
struct Point{double x, y;}Points_x[maxn], Points_y[maxn], temp[maxn];
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
	double mid_x = Points_x[mid].x;
	for(int i = low;i <= high;i++)
		if(Points_y[i].x >= mid_x - d)
		if(Points_y[i].x <= mid_x + d)
			temp[len++] = Points_y[i];
//	for(int i = mid;i >= low && (Points_y[i].x >= mid_x - d);i--)
//		temp[len++] = Points_y[i];
//	for(int i = mid+1;i <= high && (Points_y[i].x <= mid_x + d);i++)
//		temp[len++] = Points_y[i];
	for(int i = 0;i < len;i++)
		for(int j = 1;j <= near && i + j < len;j++)
		{
			if(temp[i+j].y - temp[i].y >= d) break;
			d = min(d, dist(temp[i], temp[i+j]));
		}
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
//	 freopen("debug_closest_input.txt", "r", stdin);
//	 freopen("debug_closest_nlogn.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for(int i = 1;i <= n;i++)
			scanf("%lf %lf", &Points_x[i].x, &Points_x[i].y);
		memcpy(Points_y, Points_x, sizeof(Points_x));
		sort(Points_x + 1, Points_x + n + 1, cmp_x);
		sort(Points_y + 1, Points_y + n + 1, cmp_y);
//	 for(int i = 1;i <= n;i++);
//	 	printf("%lf %lf %lf %lf\n", Points_x[i].x, Points_x[i].y, Points_y[i].x, Points_y[i].y);
		printf("%.4lf\n", closest(1, n));
	}
	return 0;
}
