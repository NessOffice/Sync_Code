#include <cstdio>
#include <vector>
#include <stack>
using namespace std;
const int maxn = 1000 + 10;
int main()
{
	// freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	int n, bfs[maxn], dfs[maxn], pos[maxn];
	vector<int> children[maxn];
	while(scanf("%d", &n) == 1)
	{
		for(int i = 1;i <= n;i++) children[i].clear();
		for(int i = 1;i <= n;i++){scanf("%d", &bfs[i]);pos[bfs[i]] = i;}
		for(int i = 1;i <= n;i++) scanf("%d", &dfs[i]);
		stack<int> parents;
		int root = dfs[1];
		parents.push(root);
		for(int i = 2, flag;i <= n;i++)//遍历dfs中每个结点，为他找归属
		{
			flag = 1;
			while(flag)
			{
				int u = parents.top();
				if(u == root || pos[dfs[i]] > pos[u] + 1){//若非兄弟结点
					children[u].push_back(dfs[i]);
					parents.push(dfs[i]);
					flag = 0;
				}else parents.pop();
			}
		}
		for(int i = 1;i <= n;i++)
		{
			printf("%d:", i);
			for(int j = 0, sz = children[i].size();j < sz;j++)
				printf(" %d", children[i][j]);
			printf("\n");
		}
	}
	return 0;
}
