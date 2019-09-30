# counting-1.polya定理

polya定理用于降低本质不同对象的计数中枚举的复杂度。

polya定理将本质相同的对象划为一个等价类予以计算，考察置换中循环的个数。

polya定理：$ans = \dfrac{1}{|G|} \sum m^{k_i}$，其中G为置换群的集合，m为颜色数，$k_i$为第i种置换中的循环数。

涉及polya定理的题目一般较为灵活，需要选取合适的枚举对象，有时需要建立对象与对象间的映射，以通过易于枚举的对象求出难于枚举的对象。

例题1：给定n个点的环，给定n种颜色，求本质不同的涂色方案数。规定若两种方案在旋转轮换后相同则其是本质相同的。

思路：$ans = \dfrac{1}{n} \sum\limits_{i = 1}^n n^{gcd(i, n)} = \dfrac{1}{n} \sum\limits_{d | n} \phi(n/d) \cdot n^d$。

```cpp
const LL MOD = 1e9+7;
LL inv_n;
LL qpow(LL base, LL expo) // write yourself
LL calc_phi(LL n)
{
    LL ans = 1;
    for(LL d = 2;d*d <= n;d++)
    {
        if(n % d) continue;
        n /= d, ans *= (d-1);
        while(n % d == 0)
            n /= d,
            ans *= d;
    }
    if(n > 1)
        ans = ans * (n-1);
    return ans;
}
LL polya(LL m, LL n)
{
    LL ans = 0;
    for(LL d = 1;d*d <= n;d++)
    {
        if(n % d) continue;
        ans = ((ans + inv_n * calc_phi(d) % MOD * qpow(m, n/d) % MOD) % MOD + MOD) % MOD;
        if(d*d != n) ans = ((ans + inv_n * calc_phi(n/d) % MOD * qpow(m, d) % MOD) % MOD + MOD) % MOD;
    }
    return ans;
}
int main()
{
    LL T;
    scanf("%lld", &T);
    while(T--)
    {
        LL n;
        scanf("%lld", &n);
        inv_n = qpow(n, MOD-2);
        printf("%lld\n", polya(n, n));
    }
    return 0;
}
```

例题2：将顶点数为n，颜色数为m的图置于一个集合中，定义两个图相等为二图同构，求集合中元素的个数，即求两两不同构的图的数目。

思路：图同构为边同构，但是边置换难以枚举。我们考虑枚举点置换……

~~~cpp
const LL maxn = 60;
LL n, m, MOD, ans, num[maxn], gcd[maxn][maxn], tot, fac[maxn], inv[maxn], inv_fac[maxn];
LL qpow(LL base, LL expo) // write yourself
void calc()
{
    LL sum = 0, cnt = fac[n], same = 1;
    for(LL i = 1;i <= tot;i++)
    {
        sum += num[i] / 2; // no MOD!!!
        for(LL j = i+1;j <= tot;j++)
            sum += gcd[num[i]][num[j]];
        cnt = cnt * inv[num[i]] % MOD;
        if(i > 1 && num[i] == num[i-1]) same++;
        else cnt = cnt * inv_fac[same] % MOD, same = 1;
    }
    cnt = cnt * inv_fac[same] % MOD;
    ans = (ans + cnt % MOD * qpow(m, sum) % MOD) % MOD;
}
void dfs(LL d, LL lst)
{
    if(d == n){calc();return;}
    for(LL i = lst;i <= n - d;i++)
    {
        num[++tot] = i;
        dfs(d + i, i);
        tot--;
    }
}
void init()
{
    fac[1] = inv[1] = inv_fac[1] = 1;
    for(LL i = 2;i < maxn;i++)
    {
        fac[i] = fac[i-1] * i % MOD;
        inv[i] = (MOD - MOD/i) * inv[MOD%i] % MOD;
        inv_fac[i] = qpow(fac[i], MOD-2);
    }
    
    for(LL i = 1;i < maxn;i++)
    for(LL j = 1;j < maxn;j++)
        gcd[i][j] = __gcd(i, j);
}
int main()
{
    scanf("%lld%lld%lld", &n, &m, &MOD);
    init();
    dfs(0, 1);
    printf("%lld", ans * inv_fac[n] % MOD);
    return 0;
}
~~~

# counting-2.Stirling数

第二类斯特林数：$S(n, m)$指将n个不同元素放入m个相同盒子的方案数。

第二类斯特林数公式：$S(n, m) = \dfrac{1}{m!} \sum\limits_{k = 0}^m (-1)^k C(m, k) (m - k)^n$。

递推式：$S(n, m) = S(n-1, m-1) + mS(n-1, m)$。

性质：$n^k = \sum\limits_{i = 0}^k S(k, i) \cdot i! \cdot C(n, i)$。

如果要求$S(n, 0), S(n, 1), S(n, 2), \dots$则这样的卷积式可以用NTT加速求解。

~~~cpp
const LL maxn = 1e6+5;
const LL MOD = 167772161LL;
LL a[maxn], b[maxn], inv[maxn], inv_fac[maxn];
LL qpow(LL base, LL expo) // write yourself
void NTT(LL *a, LL len, bool inv = false)
{
	LL w = 1, d = qpow(3, (MOD-1)/len), t;
	LL i, j, c, s;
	if(inv)
	{
		for(i = 1, j = len-1;i < j;swap(a[i++], a[j--]));
		for(t = qpow(len, MOD-2), i = 0;i < len;i++) a[i] = a[i] % MOD * t % MOD;
	}
	for(s = len>>1;s;s >>= w = 1, d = d * d % MOD)
		for(c = 0;c < s;c++, w = w * d % MOD)
			for(i = c;i < len;i += s<<1)
			{
				a[i|s] = (a[i] + MOD - (t = a[i|s])) * w % MOD;
				a[i] = (a[i] + t) % MOD;
			}
	for(i = 1;i < len;i++)
	{
		for(j = 0, s = i, c = len>>1;c;c >>= 1, s >>= 1)
			j = j<<1 | s&1;
		if(i < j) swap(a[i], a[j]);
	}
}
int main()
{
	LL n;
	scanf("%lld", &n);
	inv[1] = inv_fac[0] = inv_fac[1] = 1;
	for(LL i = 2;i <= n;i++)
	{
		inv[i] = (MOD - MOD/i) * inv[MOD%i] % MOD;
		inv_fac[i] = inv_fac[i-1] * inv[i] % MOD;
	}
	for(LL i = 0, flag = 1;i <= n;i++, flag = MOD-flag)
	{
		a[i] = flag * inv_fac[i] % MOD,
		b[i] = qpow(i, n) * inv_fac[i] % MOD;
	}
	LL len = 2;
	for(;len <= 2*n + 10;len <<= 1);
	NTT(a, len, false);
	NTT(b, len, false);
	for(LL i = 0;i < len;i++)
		a[i] = a[i] * b[i] % MOD;
	NTT(a, len, true);
	for(LL i = 0;i <= n;i++)
		printf("%lld ", a[i]);
	return 0;
}
~~~





// ver1.0 updated by Ness, 20190917