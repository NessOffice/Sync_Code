#include <cstdio>
#include <cstring>
#include <algorithm>
const int MAXN = 1e5 + 5;
int n, color[MAXN], map[MAXN], dfn[MAXN], succdfn[MAXN], loop_size[MAXN];
int main()
{
	memset(color, 0, sizeof(color));
	memset(loop_size, 0, sizeof(loop_size));
	memset(dfn, 0, sizeof(dfn));
	memset(succdfn, 0, sizeof(succdfn));
	scanf("%d", &n);
	for(int i = 1;i <= n;i++)
		scanf("%d", &map[i]);
	for(int i = 1;i <= n;i++)
	// here, i stands for the ith cow
	{
		int flag_quit = 0;
		for(int pos = i, dfn_temp = 0;!flag_quit;pos = map[pos], dfn_temp++)
		// here, pos stands for the position of the cow
		// while dfn stands for the steps the cow has taken
		{
			flag_quit = 1;
			if(!color[pos]){
				color[pos] = i;
				dfn[pos] = dfn_temp;
				flag_quit = 0;
			}else if(color[pos] == i){
				loop_size[i] = dfn_temp - dfn[pos];
				succdfn[i] = dfn[pos];
				printf("%d\n", dfn_temp);
			}else{
				loop_size[i] = loop_size[color[pos]]; // wonderful!!
				// succdfn[i] = dfn_temp + succdfn[color[pos]];
				succdfn[i] = dfn_temp + std::max(succdfn[color[pos]] - dfn[pos], 0); // I dont understand
				printf("%d\n", succdfn[i] + loop_size[i]);
			}
		}
	}
	return 0;
}
