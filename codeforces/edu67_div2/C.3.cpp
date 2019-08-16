#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long LL;
const int maxn = 1e3 + 5;
using namespace std;
int L[maxn], R[maxn], cnt;
int mark[maxn], num[maxn];
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0;i < m;i++)
    {
        int t, l, r;
        scanf("%d%d%d", &t, &l, &r);
        if(t)
            for(int i = l;i < r;i++) mark[i] = 1;
        else
            {L[cnt] = l;R[cnt] = r;cnt++;}
    }
    num[1] = maxn;
    for(int i = 2;i <= n;i++)
    {
        num[i] = num[i-1];
        if(mark[i-1] == 0)
            num[i]--;
    }
    bool flag = true;
    for(int i = 0;i < cnt && flag;i++)
        if(num[L[i]] == num[R[i]]) flag = false;
    printf("%s\n", flag ? "YES" : "NO");
    if(flag)
    for(int i = 1;i <= n;i++)
        printf("%d ", num[i]);
    return 0;
}
