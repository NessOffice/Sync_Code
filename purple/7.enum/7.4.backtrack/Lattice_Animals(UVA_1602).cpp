#include <cstdio>
#include <set>
using namespace std;
struct Cell{
	int x, y;
	Cell(int x = 0, int y = 0):x(x), y(y){}
	bool operator < (const Cell& cell2) const{return x < cell2.x || (x == cell2.x && y < cell2.y);}
};
typedef set<Cell> Polyomino;
#define FOR_CELL(c, p) for(Polyomino::const_iterator c = (p).begin(); c != (p).end(); c++)
const int maxn = 10 + 1;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
set<Polyomino> poly[maxn];
int ans[maxn][maxn][maxn];
int max(int a, int b){return a > b ? a : b;}
int min(int a, int b){return a < b ? a : b;}
Polyomino standardize(const Polyomino &p)
{
	int minX = maxn, minY = maxn;
	FOR_CELL(c, p)
	{
		if(c->x < minX) minX = c->x;
		if(c->y < minY) minY = c->y;
	}
	Polyomino p2;
	FOR_CELL(c, p)
		p2.insert(Cell(c->x - minX, c->y - minY));
	return p2;
}
Polyomino rotate(const Polyomino &p)
{
	Polyomino p2;
	FOR_CELL(c, p)
		p2.insert(Cell(c->y, -c->x));
	return standardize(p2);
}
Polyomino flip(const Polyomino &p)
{
	Polyomino p2;
	FOR_CELL(c, p)
		p2.insert(Cell(c->x, -c->y));
	return standardize(p2);
}
void try_to_insert(const Polyomino &p, Cell &c)
{
	Polyomino p2 = p;
	if(p2.count(c)) return;
	p2.insert(c);
	p2 = standardize(p2);
	int n = p2.size();
	for(int i = 0;i < 4;i++)
	{
		if(poly[n].count(p2)) return;
		p2 = rotate(p2);
	}
	p2 = flip(p2);
	for(int i = 0;i < 4;i++)
	{
		if(poly[n].count(p2)) return;
		p2 = rotate(p2);
	}
	poly[n].insert(p2);
}
void generate()
{
	Polyomino begin;
	begin.insert(Cell(0, 0));
	poly[1].insert(begin);
	for(int n = 2;n < maxn;n++)
	for(set<Polyomino>::iterator p = poly[n-1].begin();p != poly[n-1].end();p++)
	FOR_CELL(c, *p)
	for(int dir = 0;dir < 4;dir++)
	{
		Cell newc = Cell(c->x + dx[dir], c->y + dy[dir]);
		try_to_insert(*p, newc);
	}
	for(int n = 1;n < maxn;n++)
	for(int w = 1;w < maxn;w++)
	for(int h = 1;h < maxn;h++)
	{
		int cnt = 0;
		for(set<Polyomino>::iterator p = poly[n].begin();p != poly[n].end();p++)
		{
			int maxX = 0, maxY = 0;
			FOR_CELL(c, *p)
			{
				maxX = max(maxX, c->x);
				maxY = max(maxY, c->y);
			}
			if(min(maxX, maxY) < min(w, h) && max(maxX, maxY) < max(w, h)) cnt++;
		}
		ans[n][w][h] = cnt;
	}
}
int main()
{
	// freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	generate();
	int n, w, h;
	while(scanf("%d%d%d", &n, &w, &h) == 3)
		printf("%d\n", ans[n][w][h]);
	return 0;
}
