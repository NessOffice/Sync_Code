#include <cstdio>
#include <cstring>
typedef long long LL;
const LL MOD = 1000000007;
const LL maxn = 100;
LL fac[maxn], fac_rev[maxn];
LL T, n, k;
struct Matrix
{
	LL a[maxn][maxn];
	LL r, c;
	Matrix(LL r, LL c):r(r), c(c){memset(a, 0, sizeof(a));}
	Matrix operator* (const Matrix& rhs) const{
		Matrix res = Matrix(r, rhs.c);
		for(LL i = 0;i < res.r;i++)
		for(LL j = 0;j < res.c;j++)
			for(LL k = 0;k < c;k++)
				res.a[i][j] = (res.a[i][j] + a[i][k] * rhs.a[k][j]) % MOD;
		return res;
	}
};
LL C(LL n_, LL m_)
{
    if(m_ > n_ || m_ < 0) return 0;
    return fac[n_] * fac_rev[n_-m_] % MOD * fac_rev[m_] % MOD;
}
LL qpow_num(LL base,LL expo)
{
    LL ans = 1;
    while(expo)
    {
        if(expo & 1)
            ans = ans*base % MOD;
        expo >>= 1;
        base = base*base % MOD;
    }
    return ans;
}
void init_matrix_first(Matrix* first)
{
    first->a[k+1][0] = 1;
}
void init_matrix_base(Matrix* base)
{
    for(int i = 1;i < k+2;i++)
    {
        int n_ = k+1-i;
        for(int j = i;j < k+2;j++)
            base->a[i][j] = C(n_, j-i);
    }
    base->a[0][0] = 2;
    for(int j = 1;j < k+2;j++)
        base->a[0][j] = base->a[1][j];
}
LL qpow_matrix(LL expo)
{
    Matrix ans = Matrix(k+2, 1), base = Matrix(k+2, k+2);
    init_matrix_first(&ans);
    init_matrix_base(&base);
    while(expo)
    {
        if(expo & 1LL)
            ans = base * ans;
        expo >>= 1LL;
        base = base * base;
    }
    return ans.a[0][0];
}
void init()
{
    fac[0] = fac_rev[0] = 1;
    for(LL i = 1;i < maxn;i++)
    {
        fac[i] = fac[i-1]*i % MOD;
        fac_rev[i] = qpow_num(fac[i], MOD-2);
    }
}
int main()
{
    init();
    scanf("%lld", &T);
    while(T--)
    {
        scanf("%lld%lld", &n, &k);
        printf("%lld\n", qpow_matrix(n));
    }
    return 0;
}

/*
45
46 40
18872153
23 46
69685699
29 25
42508707
35 36
39834844
23 34
12430532
24 38
96846880
37 38
11967604
32 45
68451387
48 42
38078892
31 23
24625
41 47
6735073
28 41
91411372
33 27
36700690
23 43
12233992
46 37
13923374
31 22
48286618
40 32
23208325
50 34
52059983
44 22
22471798
30 26
8805034
37 41
19300058
43 48
33930857
35 45
10421802
33 38
39224310
43 25
6566990
22 25
4229744
43 44
73186322
27 40
163546
20 34
26350460
43 36
42895821
34 35
25866545
31 34
60476765
27 27
79670446
36 38
30631389
33 26
72354911
31 23
24625
25 25
3723088
32 48
15326549
43 35
80749811
48 47
72743181
30 43
26166681
22 22
27831029
41 26
35708924
48 25
95394278
34 35
25866545
*/