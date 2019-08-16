#include <cstdio>
#include <cstring>
const int MAXN = 60;
int G[MAXN][MAXN];
int vis[MAXN], matched[MAXN];
int person[MAXN], bed[MAXN], student[MAXN];
int matches, num_person, num_bed;
// person[i] indicates the ith person who will occupy a bed(num_of_all - num_of_homegoers)
bool find(int lft) // lft for the one in the LHS(person), while rgt for the one in the RHS(bed)
{
	for(int i = 0;i < num_bed;i++)
	{
		int rgt = bed[i];
		if(!G[lft][rgt]) continue;
		if(vis[rgt]) continue;
		vis[rgt] = 1;
		if(!matched[rgt] || find(matched[rgt]))
		{
			matched[rgt] = lft;
			return true;
		}
	}
	return false;
}
void init()
{
	matches = num_bed = num_person = 0;
	memset(vis, 0, sizeof(vis));
	memset(matched, 0, sizeof(matched));
	memset(G, 0, sizeof(G));
}
int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		init();
		int n;
		scanf("%d", &n);
		for(int i = 1;i <= n;i++)
		{
			scanf("%d", &student[i]);
			if(student[i]) bed[num_bed++] = i;
		}
		for(int i = 1;i <= n;i++)
		{
			int go_home;
			scanf("%d", &go_home);
			if(student[i] && go_home);
			else person[num_person++] = i;
		}
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= n;j++)
			{
				scanf("%d", &G[i][j]);
				G[i][j] = ((G[i][j] && student[j]) ? 1 : 0);
			}
			if(student[i]) G[i][i] = 1;
		}
		for(int i = 0;i < num_person && matches < num_bed;i++)
		{
			int lft = person[i];
			if(num_person > num_bed) break; // special case 1
			memset(vis, 0, sizeof(vis));
			if(find(lft)) matches++;
		}
		printf("%s\n", (matches >= num_bed ? "^_^" : "T_T"));
	}
	return 0;
}
