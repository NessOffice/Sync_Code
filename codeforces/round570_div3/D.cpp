#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
typedef long long LL;
const int maxn = 2e5 + 5;
map<int, int> id;
int q, n, cnt[maxn], id_cnt;
int main()
{
    scanf("%d", &q);
    while(q--)
    {
        id_cnt = 0;
        id.clear();
        scanf("%d", &n);
        for(int i = 0;i < n;i++)
            cnt[i] = 0;
        for(int i = 0;i < n;i++)
        {
            int temp;
            scanf("%d", &temp);
            if(id.count(temp) == 0)
                id[temp] = id_cnt++;
            cnt[id[temp]]++;
        }
        sort(cnt, cnt+id_cnt);
        int ans = 0, last = cnt[id_cnt-1];
        for(int i = id_cnt-1;i >= 0 && last > 0;i--)
        {
            if(last > cnt[i])
                last = cnt[i];
            ans += last;
            last--;
        }
        printf("%d\n", ans);
    }
    return 0;
}
