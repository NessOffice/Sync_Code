#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 5; // caution
struct Flower{int x, y, z, dup, ans;}flowers_dup[maxn], flowers[maxn];
bool cmp_by_xyz(const Flower& lhs, const Flower& rhs)
{
	if(lhs.x != rhs.x) return lhs.x < rhs.x;
	if(lhs.y != rhs.y) return lhs.y < rhs.y;
	return lhs.z < rhs.z;
}
bool cmp_by_yz(const Flower& lhs, const Flower& rhs){return lhs.y < rhs.y || (lhs.y == rhs.y && lhs.z < rhs.z);}
bool is_same(const Flower& lhs, const Flower& rhs)
{
	return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
}
int lowbit(int num){return (num & -num);}
int n_, n, k, tree[2*maxn], ans[maxn];
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
void cdq(int l, int r)
{
	if(l == r) return;
	int mid = (l+r)/2;
	cdq(l, mid);
	cdq(mid+1, r);
	sort(flowers + l, flowers + mid+1, cmp_by_yz);
	sort(flowers + mid+1, flowers + r+1, cmp_by_yz);
	int ptrl = l;
	for(int ptrr = mid+1;ptrr <= r;ptrr++)
	{
		while(ptrl <= mid && (flowers[ptrl].y <= flowers[ptrr].y))
		{
			add(flowers[ptrl].z, flowers[ptrl].dup);
			ptrl++;
		}
		flowers[ptrr].ans += query(flowers[ptrr].z);
	}
	for(int ptr = l;ptr < ptrl;ptr++) // clear the tree
		add(flowers[ptr].z, -flowers[ptr].dup);
}
int main()
{
	scanf("%d%d", &n_, &k);
	for(int i = 1;i <= n_;i++)
		scanf("%d%d%d", &flowers_dup[i].x, &flowers_dup[i].y, &flowers_dup[i].z);
	sort(flowers_dup+1, flowers_dup+n_+1, cmp_by_xyz);
	int cnt = 1, n = 0;
	for(int i2 = 1;i2 <= n_;i2++)
	{
		if(i2+1 <= n_ && is_same(flowers_dup[i2], flowers_dup[i2+1]))
			cnt++;
		else
		{
			flowers[++n] = flowers_dup[i2];
			flowers[n].dup = cnt;
			cnt = 1;
		}
	}
	cdq(1, n);
	for(int i = 1;i <= n;i++)
		ans[flowers[i].ans + flowers[i].dup - 1] += flowers[i].dup;
	for(int i = 0;i < n_;i++)
		printf("%d\n", ans[i]);
    return 0;
}
