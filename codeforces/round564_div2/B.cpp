#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
    int n, r[2000], c[2000], r_now = 0, c_now = 1, m = 1; // caution!
    scanf("%d", &n);
    for(int i = 1;i <= n;i++)
    {
        if(i & 1)
            r_now++;
        else
            c_now++,
            m++;
        r[i] = r_now;
        c[i] = c_now;
    }
    printf("%d\n", m);
    for(int i = 1;i <= n;i++)
        printf("%d %d\n", r[i], c[i]);
    return 0;
}