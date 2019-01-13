#include <cstdio>
using namespace std;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out_debug.txt","w",stdout);
	int n, m, kase = 1, line = 0;
	while(scanf("%d%d", &n, &m) == 2)
	{
		line++;
		int cmd, X, Y;
		while(m--)
		{
			line++;
			scanf("%d", &cmd);
			if(cmd == 4);
			else
			{
				scanf("%d%d", &X, &Y);
			} 
		}
		printf("Case %d: %d\n", kase++, line);
	}
	return 0;
}
