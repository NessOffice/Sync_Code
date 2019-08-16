#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 205;
char s[maxn], t[maxn];
int main()
{
    scanf("%s", s);
    scanf("%s", t);
    int len_s = strlen(s), len_t = strlen(t);
    int ans = len_s - len_t;
    for(;ans;ans--)
    {
        bool match = false;
        for(int st = 0;st <= len_s - ans && match == false;st++)
        {
            int j = 0;
            for(int i = 0;i < len_s && match == false;i++)
            {
                if(i == st){i = st+ans-1;continue;}
                if(s[i] == t[j]) j++;
                if(j == len_t) match = true;
            }
        }
        if(match) break;
    }
    printf("%d", ans);
    return 0;
}
