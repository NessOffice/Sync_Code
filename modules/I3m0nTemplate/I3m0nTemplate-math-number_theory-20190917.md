# number_theory-1.杜教筛

杜教筛用于计算某些积性函数的前缀和，如phi函数，mu函数，或是其他（尤其是可用Dirichlet卷积表示的函数）。杜教筛的前置知识为莫比乌斯反演。

复杂度：$O(n^{2/3})$，但会随预处理的值改变而改变，预处理的值一般取5e6。

记号约定：$I(n) = 1, id(n) = n, \epsilon(n) = [n = 1]$。

常见的Dirichlet卷积式：$\phi \ * \ I = id, \mu \ * \ id = \phi$。

杜教筛核心公式：若$h = f \ * \ g$，则有$g(1)S(n) = \sum\limits_{i = 1}^n h(i) - \sum\limits_{d = 2}^n g(d) \cdot S(\lfloor \dfrac{n}{d} \rfloor)$，其中S为f的前缀和。

~~~cpp
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <tr1/unordered_map>
using namespace std;
typedef long long LL;
tr1::unordered_map<LL, LL> sum_phi_big;
tr1::unordered_map<LL, LL> sum_mu_big;
const LL maxn = 5e6+5;
LL sum_phi[maxn];
LL sum_mu[maxn];
bool isP[maxn];
LL P[maxn];
LL total = 0;
void init()
{
	memset(isP, true, sizeof(isP));
	memset(P, 0, sizeof(P));
	isP[0] = isP[1] = false;
    sum_mu[1] = sum_phi[1] = 1;
	for(LL i = 2;i < maxn;i++)
	{
		if(isP[i])
        {
            P[++total]=i;
            sum_mu[i] = -1;
            sum_phi[i] = i-1;
        }
		for(LL j = 1, prime = P[j];j <= total && i*prime < maxn;j++, prime = P[j])
		{
			isP[i*prime] = false;
			if(!(i%prime))
            {
                sum_phi[i*prime] = prime * sum_phi[i];
                break;
            }
            sum_phi[i*prime] = sum_phi[prime] * sum_phi[i];
            sum_mu[i*prime] = -sum_mu[i];
		}
	}
    for(LL i = 1;i < maxn;i++)
        sum_phi[i] += sum_phi[i-1],
        sum_mu[i] += sum_mu[i-1];
}
LL calc_sum_mu(LL n)
{
    if(n < maxn) return sum_mu[n];
    if(sum_mu_big[n]) return sum_mu_big[n];
    LL ans = 1;
    for(LL l = 2, r;l <= n;l = r+1)
    {
        r = n/(n/l);
        ans -= (r-l+1)*calc_sum_mu(n / l);
    }
    return sum_mu_big[n] = ans;
}
LL calc_sum_phi(LL n)
{
    if(n < maxn) return sum_phi[n];
    if(sum_phi_big[n]) return sum_phi_big[n];
    LL ans = n*1LL*(n+1)/2LL;
    for(LL l = 2, r;l <= n;l = r+1)
    {
        r = n/(n/l);
        ans -= 1LL*(r-l+1)*calc_sum_phi(n / l);
    }
    return sum_phi_big[n] = ans;
}
LL main()
{
    init();
    LL T;
    scanf("%d", &T);
    while(T--)
    {
        LL n;
        scanf("%d", &n);
        prLLf("%lld %d\n", calc_sum_phi(n), calc_sum_mu(n));
    }
    return 0;
}
~~~

# number_theory-2.min_25筛

min_25筛用于计算某些积性函数的前缀和，其中$f(p)$需为项数较小的多项式，$f(p^k)$可由$f(p)$快速计算得出。min_25筛并未用到较难的前置知识，但其所涉及的算法较广：数论分块、动态规划、线性筛、计数。

min_25筛在S函数的求解中不需要记忆化，其复杂度为$O(\dfrac{n^{3/4} }{log \ n})$，在数据量为1e10的情况下略快于杜教筛。

~~~cpp
// f(p^k) = p^k(p^k - 1)
// in the code below, 1 is excluded in S. CATUION! CAUTION! CAUTION!
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long LL;
const LL maxn = 1e6+5; // sqrt(1e10)
const LL MOD = 1e9+7;
LL num_prime, prime[maxn], sum_p[maxn], sum_p2[maxn], g1[maxn], g2[maxn], num_w, w[maxn];
LL n, sqrt_n;
LL id1[maxn], id2[maxn];
bool isnt_prime[maxn];
void sift(LL maxn)
{
    for(LL i = 2;i <= maxn;i++)
    {
        if(!isnt_prime[i])
        {
            prime[++num_prime] = i;
            sum_p[num_prime] = (sum_p[num_prime-1] + i) % MOD;
            sum_p2[num_prime] = (sum_p2[num_prime-1] + i*i%MOD) % MOD;
        }
        for(LL j = 1;j <= num_prime && prime[j]*i <= maxn;j++)
        {
            isnt_prime[prime[j]*i] = true;
            if(i % prime[j] == 0) break;
        }
    }
}
LL S(LL m, LL j)
{
    if(prime[j] >= m) return 0;
    LL k = (m <= sqrt_n ? id1[m] : id2[n / m]);
    LL ans = (((g2[k]-g1[k])-(sum_p2[j]-sum_p[j]))%MOD+MOD)%MOD;
    for(LL i = j + 1;i <= num_prime && prime[i]*prime[i] <= m;i++)
        for(LL e = 1, p = prime[i];p <= m;e++, p *= prime[i])
        {
            LL p_ = p % MOD;
            ans = ((ans + p_*(p_-1)%MOD*(S(m/p, i)+(e!=1)))%MOD+MOD)%MOD;
        }
    return ans;
}
LL qpow(LL base, LL expo)
{
    LL ans = 1;
    base %= MOD;
    while(expo)
    {
        if(expo & 1LL)
            ans = ans * base % MOD;
        expo >>= 1LL;
        base = base * base % MOD;
    }
    return ans;
}
LL inv_6 = qpow(6, MOD-2);
void get_id()
{
    for(LL l = 1, r;l <= n;l = r + 1)
    {
        r = n/(n/l);
        w[++num_w] = n / l;
        g1[num_w] = w[num_w] % MOD;
        g2[num_w] = (g1[num_w]*(g1[num_w]+1)%MOD*(2*g1[num_w]+1)%MOD*inv_6%MOD+2*MOD-1)%MOD;
        g1[num_w] = (g1[num_w]*(g1[num_w]+1)/2-1)%MOD;
        if(n/l <= sqrt_n) id1[n/l] = num_w;
        else id2[n/(n/l)] = num_w;
    }
}
void get_g()
{
    for(LL i = 1;i <= num_prime;i++)
        for(LL j = 1;j <= num_w && prime[i]*prime[i] <= w[j];j++)
        {
            LL val = w[j] / prime[i];
            LL k = (val <= sqrt_n ? id1[val] : id2[n / val]);
            g1[j] = ((g1[j] - prime[i]*(g1[k]-sum_p[i-1])%MOD)%MOD+MOD)%MOD;
            g2[j] = ((g2[j] - prime[i]*prime[i]%MOD*(g2[k]-sum_p2[i-1]+MOD)%MOD)%MOD+MOD)%MOD;
        }
}
int main()
{
    scanf("%lld", &n);
    sqrt_n = sqrt(n);
    sift(sqrt_n);
    get_id();
    get_g();
    
    printf("%lld\n", (S(n, 0)+1)%MOD);
    return 0;
}
~~~

# number_theory-3.类欧几里得算法

类欧几里得算法用于在$O(log \ n)$的时间内计算$f(k_1, k_2, a, b, c, n) = \sum\limits_{i = 0}^n x^{k_1} ((ax + b)/c)^{k_2}$的值。

低端版本：

~~~cpp
// the code here only copes with \sum (ax + b)/c
const LL MOD = 998244353LL;
LL calc_sum(LL a, LL b, LL c, LL n)
{
    if(n == 0) return b / c;
    LL ans = (n + 1) * (b / c) % MOD;
    ans += ((n * (n + 1) / 2) * (a / c) % MOD);
    ans %= MOD;
    a %= c, b %= c;
    if((a * n + b) / c < 1) return ans;
    LL m = (a * n + b) / c;
    ans += (n * m % MOD);
    ans %= MOD;
    ans -= calc_sum(c, c-b-1, a, m-1);
    ans = ((ans % MOD) + MOD) % MOD;
    return ans;
}
~~~

普适版本：

~~~cpp
// !!!the code here is directly copied from the Internet!!! Remember to make some changes when using this template!!!
const int MOD=1e9+7;
inline ll qp(ll a,ll b)
{
    ll x=1; a%=MOD;
    while(b)
    {
        if(b&1) x=x*a%MOD;
        a=a*a%MOD; b>>=1;
    }
    return x;
}
namespace Lagrange {
ll x[23333],y[23333],a[23333],g[23333],h[23333],p[23333]; int N;
void work()
{
    for(int i=0;i<N;++i) a[i]=0;
    g[0]=1;
    for(int i=0;i<N;++i)
    {
        for(int _=0;_<=i;++_)
            h[_+1]=g[_]; h[0]=0;
        for(int _=0;_<=i;++_)
            h[_]=(h[_]-g[_]*(ll)x[i])%MOD;
        for(int _=0;_<=i+1;++_) g[_]=h[_];
    }
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<=N;++j) p[j]=g[j];
        for(int j=N;j;--j)
            p[j-1]=(p[j-1]+p[j]*(ll)x[i])%MOD;
        ll s=1;
        for(int j=0;j<N;++j) if(i!=j)
            s=s*(x[i]-x[j])%MOD;
        s=y[i]*qp(s,MOD-2)%MOD;
        for(int _=0;_<N;++_)
            a[_]=(a[_]+p[_+1]*s)%MOD;
    }
}
vector<int> feed(vector<int> v)
{
    N=v.size();
    for(int i=0;i<N;++i) x[i]=i,y[i]=v[i];
    work(); v.clear();
    for(int i=0;i<N;++i) v.push_back(a[i]);
    while(v.size()&&!v.back()) v.pop_back();
    return v;
}
ll calc(vector<int>&v,ll xx)
{
    ll s=0,gg=1; xx%=MOD;
    for(int i=0;i<N;++i)
        s=(s+gg*v[i])%MOD,gg=gg*xx%MOD;
    return s;
}
}
using Lagrange::feed;
using Lagrange::calc;
//ps[k]=\sum_{i=0}^x i^k
vector<int> ps[2333];
//rs[k]=\sum_{i=0}^x ((i+1)^k-i^k)
vector<int> rs[2333];
struct arr{ll p[11][11];};
ll C[233][233];
arr calc(ll a,ll b,ll c,ll n)
{
    arr w;
    if(n==0) a=0;
    if(a==0||a*n+b<c)
    {
        for(int i=0;i<=10;++i)
        {
            ll t=calc(ps[i],n),s=b/c;
            for(int j=0;i+j<=10;++j)
                w.p[i][j]=t,t=t*s%MOD;
        }
        return w;
    }
    for(int i=0;i<=10;++i)
        w.p[i][0]=calc(ps[i],n);
    if(a>=c||b>=c)
    {
        arr t=calc(a%c,b%c,c,n);
        ll p=a/c,q=b/c;
        for(int i=0;i<=10;++i)
            for(int j=1;i+j<=10;++j)
            {
                ll s=0,px=1;
                for(int x=0;x<=j;++x,px=px*p%MOD)
                {
                    ll qy=1;
                    for(int y=0;x+y<=j;++y,qy=qy*q%MOD)
                    {
                        //x^(i) (px)^x q^y ??^(j-x-y)
                        s+=px*qy%MOD*C[j][x]%MOD*C[j-x][y]
                        %MOD*t.p[i+x][j-x-y]; s%=MOD;
                    }
                }
                w.p[i][j]=s;
            }
        return w;
    }
    ll m=(a*n+b)/c;
    arr t=calc(c,c-b-1,a,m-1);
    for(int i=0;i<=10;++i)
        for(int j=1;i+j<=10;++j)
        {
            ll s=calc(rs[j],m-1)*calc(ps[i],n)%MOD;
            for(int p=0;p<j;++p)
            {
                for(unsigned q=0;q<ps[i].size();++q)
                {
                    ll v=C[j][p]*ps[i][q]%MOD;
                    //v*t^p*((tc+c-b-1)/a)^q
                    s-=t.p[p][q]*v; s%=MOD;
                }
            }
            w.p[i][j]=s%MOD;
        }
    return w;
}
int T,n,a,b,c,k1,k2;
int main()
{
    for(int i=0;i<=230;++i)
    {
        C[i][0]=1;
        for(int j=1;j<=i;++j)
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
    }
    for(int i=0;i<=10;++i)
    {
        ll sp=0,sr=0; vector<int> p,r;
        for(int j=0;j<=20;++j)
            sp+=qp(j,i),sr+=qp(j+1,i)-qp(j,i),
            sp%=MOD,sr%=MOD,p.push_back(sp),r.push_back(sr);
        ps[i]=feed(p); rs[i]=feed(r);
    }
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d%d%d%d",
        &n,&a,&b,&c,&k1,&k2);
        arr s=calc(a,b,c,n);
        int p=s.p[k1][k2];
        p=(p%MOD+MOD)%MOD;
        printf("%d\n",p);
    }
}
~~~

# number_theory-4.Cipolla算法

cipolla算法用于解二次剩余方程，即求解方程$x^2 \equiv N(mod \ p)$中的x。

中心思想为扩展数域，通过构造模意义下的虚单位元辅助求解。

~~~cpp
LL omega2;
struct cp{LL real, imag;};
cp mul_cp(cp a, cp b, LL p)
{
    cp ans;
    ans.real = ((a.real*b.real%p + a.imag*b.imag%p*omega2%p) % p + p) % p;
    ans.imag = ((a.real*b.imag%p + a.imag*b.real%p) % p + p) % p;
    return ans;
}
LL qpow_cp(cp base, LL expo, LL p)
{
    cp ans = {1, 0};
    while(expo)
    {
        if(expo & 1LL)
            ans = mul_cp(ans, base, p);
        expo >>= 1LL;
        base = mul_cp(base, base, p);
    }
    return ans.real;
}
LL qpow_real(LL base, LL expo, LL p) // write yourself
LL cipolla(LL n, LL p)
{
    if(n == 0) return 0;
    if(qpow_real(n, (p-1)/2, p) != 1) return -1;
    LL a;
    while(1)
    {
        a = rand() % p;
        omega2 = ((a*a-n) % p + p ) % p;
        if(qpow_real(omega2, (p-1)/2, p) == p-1) break;
    }
    return qpow_cp((cp){a, 1}, (p+1)/2, p);
}
int main()
{
    srand(time(0));
    LL T;
    scanf("%lld", &T);
    while(T--)
    {
        LL n, p, ans1, ans2;
        scanf("%lld%lld", &n, &p);
        ans1 = cipolla(n, p), ans2 = p - ans1;
        if(ans1 == -1)
            printf("Hola!\n");
        else
        {
            if(ans1 > ans2) swap(ans1, ans2);
            if(ans2 != ans1 && ans2 != p)
                printf("%lld %lld\n", ans1, ans2);
            else
                printf("%lld\n", ans1);
        }
    }
    return 0;
}
~~~

# number_theory-5.乘法逆元相关

乘法逆元的求解方法很多，具体要根据题目的需求选择合适的求解方法。

1.拓欧

2.欧拉定理

3.线性递推（仅适用于p为素数的情形）

~~~cpp
inv[1] = 1;
for(int i = 2;i < p;i++)
    inv[i] = (p - p/i) * inv[p % i] % p;
~~~

4.离线+前缀积

~~~cpp
inv_product[n] = qpow(product[n], p-2, p);
for(int i = n;i > 0;i--)
{
    inv[i] = 1LL * product[i - 1] * inv_product[i] % p;
    inv_product[i - 1] = 1LL * inv_product[i] * a[i] % p;
}
~~~

# number_theory-6.中国剩余定理

此处虽标为“中国剩余定理”但实为拓展版，不需要模数互素这一条件。

中国剩余定理用于计算模意义下的同余方程组的解。

复杂度为$O(nlog \ n)$，log是扩欧所带来的。

python实现：

~~~py
def gcd(a, b):
	if(b == 0):
		return a
	return gcd(b, a % b)
def lcm(a, b):
	return a * b // gcd(a, b)

x = 0
y = 0
def exgcd(a, b):
	global x
	global y
	if(b == 0):
		x = 1
		y = 0
		return a
	r = exgcd(b, a % b)
	temp = y
	y = x - (a // b) * y
	x = temp
	return r

a = [0]
b = [0]
def excrt(k):
	M = a[1]
	ans = b[1] % a[1]
	for i in range(2, k+1):
		d = exgcd(M, a[i])
		c = (b[i] - ans % a[i] + a[i]) % a[i]
		if(c % d != 0):
			return -1

		t = x
		t = t * (c // d) % a[i]
		ans += (t * M)
		M = lcm(M, a[i])
		ans = (ans % M + M) % M
	return (ans % M + M) % M
~~~

C++实现：

~~~cpp
LL a[MAXN], b[MAXN];
LL euclid(LL a, LL b){return b == 0 ? a : euclid(b, a % b);}
LL LCM(LL a, LL b){return a / euclid(a, b) * b;}
LL extend_euclid(LL a, LL b, LL &x, LL &y)
{
    if(b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    LL r = extend_euclid(b, a%b, x, y);
    LL temp = y;
    y = x - (a/b)*y;
    x = temp;
    return r;
}
LL qmul(LL a,LL b, LL MOD)
{
	a %= MOD;
    LL ans = 0;
    while(b)
    {
        if(b & 1)
            ans = (ans + a) % MOD;
        b >>= 1;
        a = (a + a) % MOD;
    }
    return ans % MOD;
}
LL exCRT(LL n)// x === bi(mod ai)
{
    LL M, ans;
    M = a[1];
    ans = b[1] % a[1];
    for(LL i = 2;i <= n;i++)
    {
        LL t, temp_y, gcd;
        gcd = extend_euclid(M, a[i], t, temp_y); // t * M[k-1] + a[k] * temp_y = 1
		LL c = (b[i] - ans % a[i] + a[i]) % a[i];
		if(c % gcd) return -1;
		
        t = qmul(t, c / gcd, a[i]); // caution!
        ans += (t*M);
        M = LCM(M, a[i]);
        ans = (ans % M + M) % M;
    }
    return (ans % M + M) % M;
}
~~~

# number_theory-7.Lucas定理

Lucas定理：如p为素数，则$C_n^m \% p = C_{n/p}^{m/p} \cdot C_{n \% p}^{m \% p} \% p$。用于计算大组合数的模。

拓展lucas定理不需要p为素数，适用性更广泛。

~~~cpp
// !!!the code here is directly copied from the Internet!!! Remember to make some changes when using this template!!!
void exgcd(ll a,ll b,ll &x,ll &y){
    if (!b) return (void)(x=1,y=0);
    exgcd(b,a%b,x,y);
    ll tmp=x;x=y;y=tmp-a/b*y;
}
inline ll INV(ll a,ll p){
    ll x,y;
    exgcd(a,p,x,y);
    return (x+p)%p;
}
inline ll lcm(ll a,ll b){
    return a/gcd(a,b)*b;
}
inline ll mabs(ll x){
    return (x>0?x:-x);
}
inline ll fast_mul(ll a,ll b,ll p) // a %= p, b %= p
inline ll fast_pow(ll a,ll b,ll p) // write yourself
inline ll F(ll n,ll P,ll PK){
    if (n==0) return 1;
    ll rou=1;//循环节
    ll rem=1;//余项 
    for (ll i=1;i<=PK;i++){
        if (i%P) rou=rou*i%PK;
    }
    rou=fast_pow(rou,n/PK,PK);
    for (ll i=PK*(n/PK);i<=n;i++){
        if (i%P) rem=rem*(i%PK)%PK;
    }
    return F(n/P,P,PK)*rou%PK*rem%PK;
}
inline ll G(ll n,ll P){
    if (n<P) return 0;
    return G(n/P,P)+(n/P);
}
inline ll C_PK(ll n,ll m,ll P,ll PK){
    ll fz=F(n,P,PK),fm1=INV(F(m,P,PK),PK),fm2=INV(F(n-m,P,PK),PK);
    ll mi=fast_pow(P,G(n,P)-G(m,P)-G(n-m,P),PK);
    return fz*fm1%PK*fm2%PK*mi%PK;
}
ll A[1001],B[1001];
//x=B(mod A)
inline ll exLucas(ll n,ll m,ll P){
    ll ljc=P,tot=0;
    for (ll tmp=2;tmp*tmp<=P;tmp++){
        if (!(ljc%tmp)){
            ll PK=1;
            while (!(ljc%tmp)){
                PK*=tmp;ljc/=tmp;
            }
            A[++tot]=PK;B[tot]=C_PK(n,m,tmp,PK);
        }
    }
    if (ljc!=1){
        A[++tot]=ljc;B[tot]=C_PK(n,m,ljc,ljc);
    }
    ll ans=0;
    for (ll i=1;i<=tot;i++){
        ll M=P/A[i],T=INV(M,A[i]);
        ans=(ans+B[i]*M%P*T%P)%P;
    }
    return ans;
}
int main(){
    ll n=read(),m=read(),P=read();
    printf("%lld\n",exLucas(n,m,P));
    return 0;
}
~~~

# number_theory-8.Miller-Rabin素性检测

Miller-Rabin为确定算法，用以在$O(T log^2 n)$的复杂度内确定一个数的素性，其中T一般取10。

~~~python
maxn = 9 # nine primes to ensure the algorithm
primes = [2, 3, 5, 7, 11, 13, 17, 19, 23]
def qpow(base, expo, MOD):
    ans = 1
    while(expo != 0):
        if(expo & 1):
            ans = ans * base % MOD
        expo >>= 1
        base = base * base % MOD
    return ans
def miller_rabin(num):
    if(num == 1):
    	return "N"
    for i in range(maxn):
        if(num == primes[i]):
        	return "Y"
        if(num < primes[i]):
        	return "N"
        expo = num-1
        res = qpow(primes[i], expo, num)
        if(res != 1):
        	return "N"
        while(res == 1 and (expo & 1) == 0):
            expo >>= 1
            res = qpow(primes[i], expo, num)
            if(res != 1 and res != num-1):
            	return "N"
    return "Y"
n = 0
while True:
    try:
        n = int(input())
        print(miller_rabin(n))
    except:
        break
~~~

# number_theory-9.其他数论定理

欧拉定理：用于降幂



// ver1.0, updated by Ness, 2019-09-17