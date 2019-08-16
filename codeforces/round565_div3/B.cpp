#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
    int T, n, num[3];
    scanf("%d", &T);
    while(T--)
    {
        num[0] = num[1] = num[2] = 0;
        scanf("%d", &n);
        while(n--)
        {
            int temp;
            scanf("%d", &temp);
            num[temp % 3]++;
        }
        while(num[1] && num[2])
        {
            num[0]++;
            num[1]--;
            num[2]--;
        }
        while(num[1] >= 3)
        {
            num[1] -= 3;
            num[0]++;
        }
        while(num[2] >= 3)
        {
            num[2] -= 3;
            num[0]++;
        }
        printf("%d\n", num[0]);
    }
    return 0;
}