#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 1e6 + 5;
char word_first[maxn], word_second[maxn];
int main()
{
    int n;
    scanf("%d", &n);
    while(n--)
    {
        bool flag = true;
        scanf("%s", word_first);
        scanf("%s", word_second);
        int i1 = 0, i2 = 0;
        while(flag)
        {
            if(word_first[i1] == '\0')
            {
                if(word_second[i2] != '\0')
                    flag = false;
                break;
            }
            if(word_second[i2] == '\0'){flag = false;break;}
            char ch1 = word_first[i1], ch2 = word_second[i2];
            if(ch1 != ch2){flag = false;break;}
            int len1 = 0, len2 = 0;
            while(word_first[i1] && word_first[i1] == ch1){i1++;len1++;}
            while(word_second[i2] && word_second[i2] == ch2){i2++;len2++;}
            if(len2 < len1) flag = false;
        }
        printf("%s\n", flag ? "YES" : "NO");
    }
    return 0;
}
