#include <cstdio>
const int maxn = 100000+10;
int main()
{
    int L, R, ban[10];
    while(scanf("%d%d", &L, &R))
    {
        if(L == 0 && R == 0) break;
        int cnt = 0;
        for(int i = L;i <= R;i++)
        {
            for(int j = 0;j < 10;j++) ban[j] = 0;
            int temp = i, ok = 1, digit;
            while(temp && ok)
            {
                digit = temp % 10;
                if(ban[digit]) ok = 0;
                ban[digit] = 1;
                temp /= 10;
            }
            if(ok) cnt++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}