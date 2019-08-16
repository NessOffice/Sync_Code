#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 3e5+5;
int tree[maxn<<2], ptr[maxn]; // tree[id] stores the minimum index of val in [l, r]
int query(int id, int l, int r, int lft) // return mex{val[lft, i]}
{
	if(l == r) return l;
	int mid = l+r>>1;
	if(tree[id<<1] < lft)
		return query(id<<1, l, mid, lft);
	else
		return query(id<<1|1, mid+1, r, lft);
}
void update(int id, int l, int r, int rgt, int val) // rgt for the rightmost element whose value is val
{
	if(l == r){tree[id] = rgt;return;}
	int mid = l+r>>1;
	if(val <= mid)
		update(id<<1, l, mid, rgt, val);
	else
		update(id<<1|1, mid+1, r, rgt, val);
	tree[id] = min(tree[id<<1], tree[id<<1|1]);
}
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1, num;i <= n;i++)
	{
		scanf("%d", &num);
		for(int j;num;num--)
		{
			scanf("%d", &j);
			if(ptr[j] == 0)
				ptr[j] = i;
		}
	}
	for(int i = 1;i <= n;i++)
	{
		int ans = 1; // if ptr[i] == 0
		if(ptr[i])
			ans = query(1, 1, maxn-1, ptr[i]+1);
		update(1, 1, maxn-1, i, ans);
		printf("%d ", ans);
	}
	return 0;
}
