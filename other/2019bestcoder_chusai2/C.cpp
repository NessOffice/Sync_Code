#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = (1<<21)+5;
// const int maxn = 100;
char s[maxn];
int num[maxn];
int get_mask(int n)
{
    int mask = 1;
    while((mask<<1) <= n)
        mask <<= 1;
    return mask;
}
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%s", s);
        int ans = 0, cnt = 0, lst = 0;
        for(int i = 0, len = strlen(s);i < len;i++)
        {
            if(s[i] == '^'){
                num[cnt++] = lst + 1;
                lst = 0;
            }else
                lst++;
        }
        num[cnt++] = lst + 1;
        sort(num, num + cnt, greater<int>());

        int temp = 0;
        for(int i = 0;i < cnt;i++)
            if(num[i] & 1) temp ^= 1;

        for(int i = 0;i < cnt;i++)
        {
            int mask = get_mask(num[i]);
            while(num[i])
            {
                if(ans & mask)
                {
                    num[i] = mask-1;
                    break;
                }
                ans |= mask;
                num[i] -= mask;
                mask = get_mask(num[i]);
            }
            ans |= num[i];
        }
        ans = ans - (ans & 1) + temp;
        printf("%d\n", ans);
    }
    return 0;
}
/*

???????????????????^???????????

100
?^^??^?
^?^^^?^^^^^??^^?
?^??
^^??^?^?^?^?^?
??^???^??^?^^??^^???
???^??^?^^^?^?^^^?
??^?^^^?^??^?
^
^^?^?^??
^??^?^?^??^^
??^^??^^???^^?^?
?????^
^^^
^?^?^?^^???^?????
?^^?^^^??^?^^????^^?
?^^??^^^
^^^
^^^??
^^^?^^?^?^^??^^^?
??^^^^?
???????^^^??^^??^??
^?^?^?^^??
??^^^^^
^?^?^?^?^?^?^?^
^^^???^??^??
^?^^??^^?
??^^
^????^^
??^?
?^?
^?^^
^^???^??^^?^?^^?^??
???^??^
^
^???^
^^???^?^?^^^?^??^^?^
^^?^???
^?^????^?^
^?^??^
^?^
?^^?^^^^^??^^^^^
??????^?^?^??^^????
^^^^???^?
?^???
^^?^????
?^?^?^^?^^
^^^^^^^
????^??^^^^?
??^^?^^?^?
????^^??^?^?^?^?^^^^
^^^?^?^?^
?^^^^?
^^??^
^??^??????^??^
^^?^?^^^^^^^??^
^^^????^^?^?^^^??^^
^^?^^?^??^??
???^??^^?????^??^
??^??????^?^?^^
?
?^?^???^^^^^
^??^?^?^^?^^^??^??
^??^^^
?^^^^^^?^??
^^
^^?^^
??^^?^^^?^^^????^?^?
????^??^?^
^?
^?^?^?^^?^^^
^^^^??^^?^
^^^^^?^^^?
^???
?^^
^??^?^^??^^
??^?^?^?^
?^?^?^^^?^
?
??????^?^??^^?^?^^
^^^
???^
^
^^?^?^^
???^^??^?^???
?^^^?^^^?^^?
?^^^?^?^?????
^^?^??^^^???^^???^^?
^^^^^?^???^^?
???^
?^^
?^?^^^^??
????^^^?^^??^?^^
????^??^^^^??^
^^?^^^??^?
???^???
^?^?
^?^^?????^?^??^?^^
^^^
^?^^^?
^^^?^???^^?^^????^?

100
???????
^^^
???^???
?
??
^^
*/