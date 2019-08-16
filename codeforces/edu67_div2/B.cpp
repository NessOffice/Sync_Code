#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long LL;
const int maxn = 2e5 + 5;
using namespace std;
int place[maxn][26], occurence[26], cnt[26];
int main()
{
    char temp[maxn];
    int n;
    scanf("%d", &n);
    scanf("%s", temp);
    for(int i = 0;i < n;i++)
    {
        int ch = temp[i] - 'a';
        place[++occurence[ch]][ch] = i+1;
    }
    int m;
    scanf("%d", &m);
    while(m--)
    {
        scanf("%s", temp);
        memset(cnt, 0, sizeof(cnt));
        for(int i = strlen(temp)-1;i >= 0;i--)
        {
            int ch = temp[i] - 'a';
            cnt[ch]++;
        }
        int ans = 0;
        for(int j = 0;j < 26;j++)
            ans = max(ans, place[cnt[j]][j]);
        printf("%d\n", ans);
    }
    return 0;
}