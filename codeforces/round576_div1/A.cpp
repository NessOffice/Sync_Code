#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 4e5 + 5;
int n, I, k, del = (1 << 30), sum[maxn];
map<int, int> occ;
int main()
{
    scanf("%d%d", &n, &I);
    k = 8 * I / n;
    k = k > 30 ? (1 << 30) : (1 << k);
    for(int i = 0;i < n;i++)
    {
        int temp;
        scanf("%d", &temp);
        occ[temp]++;
    }
    int cnt = 1;
    for(map<int, int>::iterator iter = occ.begin();iter != occ.end();iter++, cnt++)
        sum[cnt] = sum[cnt-1] + iter->second;
    if(k >= cnt) del = 0;
    for(int i = k;i < cnt;i++)
        del = min(del, n - (sum[i] - sum[i-k]));
    printf("%d", del);
    return 0;
}
