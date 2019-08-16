#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL maxn = 2e5+5;
const LL MOD = 1e9+7;
LL a[maxn], b[maxn], c[maxn], f[2];
struct Matrix
{
    LL row, col, m[4][4];
    Matrix operator* (const Matrix& rhs) const{
		Matrix res;
        res.row = row, res.col = rhs.col;
        memset(res.m, 0, sizeof(res.m));
		for(LL i = 0;i < res.row;i++)
		for(LL j = 0;j < res.col;j++)
			for(LL k = 0;k < col;k++)
				res.m[i][j] = (res.m[i][j] + m[i][k] * rhs.m[k][j]) % MOD;
		return res;
	}
}tree[maxn<<2], M_init, M_L, M_R;
LL inv(LL num)
{
    LL base = num, ans = 1, expo = MOD-2;
    while(expo)
    {
        if(expo & 1LL)
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
        tree[index].row = tree[index].col = 4;
        tree[index].m[0][0] = 1, tree[index].m[0][1] = 0, tree[index].m[0][2] = 0, tree[index].m[0][3] = 0;
        tree[index].m[1][0] = a[l], tree[index].m[1][1] = a[l], tree[index].m[1][2] = 1, tree[index].m[1][3] = 0;
        tree[index].m[2][0] = b[l], tree[index].m[2][1] = b[l], tree[index].m[2][2] = 0, tree[index].m[2][3] = 0;
        tree[index].m[3][0] = c[l], tree[index].m[3][1] = c[l], tree[index].m[3][2] = 0, tree[index].m[3][3] = 1;
        return;
    }
    LL mid = (l + r) / 2;
    build(2*index, l, mid);
    build(2*index+1, mid+1, r);
    tree[index] = tree[2*index] * tree[2*index+1];
}
void update(LL index, LL l, LL r, LL loc, LL val, char arr)
{
    if(l == r)
    {
        tree[index].m[arr-'a'+1][0] = val;
        tree[index].m[arr-'a'+1][1] = val;
        return;
    }
    LL mid = (l + r) / 2LL;
    if(loc <= mid) update(2*index, l, mid, loc, val, arr);
    else update(2*index+1, mid+1, r, loc, val, arr);
    tree[index] = tree[2*index] * tree[2*index+1];
}
void query(LL index, LL l, LL r, LL x, LL y, char type)
{
    if(y < x)
    {
        if(y == -1)
        {
            if(type == 'L') M_L.m[0][0] = 0;
            if(type == 'R') M_R.m[0][0] = 0;
        }
        if(y == 0)
        {
            if(type == 'L') M_L.m[0][0] = f[0];
            if(type == 'R') M_R.m[0][0] = f[0];
        }
        return;
    }
    if(x <= l && r <= y)
    {
        if(type == 'L') M_L = M_L * tree[index];
        if(type == 'R') M_R = M_R * tree[index];
        return;
    }
    LL mid = (l + r) / 2LL;
    if(x <= mid) query(2*index, l, mid, x, y, type);
    if(y > mid) query(2*index+1, mid+1, r, x, y, type);
}
int main()
{
    LL n, q;
    scanf("%lld%lld", &n, &q);
    scanf("%lld%lld", &f[0], &f[1]);
    M_init.row = 1, M_init.col = 4;
    M_init.m[0][0] = ((f[0]+f[1])%MOD+MOD)%MOD, M_init.m[0][1] = f[1], M_init.m[0][2] = f[0], M_init.m[0][3] = 1;
    for(LL i = 2;i < n;i++) scanf("%lld", a+i);
    for(LL i = 2;i < n;i++) scanf("%lld", b+i);
    for(LL i = 2;i < n;i++) scanf("%lld", c+i);
    build(1, 2, n-1);
    while(q--)
    {
        char cmd_str[10], arr;
        LL x, y, loc, val;
        scanf("%s", &cmd_str);
        if(cmd_str[0] == 'q')
        {
            scanf("%lld%lld", &x, &y);
            M_L = M_R = M_init;
            query(1, 2, n-1, 2, x-1, 'L');
            query(1, 2, n-1, 2,   y, 'R');
            printf("%lld\n", ((M_R.m[0][0] - M_L.m[0][0])%MOD+MOD)%MOD);
        }
        if(cmd_str[0] == 's')
        {
            scanf(" %c[%lld]=%lld", &arr, &loc, &val);
            if(arr == 'F')
            {
                M_init.m[0][2-loc] = f[loc] = val;
                M_init.m[0][0] = (f[0] + f[1]) % MOD;
            }
            else
                update(1, 2, n-1, loc, val, arr);
        }
    }
    return 0;
}
/*
5 6
1 2
1 1 2
2 3 3
3 5 8
query 0 4
query 2 3
set F[0]=3
query 2 4
set b[3]=9
query 3 4
*/