#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 1e5+5;
bool isP[maxn];
int P[maxn];
int total = 0;
void sift()
{
	memset(isP, true, sizeof(isP));
	memset(P, 0, sizeof(P));
	isP[0] = isP[1] = false;
	for(int i = 2;i <= maxn;i++)
	{
		if(isP[i]) P[++total]=i;
		for(int j = 1;j <= total && i*P[j] <= maxn;j++)
		{
			isP[i*P[j]]=false;
			if(!(i%P[j])) break;
		}
	}
}
int num[maxn];
bool vis[maxn];
int main()
{
    sift();
    int n, ans = 0, lst, ths;
    scanf("%d", &n);
    for(int i = 1;P[i] <= n;i++)
    {
        ths = P[i]*P[i+1];
        for(int j = 1;j*P[i] <= n;j++)
        {
            if(j == P[i-1]) continue;
            if(j == P[i+1]) continue;
            if(vis[j*P[i]] == false) num[ans++] = j*P[i];
            vis[j*P[i]] = true;
        }
        if(ths <= n && vis[ths] == false) num[ans++] = ths;
        else break;
    }
    printf("%d\n", ans-1);
    for(int i = 0;i < ans;i++)
        printf("%d%c", num[i], i == ans-1 ? '\n' : ' ');
    return 0;
}