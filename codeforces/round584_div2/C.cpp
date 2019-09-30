#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL maxn = 2e5+5;
char digit[maxn];
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int len;
        scanf("%d", &len);
        scanf("%s", digit);
        int ok = -1;
        for(int big = 0;big <= 9 && ok == -1;big++)
        {
            int sta[2] = {0, big};
            bool maybe_ok = true;
            for(int i = 0;i < len && maybe_ok;i++)
            {
                int num = digit[i] - '0';
                if(num >= big && sta[1] <= num){
                    if(sta[1] > num)
                        maybe_ok = false;
                    else
                        sta[1] = num;
                }else{
                    if(sta[0] > num || num > big)
                        maybe_ok = false;
                    else
                        sta[0] = num;
                }
            }
            if(maybe_ok) ok = big;
        }
        if(ok == -1){
            printf("-\n");
        }else{
            int sta[2] = {0, ok};
            for(int i = 0;i < len;i++)
            {
                int num = digit[i] - '0';
                if(num >= ok && sta[1] <= num){
                    if(sta[1] <= num)
                        sta[1] = num;
                    putchar('2');
                }else{
                    putchar('1');
                }
            }
            putchar('\n');
        }
    }
    return 0;
}
