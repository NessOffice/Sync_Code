//为何哈希比set要快这么多？
#include <cstdio>
#include <cstring>
using namespace std;

typedef int State[9];
const int maxstate = 400000;
const int hashsize = 400000;
State states[maxstate], goal;
int blank[maxstate], dist[maxstate];
int head[hashsize], next[hashsize];

void init_table(){memset(head, 0, sizeof(head)), memset(next, 0, sizeof(next));}
int hash(State& u)
{
	int v = 0;
	for(int i = 0;i < 9;i++) v = 10 * v + u[i];
	return v % hashsize;
}
bool try_to_insert(int st0)
{
	int hashkey = hash(states[st0]);
	int u = head[hashkey];
	while(u)
	{
		if(memcmp(states[st0], states[u], sizeof(states[u])) == 0) return false;
		u = next[u];
	}
	next[st0] = head[hashkey];
	head[hashkey] = st0;
	return true;
}

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
int solve()
{
	init_table();
	dist[0] = 0;
	int front = 0, tail = 1;
	while(front < tail)
	{
		State& st0 = states[front];
		if(memcmp(goal, st0, sizeof(st0)) == 0) return dist[front];
		int x = blank[front] % 3, y = blank[front] / 3;
		for(int dir = 0;dir < 4;dir++)
		{
			int newx = x + dx[dir], newy = y + dy[dir];
			blank[tail] = newx + newy * 3;
			if(newx < 0 || newx >= 3 || newy < 0 || newy >= 3) continue;
			State& st1 = states[tail];
			memcpy(&st1, &st0, sizeof(st0));
			st1[blank[tail]] = st0[blank[front]];
			st1[blank[front]] = st0[blank[tail]];
			dist[tail] = dist[front] + 1;
			if(try_to_insert(tail)) tail++;
		}
		front++;
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
