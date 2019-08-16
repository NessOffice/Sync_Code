#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 2e5+5;
char s[maxn], t[maxn];
int match[2][maxn];
int main()
{
    scanf("%s", s+1);
    scanf("%s", t+1);
    int len_s = strlen(s+1), len_t = strlen(t+1);
    int ans = 0, j = 1;
    for(int i = 1;i <= len_s;i++)
        if(s[i] == t[j])
            match[0][j++] = i;
    j = len_t;
    match[1][len_t+1] = len_s+1;
    for(int i = len_s;i >= 1;i--)
        if(s[i] == t[j])
            match[1][j--] = i;
    for(int i = 0;i <= len_t;i++)
        ans = max(ans, match[1][i+1] - match[0][i] - 1);
    printf("%d", ans);
    return 0;
}
