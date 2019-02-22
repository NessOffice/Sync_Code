#include <cstdio>
#include <cstring>
const int maxn = 40000 + 5;
int n, ans, tot, P[maxn], phi[maxn];
bool isP[maxn];
void SiftPrime(int m)
{
	memset(isP,true,sizeof(isP));
	memset(P,0,sizeof(P));
	isP[0] = false;
	isP[1] = false;
    tot = 0;
	for(int i = 2;i <= m;i++)
    {
		if(isP[i]) P[tot++] = i;
		for(int j = 0;j < tot && i*P[j] <= m;j++)
        {
			isP[i*P[j]] = false;
			if(!(i%P[j])) break;
		}
	}
    for(int i = 1;i < m;i++) phi[i] = i;
    for(int i = 0;i < tot;i++)
    for(int j = 1;P[i]*j < m;j++)
        phi[P[i]*j] = phi[P[i]*j]*(P[i]-1)/P[i];
}
int main()
{
    int n, ans = 0;
    SiftPrime(maxn);
    scanf("%d", &n);
    for(int i = 1;i < n;i++)
        ans += phi[i];
    if(ans > 1) ans = 2*ans+1;
    printf("%d\n", ans);
}
