//Accept 20ms
//但网上大多数人都是0ms，故此题的解法或一些细节值得关注
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 10 + 2;
const int maxp = 6 + 1;
const int dr[] = {0, 1, 0, -1, 0};
const int dc[] = {0, 0, 1, 0, -1};
int row, col, r1, c1;
int room[maxn][maxn], face2[maxp][maxp];
struct Node{
	int r, c, up, front;
	Node(int r = 0, int c = 0, int up = 0, int front = 0):r(r), c(c), up(up), front(front){}
};
int vis[maxn][maxn][maxp][maxp];
Node parent[maxn][maxn][maxp][maxp];
bool valid(Node u)
{
	return u.r > 0 && u.r <= row && u.c > 0 && u.c <= col;
}
void turn(int dir, int face[])
{
	if(dir > 2) dir++;
	int temp, step1 = dir, step2 = (dir + 3) % 6;
	temp = face[0], face[0] = face[step2], face[step2] = face[3], face[3] = face[step1], face[step1] = temp;
}
void printAns(Node u)
{
	vector<Node> nodes;
	while(1)
	{
		nodes.push_back(u);
		if(vis[u.r][u.c][u.up][u.front] == 0) break;
		vis[u.r][u.c][u.up][u.front] = 0;
		u = parent[u.r][u.c][u.up][u.front];
	}
	int cnt = 0;
	for(int i = nodes.size() - 1;i >= 0;i--)
	{
		if(cnt % 9 == 0) printf("  ");
		printf("(%d,%d)", nodes[i].r, nodes[i].c);
		if(i) printf(",");
		if(++cnt % 9 == 0) printf("\n");
	}
	if(nodes.size() % 9 != 0) printf("\n");
}
void mazeBFS(Node start)
{
	queue<Node> q;
	q.push(start);
	int first = 0;
	while(!q.empty())
	{
		Node u = q.front();q.pop();
		if(u.r == r1 && u.c == c1 && first++){printAns(u);return;}
		for(int dir = 1;dir <= 4;dir++)
		{
			Node v = Node(u.r + dr[dir], u.c + dc[dir], 0, 0);
			if(!valid(v)) continue;
			int face[maxp];
			face[0] = u.up, face[1] = u.front;
			face[2] = face2[face[0]][face[1]];
			for(int i = 3;i < 6;i++) face[i] = 7 - face[i - 3];
			if(room[v.r][v.c] != -1 && room[v.r][v.c] != face[0]) continue;
			turn(dir, face);
			v.up = face[0], v.front = face[1];
			if(vis[v.r][v.c][v.up][v.front]) continue;
			parent[v.r][v.c][v.up][v.front] = u;
			vis[v.r][v.c][v.up][v.front] = 1;
			q.push(v);
		}
	}
	printf("  No Solution Possible\n");
}
void init()
{
	face2[1][2] = 4; face2[1][3] = 2; face2[1][4] = 5; face2[1][5] = 3;
    face2[2][1] = 3; face2[2][3] = 6; face2[2][4] = 1; face2[2][6] = 4;
    face2[3][1] = 5; face2[3][2] = 1; face2[3][5] = 6; face2[3][6] = 2;
    face2[4][1] = 2; face2[4][2] = 6; face2[4][5] = 1; face2[4][6] = 5;
    face2[5][1] = 4; face2[5][3] = 1; face2[5][4] = 6; face2[5][6] = 3;
    face2[6][2] = 3; face2[6][3] = 5; face2[6][4] = 2; face2[6][5] = 4;
	for(int i = 1;i <= 6;i++)
	for(int j = 1;j <= 6;j++)
	{
		if(i == j || i + j == 7) continue;
		face2[i][j] = 7 - face2[i][j];
	}
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int up, front;
	char name[24];
	init();
	while(~scanf("%s", name) && strcmp(name, "END"))
	{
		memset(parent, 0, sizeof(parent));
		memset(room, 0, sizeof(room));
		memset(vis, 0, sizeof(vis));
		scanf("%d%d%d%d%d%d", &row, &col, &r1, &c1, &up, &front);
		for(int i = 1;i <= row;i++)
		for(int j = 1;j <= col;j++)
			scanf("%d", &room[i][j]);
		printf("%s\n", name);
		Node start = Node(r1, c1, up, front);
		mazeBFS(start);
	}
	return 0;
}
