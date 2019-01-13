#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 1000 + 10;
struct Node
{
	vector<int> child;
	int level;
};
int main()
{
	// freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	int n, bfs[maxn], dfs[maxn], visNode[maxn];
	Node nodes[maxn];
	while(scanf("%d", &n) == 1)
	{
		for(int i = 0;i <= n;i++){visNode[i] = nodes[i].level = -1;nodes[i].child.clear();}
		for(int i = 0;i < n;i++) scanf("%d", &bfs[i]);
		for(int i = 0;i < n;i++) scanf("%d", &dfs[i]);
		int IndexOfDfs, IndexOfBfs, visDfs, visBfs, visLevel;
		IndexOfDfs = IndexOfBfs = visLevel = 1;
		visNode[0] = dfs[0];
		while(IndexOfDfs < n)
		{
			visDfs = dfs[IndexOfDfs], visBfs = bfs[IndexOfBfs];
			if(nodes[visDfs].level == -1)//当前dfs未被遍历
			{
				if(visBfs == visDfs)//正在访问的dfs结点无子节点或在下一层开始结点的情况
				{
					nodes[visNode[visLevel - 1]].child.push_back(visDfs);
					nodes[visDfs].level = visLevel;
					visNode[nodes[visDfs].level] = visDfs;
					visLevel++;
					IndexOfBfs++, IndexOfDfs++;
				}
				else//用以遍历本层的兄弟结点
				{
					nodes[visDfs].level = visLevel + 1;
					while(visBfs != visDfs)
					{
						nodes[visBfs].level = visLevel;
						visBfs = bfs[++IndexOfBfs];
					}
				}
			}
			else//本层兄弟结点已被遍历的情况下为父母结点“找孩子”
			{
				visNode[nodes[visDfs].level] = visDfs;
				nodes[visNode[nodes[visDfs].level - 1]].child.push_back(visDfs);
				IndexOfDfs++;
			}
		}
		for(int i = 1;i <= n;i++)
		{
			printf("%d:", i);
			// printf(" %d", visNode[i]);
			for(int j = 0, sz = nodes[i].child.size();j < sz;j++)
				printf(" %d", nodes[i].child[j]);
			printf("\n");
		}
	}
	return 0;
}
