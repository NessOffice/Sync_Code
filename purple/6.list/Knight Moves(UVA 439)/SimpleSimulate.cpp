#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 8 + 2;
const int dx[] = {2, 2, -2, -2, 1, -1, 1, -1};
const int dy[] = {1, -1, 1, -1, 2, 2, -2, -2};
int d[maxn][maxn], ans, startX, startY, endX, endY;
bool invalid(int x, int y)
{
	if(x < 1 || x > 8) return true;
	if(y < 1 || y > 8) return true;
	return false;
}
void moveBFS()
{
	memset(d, -1, sizeof(d));
	d[startX][startY] = 0;
	queue<pair<int, int> > q;
	q.push(make_pair(startX, startY));
	int quit = 1;
	while(quit)
	{
		int X = q.front().first, Y = q.front().second;q.pop();
		if(X == endX && Y == endY){quit = 0;ans = d[X][Y];}
		for(int dir = 0;dir < 8 && quit;dir++)
		{
			int X1 = X + dx[dir], Y1 = Y + dy[dir];
			if(invalid(X1, Y1) || d[X1][Y1] != -1) continue;
			d[X1][Y1] = d[X][Y] + 1;
			q.push(make_pair(X1, Y1)); 
		}
	}
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	char pos[2][4];
	while(scanf("%s", pos[0]) == 1)
	{
		scanf("%s", pos[1]);
		startX = pos[0][0] - 'a' + 1, startY = pos[0][1] - '0';
		endX = pos[1][0] - 'a' + 1, endY = pos[1][1] - '0';
		moveBFS();
		printf("To get from %s to %s takes %d knight moves.\n", pos[0], pos[1], ans);
	}
	return 0;
}
