# offline-1.莫队算法

莫队算法是一种离线算法，它适用于query(l+1, r)可快速由query(l, r)转化而来的区间查询问题。

例题：求区间$(l, r)$中不同颜色点个数的平方之和。

~~~cpp
const LL maxn = 5e4+5;
struct Query{LL l, r, id;}queries[maxn];
struct Answer{LL p, q;}ans[maxn];
LL n, m, res, a[maxn], cnt[maxn], block_size, id_of_block[maxn];
bool cmp(const Query &lhs, const Query &rhs)
{
    if(id_of_block[lhs.l] != id_of_block[rhs.l])
        return id_of_block[lhs.l] < id_of_block[rhs.l];
    if(id_of_block[lhs.l] & 1)
        return lhs.r < rhs.r;
    else
        return lhs.r > rhs.r;
}
LL calc_C2(LL l, LL r){return (r-l+1)*(r-l);}
void update(LL col, LL flag)
{
    res -= (cnt[col]*(cnt[col]-1));
    cnt[col] += flag;
    res += (cnt[col]*(cnt[col]-1));
}
void get_ans(LL p, LL q, LL id)
{
    LL d = __gcd(p, q);
    if(q == 0){ans[id].p = 0, ans[id].q = 1;return;} // if q == 0
    ans[id].p = p / d;
    ans[id].q = q / d;
}
int main()
{
    scanf("%lld%lld", &n, &m);
    block_size = n / (LL)(sqrt(m));
    for(LL i = 1;i <= n;i++)
        scanf("%lld", a + i),
        id_of_block[i] = (i-1)/block_size + 1;
    for(LL i = 1;i <= m;i++)
        scanf("%lld%lld", &queries[i].l, &queries[i].r),
        queries[i].id = i;
    sort(queries+1, queries+m+1, cmp);

    LL l = queries[1].l, r = queries[1].r;
    for(LL i = l;i <= r;i++)
        update(a[i], 1);
    get_ans(res, calc_C2(l, r) , queries[1].id);
    for(LL i = 2;i <= m;i++)
    {
        while(l < queries[i].l) update(a[l++], -1);
        while(l > queries[i].l) update(a[--l],  1);
        while(r < queries[i].r) update(a[++r],  1);
        while(r > queries[i].r) update(a[r--], -1);
        get_ans(res, calc_C2(l, r), queries[i].id);
    }
    for(LL i = 1;i <= m;i++)
        printf("%lld/%lld\n", ans[i].p, ans[i].q);
    return 0;
}
~~~

# offline-2.整体二分

例题：求区间第k小值。

~~~cpp
const int maxn = 1e5+5;
const int INF = 1e9+7;
int rd(){int x;scanf("%d", &x);return x;}
int tree[maxn];
int lowbit(int x){return x&-x;}
int add(int begin, int delta){for(int i = begin;i < maxn;i += lowbit(i)) tree[i] += delta;}
int query(int begin){int sum = 0;for(int i = begin;i > 0;i -= lowbit(i)) sum += tree[i];return sum;}
struct Cmd{int a, b, k, id, num, is_query;}cmds[maxn + 5005], cmdsL[maxn + 5005], cmdsR[maxn + 5005];
int ans[5005];
void solve(int l, int r, int L, int R)
{
    if(l > r || L > R) return;
    if(l == r)
    {
        for(int i = L;i <= R;i++)
            if(cmds[i].is_query)
                ans[cmds[i].id] = l;
        return;
    }
    int mid = l + r >> 1, cntL = 0, cntR = 0;
    for(int i = L;i <= R;i++)
    {
        if(cmds[i].is_query){
            int k2 = query(cmds[i].b) - query(cmds[i].a - 1);
            if(k2 >= cmds[i].k){
                cmdsL[++cntL] = cmds[i];
            }else{
                cmds[i].k -= k2;
                cmdsR[++cntR] = cmds[i];
            }
        }else{
            if(cmds[i].num <= mid){
                add(cmds[i].id, 1);
                cmdsL[++cntL] = cmds[i];
            }else{
                cmdsR[++cntR] = cmds[i];
            }
        }
    }
    for(int i = 1;i <= cntL;i++)
        if(cmdsL[i].is_query == 0)
            add(cmdsL[i].id, -1);
    for(int i = 1;i <= cntL;i++)
        cmds[L+i-1] = cmdsL[i];
    for(int i = 1;i <= cntR;i++)
        cmds[L+cntL+i-1] = cmdsR[i];
    solve(    l, mid,      L, L+cntL-1);
    solve(mid+1,   r, L+cntL,        R);
}
int main()
{
    int n = rd(), m = rd(), cnt = 0;
    for(int i = 1;i <= n;i++)
        cmds[++cnt] = (Cmd){0, 0, 0, i, rd(), 0};
    for(int i = 1;i <= m;i++)
        cmds[++cnt] = (Cmd){rd(), rd(), rd(), i, 0, 1};
    solve(-INF, INF, 1, cnt);
    for(int i = 1;i <= m;i++)
        printf("%d\n", ans[i]);
    return 0;
}
~~~

# offline-3.cdq分治

例题：陌上花开。

题目的一项麻烦之处在对完全相同元素的处理。

~~~cpp
const int maxn = 1e5 + 5;
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
~~~



// updated by Ness, 2019-09-18