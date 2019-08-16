#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 4e4 + 5;
struct Node{int A, B;}nodes[maxn];
bool cmp_by_A(const Node& lhs, const Node& rhs){return lhs.A < rhs.A || (lhs.A == rhs.A && lhs.B < rhs.B);}
int lowbit(int num){return (num & -num);}
int n, k, tree[maxn], res[maxn];
void add(int index, int num)
{
	for(;index <= k;index += lowbit(index))
		tree[index] += num;
}
int query(int begin)
{
	int ans = 0;
	for(int i = begin;i > 0;i -= lowbit(i))
		ans += tree[i];
	return ans;
}
int main()
{
	scanf("%d", &n);
	k = 40000;
	for(int i = 1;i <= n;i++)
		scanf("%d%d", &nodes[i].A, &nodes[i].B);
	sort(nodes+1, nodes+n+1, cmp_by_A);
	for(int i = 1;i <= n;i++)
	{
		int target = nodes[i].B+1; // caution B == 0!
		int num = 1;
		while(i+1 <= n && nodes[i+1].A == nodes[i].A && nodes[i+1].B == nodes[i].B)
			num++, i++;
		add(target, num);
		res[query(target)] += num;
		
	}
	for(int i = 1;i <= n;i++)
		printf("%d\n", res[i]);
    return 0;
}
