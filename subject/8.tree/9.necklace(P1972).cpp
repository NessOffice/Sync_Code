#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1e6 + 5;
struct Node{int l, r, index, ans;}nodes[maxn];
int lowbit(int num){return (num & -num);}
int n, m, tree[maxn], last[maxn], place[maxn];
bool cmp_by_r(const Node& lhs, const Node& rhs){return lhs.r < rhs.r;}
bool cmp_by_index(const Node& lhs, const Node& rhs){return lhs.index < rhs.index;}
void change(int index, int num)
{
	for(;index <= n;index += lowbit(index))
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
	memset(last, 0, sizeof(last));
	memset(place, 0, sizeof(place));
	scanf("%d", &n);
	for(int i = 1;i <= n;i++)
	{
		int num;
		scanf("%d", &num);
		if(place[num])
			last[i] = place[num];
		place[num] = i;
	}
	scanf("%d", &m);
	for(int i = 1;i <= m;i++)
	{
		nodes[i].index = i;
		scanf("%d%d", &nodes[i].l, &nodes[i].r);
	}
	sort(nodes+1, nodes+m+1, cmp_by_r);
	int cur_last = 1;
	for(int i = 1;i <= m;i++)
	{
		while(cur_last <= nodes[i].r)
		{
			if(last[cur_last])
				change(last[cur_last], -1);
			change(cur_last, 1);
			cur_last++;
		}
		nodes[i].ans = (query(nodes[i].r) - query(nodes[i].l - 1));
	}

	sort(nodes+1, nodes+m+1, cmp_by_index);
	for(int i = 1;i <= m;i++)
		printf("%d\n", nodes[i].ans);
    return 0;
}
