#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 50 + 2;
const int maxc = 1000 + 1;
int x0[maxn], y0[maxn], z0[maxn];
int x1[maxn], y1[maxn], z1[maxn];
int dis_x[2*maxn], dis_y[2*maxn], dis_z[2*maxn];
int nx, ny, nz;
int color[2*maxn][2*maxn][2*maxn];
const int dx[] = {1, -1, 0, 0, 0, 0};
const int dy[] = {0, 0, 1, -1, 0, 0};
const int dz[] = {0, 0, 0, 0, 1, -1};
struct Cell
{
	int px, py, pz;
	Cell(int px = 0, int py = 0, int pz = 0):px(px), py(py), pz(pz){}
	Cell neighbor(int dir){return Cell(px + dx[dir], py + dy[dir], pz + dz[dir]);}
	bool outside()
	{
		if(px < 0 || px >= nx - 1) return true;
		if(py < 0 || py >= ny - 1) return true;
		if(pz < 0 || pz >= nz - 1) return true;
		return false;
	}
	int area(int dir)
	{
		if(dx[dir]) return (dis_y[py+1]-dis_y[py])*(dis_z[pz+1]-dis_z[pz]);
		if(dy[dir]) return (dis_x[px+1]-dis_x[px])*(dis_z[pz+1]-dis_z[pz]);
		if(dz[dir]) return (dis_x[px+1]-dis_x[px])*(dis_y[py+1]-dis_y[py]);
	}
	int volumn(){return (dis_x[px+1]-dis_x[px])*(dis_y[py+1]-dis_y[py])*(dis_z[pz+1]-dis_z[pz]);}
};
void FloodFill(int& v, int& s)
{
	queue<Cell> cellQueue;
	Cell begin = Cell();
	color[begin.px][begin.py][begin.pz] = 2;
	cellQueue.push(begin);
	while(!cellQueue.empty())
	{
		Cell c0 = cellQueue.front();cellQueue.pop();
		v += c0.volumn();
		for(int i = 0;i < 6;i++)
		{
			Cell c1 = c0.neighbor(i);
			if(c1.outside()) continue;
			int status = color[c1.px][c1.py][c1.pz];
			switch(status)
			{
				case 0:color[c1.px][c1.py][c1.pz] = 2;cellQueue.push(c1);break;
				case 1:s += c0.area(i);break;
				case 2:break;
			}
		}
	}
	v = maxc*maxc*maxc - v;
}
void discretize(int* dis, int& n)
{
	sort(dis, dis + n);
	n = unique(dis, dis + n) - dis;
}
int findPos(int* dis, int n, int find)
{
	return lower_bound(dis, dis + n, find) - dis;
}
int main()
{
	freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	int T, n;
	scanf("%d", &T);
	while(T--)
	{
		nx = ny = nz = 2;
		dis_x[0] = dis_y[0] = dis_z[0] = 0;
		dis_x[1] = dis_y[1] = dis_z[1] = maxc;
		
		scanf("%d", &n);
		for(int i = 0;i < n;i++)
		{
			scanf("%d%d%d%d%d%d", &x0[i], &y0[i], &z0[i], &x1[i], &y1[i], &z1[i]);
			x1[i] += x0[i], y1[i] += y0[i], z1[i] += z0[i];
			dis_x[nx++] = x0[i]; dis_x[nx++] = x1[i];
			dis_y[ny++] = y0[i]; dis_y[ny++] = y1[i];
			dis_z[nz++] = z0[i]; dis_z[nz++] = z1[i];
		}
		discretize(dis_x, nx);
		discretize(dis_y, ny);
		discretize(dis_z, nz);

		memset(color, 0, sizeof(color));
		for(int i = 0;i < n;i++)
		{
			int posX0 = findPos(dis_x, nx, x0[i]), posX1 = findPos(dis_x, nx, x1[i]);
			int posY0 = findPos(dis_y, ny, y0[i]), posY1 = findPos(dis_y, ny, y1[i]);
			int posZ0 = findPos(dis_z, nz, z0[i]), posZ1 = findPos(dis_z, nz, z1[i]);
			for(int posX = posX0;posX < posX1;posX++)
			for(int posY = posY0;posY < posY1;posY++)
			for(int posZ = posZ0;posZ < posZ1;posZ++)
				color[posX][posY][posZ] = 1;
		}
		int v = 0, s = 0;
		FloodFill(v, s);
		printf("%d %d\n", s, v);
	}
	return 0;
}
