#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 5e4+5;
int sum_mu[maxn], mu[maxn];
bool isP[maxn];
int P[maxn];
int total = 0;
int k;
void calc_mu()
{
	memset(isP, true, sizeof(isP));
	memset(P, 0, sizeof(P));
	isP[0] = isP[1] = false;
    mu[1] = 1;
	for(int i = 2;i <= maxn;i++)
	{
		if(isP[i])
        {
            P[++total]=i;
            mu[i] = -1;
        }
		for(int j = 1;j <= total && i*P[j] < maxn;j++)
		{
			isP[i*P[j]] = false;
			if(!(i%P[j])) break;
            else mu[i*P[j]] = -mu[i];
		}
	}
    for(int i = 1;i < maxn;i++)
        sum_mu[i] = sum_mu[i-1] + mu[i];
}
int solve(int upper1, int upper2)
{
    int ans = 0;
    for(register int l = 1, r;l <= min(upper1, upper2);l = r+1)
    {
        r = min(upper1/(upper1/l), upper2/(upper2/l));
        ans += (upper1/(l*k))*(upper2/(l*k))*(sum_mu[r] - sum_mu[l-1]);
    }
    return ans;
}
int main()
{
    calc_mu();
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int a, b, c, d;
        scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
        printf("%d\n", solve(b, d) - solve(a-1, d) - solve(b, c-1) + solve(a-1, c-1));
    }
    return 0;
}
