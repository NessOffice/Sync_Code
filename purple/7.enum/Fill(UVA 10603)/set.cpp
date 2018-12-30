#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

set<int> vis;
void init_table(){vis.clear();}
bool try_to_insert(int u)
{
	int v = 0;
	for(int i = 0;i < 9;i++) v = 10 * v + states[u][i];
	if(vis.count(v)) return false;
	vis.insert(v);
	return true;
}

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
int solve()
{
	init_table();
	dist[0] = 0;
	int head = 0, tail = 1;
	while(head < tail)
	{
		State& st0 = states[head];
		if(memcmp(goal, st0, sizeof(st0)) == 0) return dist[head];
		int x = blank[head] % 3, y = blank[head] / 3;
		for(int dir = 0;dir < 4;dir++)
		{
			int newx = x + dx[dir], newy = y + dy[dir];
			blank[tail] = newx + newy * 3;
			if(newx < 0 || newx >= 3 || newy < 0 || newy >= 3) continue;
			State& st1 = states[tail];
			memcpy(&st1, &st0, sizeof(st0));
			st1[blank[tail]] = st0[blank[head]];
			st1[blank[head]] = st0[blank[tail]];
			dist[tail] = dist[head] + 1;
			if(try_to_insert(tail)) tail++;
		}
		head++;
	}
	return -1;
}
int main()
{
	// freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	for(int i = 0;i < 9;i++)
	{
		scanf("%d", &states[0][i]);
		if(states[0][i] == 0) blank[0] = i;
	}
	for(int i = 0;i < 9;i++)
		scanf("%d", &goal[i]);
	printf("%d\n", solve());
	return 0;
}
