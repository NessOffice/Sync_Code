#include <cstdio>
#include <algorithm>
const int maxn = 1e4 + 7;
int pos[maxn];
int main()
{
    int L, M, N;
    scanf("%d%d%d", &L, &N, &M);
    M = N-M+1;
    for(int i = 0;i < N;i++)
        scanf("%d", &pos[i]);
    pos[N++] = L;
    int l = 0, r = L;
    while(r > l)
    {
        int m = (l+r+1)/2, ok = 1;
        int p = 0, cnt = M;
        while(cnt-- && ok)
        {
            if()
            while(j < A && pos[j] < pos[i] + m) j++;
            if(j == A) ok = 0;
            i = j;
        }
        if(ok) l = m;
        else r = m-1;
    }
    printf("%d", l);
}
