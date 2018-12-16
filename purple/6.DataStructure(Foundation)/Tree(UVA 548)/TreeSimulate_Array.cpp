#include <cstdio>
#include <set>
#include <map>
using namespace std;
const int maxn = 10000 + 10;
int left[maxn], right[maxn], weigh[maxn];
int postOrder[maxn], inOrder[maxn];
map<int, int> leaf;
void dfs(int u)
{
	if(left[u] != -1)
	{
		weigh[left[u]] = weigh[u] + left[u];
		dfs(left[u]);
	}
	if(right[u] != -1)
	{
		weigh[right[u]] = weigh[u] + right[u];
		dfs(right[u]);
	}
	if(left[u] == -1 && right[u] == -1) leaf[weigh[u]] = u;
}
int TreeBuild(int L1, int R1, int L2, int R2)
{
	if(L1 >= R1) return -1;
	int value = postOrder[R2 - 1], cnt1 = 0;
	while(inOrder[L1 + cnt1] != value) cnt1++;
	left[value] = TreeBuild(L1, L1 + cnt1, L2, L2 + cnt1);
	right[value] = TreeBuild(L1 + cnt1 + 1, R1, L2 + cnt1, R2 - 1);
	return value;
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(1)
	{
		leaf.clear();
		set<int> order1;
		int temp, quit = 0, cnt1 = 0;
		while(quit = scanf("%d", &temp))
		{
			if(quit == -1 || order1.count(temp)) break;
			order1.insert(temp);
			inOrder[cnt1++] = temp;
		}
		if(quit == -1) break;
		postOrder[0] = temp;
		for(int i = 1;i < cnt1;i++)
			scanf("%d", &postOrder[i]);
		int root = postOrder[cnt1 - 1];
		weigh[root] = root;
		TreeBuild(0, cnt1, 0, cnt1);
		dfs(root);
		printf("%d\n", leaf.begin()->second);
	}
	return 0;
}
