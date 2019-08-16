#include <cstdio>
#include <cstring>
typedef long long LL;
LL n, root[32][32], score[32][32], a[32], first = 0;
LL calc(LL l, LL r)
{
    if(r < l) return 1;
    if(score[l][r] != -1) return score[l][r];
    LL ans = 0;
    for(LL i = l;i <= r;i++)
    {
        LL temp = a[i] + calc(l, i-1) * calc(i+1, r);
        if(i-1 < l && r < i+1) temp--;//leaf
        if(temp > ans)
        {
            ans = temp;
            root[l][r] = i;
        }
    }
    return score[l][r] = ans;
}
void preOrder(LL l, LL r)
{
    if(r < l) return;
    LL m = root[l][r];
    if(first++) putchar(' ');
    printf("%lld", m);
    preOrder(l, m-1);
    preOrder(m+1, r);
}
int main()
{
    memset(score, -1, sizeof(score));
    scanf("%lld", &n);
    for(LL i = 1;i <= n;i++)
        scanf("%lld", &a[i]);
    printf("%lld\n", calc(1, n));
    preOrder(1, n);
	return 0;
}
