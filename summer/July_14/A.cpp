#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
const int maxn = 1e5+5;
int sum[maxn], ans[maxn], jmp[maxn];
map<int, int> last;
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        last.clear();
        int n;
        scanf("%d", &n);
        for(int i = 0;i <= n;i++)
            jmp[i] = ans[i] = 0;
        sum[0] = 0;
        for(int i = 1;i <= n;i++)
        {
            int ai;
            scanf("%d", &ai);
            sum[i] = sum[i-1] ^ ai;
            if(sum[i] == 0)
                ans[i]++;
            if(last.count(sum[i]))
            {
                int j = i;
                jmp[i] = last[sum[i]];
                while(j)
                {
                    if(jmp[j])
                        ans[i-jmp[j]]++;
                    j = jmp[j];
                }
            }
            last[sum[i]] = i;
        }
        for(int i = 1;i <= n;i++)
            printf("%d%c", ans[i], i == n ? '\n' : ' ');
    }
    return 0;
}
/*
2

5
3 3 1 2 3

6
3 3 1 2 3 3
*/