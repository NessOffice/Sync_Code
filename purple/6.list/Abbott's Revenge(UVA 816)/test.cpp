#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
using namespace std;
const char* dirs = "NESW";
const char* turns = "FLR";
int dirId(char ch){return strchr(dirs, ch) - dirs;}
int turnId(char ch){return strchr(turns, ch) - turns;}
bool walkable[10][10][4][4];
int r1, c1, r2, c2, dir, d[10][10][4];
struct Node{
	int r, c, dir;
	Node(int _r = 0, int _c = 0, int _dir = 0):r(_r), c(_c), dir(_dir){}
};
Node parent[10][10][4];
void walk(Node& u, int turn)
{
	if(turn == 1) u.dir = (u.dir + 3) % 4; 
	if(turn == 2) u.dir = (u.dir + 1) % 4;
	switch(u.dir)
	{
		case 0:u.r--;break;
		case 1:u.c++;break;
		case 2:u.r++;break;
		case 3:u.c--;break;
	}
}
void printAns(Node u)
{
	vector<Node> nodes;
	while(1)
	{
		nodes.push_back(u);
		if(d[u.r][u.c][u.dir] == 0) break;
		u = parent[u.r][u.c][u.dir];
	}
	nodes.push_back(Node(r1, c1, dir));
	int cnt = 0;
	for(int i = nodes.size() - 1;i >= 0;i--)
	{
		if(cnt % 10 == 0) cout<<" ";
		cout<<" ("<<nodes[i].r<<","<<nodes[i].c<<")";
		if(++cnt % 10 == 0) cout<<endl;
	}
	if(nodes.size() % 10 != 0) cout<<endl;
}
void mazeBFS()
{
	queue<Node> q;
	Node start = Node(r1, c1, dir);
	walk(start, 0);
	d[start.r][start.c][start.dir] = 0;
	parent[start.r][start.c][start.dir] = Node(r1, c1, dir);
	q.push(start);
	while(!q.empty())
	{
		Node u = q.front();q.pop();
		if(u.r == r2 && u.c == c2){printAns(u);return;}
		for(int i = 0;i < 3;i++)
		{
			if(walkable[u.r][u.c][u.dir][i])
			{
				Node v = u;
				walk(v, i);
				if(d[v.r][v.c][v.dir] != -1) continue;
				d[v.r][v.c][v.dir] = d[u.r][u.c][u.dir] + 1;
				parent[v.r][v.c][v.dir] = u;
				q.push(v);
			}
		}
	}
	cout<<"  No Solution Possible\n";
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	string name, turn;
	while(cin>>name)
	{
		if(name == "END") break;
		memset(walkable, 0, sizeof(walkable));
		memset(d, -1, sizeof(d));
		memset(parent, 0, sizeof(parent));
		char dir0;
		cin>>r1>>c1>>dir0>>r2>>c2;
		dir = dirId(dir0);
		int r, c;
		while(cin>>r && r)
		{
			cin>>c;
			while(cin>>turn && turn[0] != '*')
			{
				int dir1 = dirId(turn[0]);
				for(int i = turn.length() - 1;i > 0;i--)
				{
					int turn0 = turnId(turn[i]);
					walkable[r][c][dir1][turn0] = 1;
				}
			}
		}
		cout<<name<<endl;
		mazeBFS();
	}
	return 0;
}
