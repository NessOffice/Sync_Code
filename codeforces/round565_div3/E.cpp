#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 2e5 + 5;
int colors[maxn], num_of_color[2];
void paint(int u, int color)
{
	colors[u] = color;
	num_of_color[color]++;
}
int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		num_of_color[0] = num_of_color[1] = 0;
		for(int i = 1;i <= n;i++) // don't use memset! it's a duliu problem
			colors[i] = -1;
		for(int i = 0;i < m;i++)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			if(colors[u] != -1 && colors[v] != -1) continue;
			if(colors[u] == -1 && colors[v] == -1)
			{
				paint(u, 0);
				paint(v, 1);
			}
			if(colors[u] == -1)
				paint(u, 1 ^ colors[v]);
			if(colors[v] == -1)
				paint(v, 1 ^ colors[u]);
		}
		int max_color = (num_of_color[0] < num_of_color[1] ? 0 : 1);
		printf("%d\n", num_of_color[max_color]);
		for(int i = 1;i <= n;i++)
			if(colors[i] == max_color)
				printf("%d ", i);
		putchar('\n');
	}
    return 0;
}
