#include <cstdio>
#include <cstring>
const int maxn = 1e6 + 5;
int n, ans, tot, P[maxn], sum[maxn];
bool isP[maxn];
void SiftPrime(int m)
{
	memset(isP,true,sizeof(isP));
	memset(P,0,sizeof(P));
	isP[0] = false;
	isP[1] = false;
    sum[0] = sum[1] = tot = 0;
	for(int i = 2;i <= m;i++)
    {
		if(isP[i]) P[tot++] = i;
        sum[i] = sum[i-1] + isP[i];
		for(int j = 0;j < tot && i*P[j] <= m;j++)
        {
			isP[i*P[j]] = false;
			if(!(i%P[j])) break;
		}
	}
}
int main()
{
    int n, m, l, r;
    SiftPrime(maxn);
    scanf("%d%d", &n, &m);
    while(n--)
    {
        scanf("%d%d", &l, &r);
        if(l < 1 || r > m || l > r)
            printf("Crossing the line\n");
        else printf("%d\n", sum[r]-sum[l-1]);
    }
}
