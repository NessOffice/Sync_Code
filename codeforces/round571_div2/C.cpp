#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 1e6 + 5;
char str1[maxn], str2[maxn];
int delta[maxn];
int main()
{
    scanf("%s%s", str1, str2);
    int len1 = strlen(str1), len2 = strlen(str2);
    for(int i = 1;i < len1;i++)
        delta[i] = delta[i-1] + (str1[i] != str1[i-1] ? 1 : 0);
    int ans = 0, cnt = 0;
    for(int i = 0;i < len2;i++)
        if(str1[i] != str2[i]) cnt++;
    if(cnt % 2 == 0) ans++;
    for(int i = len2;i < len1;i++)
    {
        cnt += (delta[i] - delta[i-len2]);
        if(cnt % 2 == 0) ans++;
    }
    printf("%d", ans);
    return 0;
}
