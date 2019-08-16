#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL maxn = 1e5 + 5;
char s[2][maxn];
int lft[2][maxn], rgt[2][maxn]; // lft[1][] for the filpped situation
int n, k;
int main()
{
    scanf("%d%d", &n, &k);
    scanf("%s", s[0]+1);
    int len = strlen(s[0]+1);
    for(int i = 1;i <= len;i++)
        s[1][i] = (1^(s[0][i]- '0')) + '0';
    for(int i = 1;i < maxn;i++)
        rgt[0][i] = rgt[1][i] = len+1;
    for(int flip = 0;flip < 2;flip++)
    {
        int ptrl = 1, ptrr = len;
        for(int i = 1;i <= len;i++)
            if(s[flip][i] == '0')
                while(ptrl <= i)
                    rgt[flip][ptrl++] = i;
        for(int i = len;i >= 0;i--)
            if(s[flip][i] == '0')
                while(ptrr >= i)
                    lft[flip][ptrr--] = i;
    }
    int ans = -1;
    if(lft[0][n] - rgt[0][1] <= k - 1 || lft[1][n] - rgt[1][1] <= k - 1) ans = 1;
    if(ans == -1)
    {
        bool lose = true;
        for(int flip = 0;flip < 2;flip++)
            for(int i = 1;i <= n-k+1 && lose;i++)
            {
                if(lft[flip][i-1] && rgt[flip][i+k] != len+1) lose = false;
                if(lft[flip][n] - rgt[flip][i+k] >= k) lose = false;
                if(lft[flip][i-1] - rgt[flip][1] >= k) lose = false;
            }
        if(lose) ans = 0;
    }
    if(ans == 1) printf("tokitsukaze");
    if(ans == 0) printf("quailty");
    if(ans == -1) printf("once again");
    return 0;
}
