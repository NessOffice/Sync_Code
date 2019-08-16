#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long LL;
const int maxn = 105;
using namespace std;
char s[maxn], t[maxn], p[maxn];
int store[26];
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        bool ok = true;
        for(int i = 0;i < 26;i++)
            store[i] = 0;
        scanf("%s%s%s", s, t, p);
        int ptr_t = 0, len_t = strlen(t), len_s = strlen(s);
        for(int ptr_s = 0;ptr_s < len_s;ptr_s++)
        {
            while(ptr_t < len_t && t[ptr_t] != s[ptr_s])
            {
                store[t[ptr_t]-'a']++;
                ptr_t++;
            }
            if(ptr_t >= len_t){ok = false;break;}
            ptr_t++;
        }
        while(ptr_t < len_t){store[t[ptr_t]-'a']++;ptr_t++;}
        if(ok)
        for(int ptr_p = 0, len_p = strlen(p);ptr_p < len_p;ptr_p++)
            store[p[ptr_p]-'a']--;
        for(int i = 0;i < 26;i++)
            if(store[i] > 0) ok = false;
        printf("%s\n", ok ? "YES" : "NO");
    }
    return 0;
}
