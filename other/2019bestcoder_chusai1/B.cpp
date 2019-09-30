#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 1e3 + 5;
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n, ans = 0, a_now, b_now, a_nxt, b_nxt;
        scanf("%d", &n);
        scanf("%d%d", &a_now, &b_now);
        for(int i = 1;i < n;i++)
        {
            scanf("%d%d", &a_nxt, &b_nxt);
            if(b_nxt <= b_now && a_nxt >= a_now)
            {
                a_now = a_nxt;
                b_now = b_nxt;
                continue;
            }
            if(a_now >= a_nxt && b_now <= b_nxt)
                continue;
            if(a_now < a_nxt && b_now < b_nxt && b_now >= a_nxt)
            {
                a_now = a_nxt;
                continue;
            }
            if(a_nxt < a_now && b_nxt < b_now && a_now <= b_nxt)
            {
                b_now = b_nxt;
                continue;
            }
            if(b_now < a_nxt)
            {
                int step = (a_nxt-b_now+1)/2;
                ans += step;
                a_now = a_nxt;
                if(((a_nxt-b_now) & 1) && (b_nxt != a_nxt)) b_now = a_nxt+1;
                else b_now = a_nxt;
                continue;
            }
            if(b_nxt < a_now)
            {
                int step = (a_now-b_nxt+1)/2;
                ans += step;
                b_now = b_nxt;
                if(((a_now-b_nxt) & 1) && (b_nxt != a_nxt)) a_now = b_nxt-1;
                else a_now = b_nxt;
                continue;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
/*
2
6
1 2
3 3
3 4
4 4
5 6
7 7
2
1 10
20 30
*/