#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 8 + 2;
const int dx[] = {2, 2, -2, -2, 1, -1, 1, -1};
const int dy[] = {1, -1, 1, -1, 2, 2, -2, -2};
int ans[maxn][maxn][maxn][maxn];
bool invalid(int x, int y)
{
	if(x < 1 || x > 8) return true;
	if(y < 1 || y > 8) return true;
	return false;
}
void moveBFS()
{
	for(int startX = 1;startX <= 8;startX++)
		for(int startY = 1;startY <= 8;startY++)
		{
			memset(ans[startX][startY], -1, sizeof(ans[startX][startY]));
			ans[startX][startY][startX][startY] = 0;
			queue<pair<int, int> > q;
			q.push(make_pair(startX, startY));
			int num = 1;
			while(num < 64)
			{
				int X = q.front().first, Y = q.front().second;q.pop();
				for(int dir = 0;dir < 8 && num<64;dir++)
				{
					int X1 = X + dx[dir], Y1 = Y + dy[dir];
					if(invalid(X1, Y1) || ans[startX][startY][X1][Y1] != -1) continue;
					ans[startX][startY][X1][Y1] = ans[startX][startY][X][Y] + 1;
					num++;
					q.push(make_pair(X1, Y1)); 
				}
			}
		}
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	//什么情况？打表慢成这样？ 
	char pos[2][4];
	int startX, startY, endX, endY;
	while(scanf("%s", pos[0]) == 1)
	{
		scanf("%s", pos[1]);
		startX = pos[0][0] - 'a' + 1, startY = pos[0][1] - '0';
		endX = pos[1][0] - 'a' + 1, endY = pos[1][1] - '0';
		moveBFS();
		printf("To get from %s to %s takes %d knight moves.\n", pos[0], pos[1], ans[startX][startY][endX][endY]);
	}
	return 0;
}
