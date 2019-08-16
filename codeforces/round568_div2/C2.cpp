#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 2e5 + 5;
int main()
{
    int n, M, num[120], sum = 0, t, del1 = 0;
    memset(num, 0, sizeof(num));
    scanf("%d%d", &n, &M);
    for(int i = 0;i < n;i++)
    {
        int del2 = 0;
        scanf("%d", &t);
        if(sum > M)
        {
            for(int j = 100;j > 0;j--)
            {
                if(sum - num[j] * j <= M){
                    int temp_num = (sum - M - 1) / j + 1;
                    sum -= temp_num * j;
                    del1 += temp_num;
                    num[j] -= temp_num;
                    break;
                }else{
                    sum -= num[j] * j;
                    del1 += num[j];
                    num[j] = 0;
                }
            }
        }

        if(sum > M - t)
        {
            int sum_temp = sum;
            for(int j = 100;j > 0;j--)
            {
                if(sum_temp - num[j] * j <= M - t){
                    int temp_num = (sum_temp - (M - t) - 1) / j + 1;
                    sum_temp -= temp_num * j;
                    del2 += temp_num;
                    break;
                }else{
                    sum_temp -= num[j] * j;
                    del2 += num[j];
                }
            }
        }
        sum += t;
        num[t]++;
        printf("%d ", del1 + del2);
    }
    return 0;
}
