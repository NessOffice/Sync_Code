#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL maxn = 1e5+5;
const LL MOD = 998244353;
LL a[maxn];
struct Matrix
{
    LL r, c, a[2][2];
    Matrix operator* (const Matrix& rhs) const{
		Matrix res;
        res.r = r, res.c = rhs.c;
        memset(res.a, 0, sizeof(res.a));
		for(LL i = 0;i < res.r;i++)
		for(LL j = 0;j < res.c;j++)
			for(LL k = 0;k < c;k++)
				res.a[i][j] = (res.a[i][j] + a[i][k] * rhs.a[k][j]) % MOD;
		return res;
	}
}tree[maxn<<2], P, Q;
LL inv(LL num)
{
    LL base = num, ans = 1, expo = MOD-2;
    while(expo)
    {
        if(expo & 1)
            ans = ans * base % MOD;
        expo >>= 1LL;
        base = base * base % MOD;
    }
    return ans;
}
void build(LL index, LL l, LL r)
{
    if(l == r)
    {
        tree[index].r = tree[index].c = 2;
        tree[index].a[0][0] = a[l];
        tree[index].a[0][1] = 1;
        tree[index].a[1][0] = 1;
        tree[index].a[1][1] = 0;
        return;
    }
    LL mid = (l + r) / 2LL;
    build(2LL*index, l, mid);
    build(2LL*index+1LL, mid+1LL, r);
    tree[index] = tree[2*index] * tree[2*index+1];
}
void update(LL index, LL l, LL r, LL loc, LL val)
{
    if(l == r)
    {
        tree[index].a[0][0] = a[loc] = val;
        return;
    }
    LL mid = (l + r) / 2LL;
    if(loc <= mid) update(2*index, l, mid, loc, val);
    else update(2*index+1, mid+1, r, loc, val);
    tree[index] = tree[2*index] * tree[2*index+1];
}
void query(LL index, LL l, LL r, LL x, LL y)
{
    if(x <= l && r <= y)
    {
        P = P * tree[index];
        Q = Q * tree[index];
        return;
    }
    LL mid = (l + r) / 2LL;
    if(x <= mid) query(2*index, l, mid, x, y);
    if(y > mid) query(2*index+1, mid+1, r, x, y);
}
int main()
{
    P.r = Q.r = 1;
    P.c = Q.c = 2;
    LL T, n, q;
    scanf("%lld", &T);
    while(T--)
    {
        scanf("%lld", &n);
        for(LL i = 1;i <= n;i++)
            scanf("%lld", a + i);
        build(1, 1, n);
        scanf("%lld", &q);
        while(q--)
        {
            LL cmd, x, y, loc, val;
            scanf("%lld", &cmd);
            if(cmd == 1LL)
            {
                scanf("%lld%lld", &loc, &val);
                update(1, 1, n, loc, val);
            }
            if(cmd == 2LL)
            {
                scanf("%lld%lld", &x, &y);
                P.a[0][0] = a[x];
                P.a[0][1] = 1;
                Q.a[0][0] = 1;
                Q.a[0][1] = 0;
                if(x != y) query(1, 1, n, x+1, y);
                printf("%lld\n", P.a[0][0] * inv(Q.a[0][0]) % MOD);
            }
        }
    }
    return 0;
}
