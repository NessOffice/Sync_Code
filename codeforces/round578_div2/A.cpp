#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 5;
int ans[12];
int main()
{
    int n, ptrL = 0, ptrR = 9;
    char cmd[maxn];
    scanf("%d", &n);
    scanf("%s", cmd);
    for(int i = 0;i < n;i++)
    {
        if(cmd[i] == 'L')
        {
            while(ptrL < 9 && ans[ptrL] == 1) ptrL++;
            ans[ptrL++] = 1;
            while(ptrL < 9 && ans[ptrL] == 1) ptrL++;
        }
        else if(cmd[i] == 'R')
        {
            while(ptrR > 0 && ans[ptrR] == 1) ptrR--;
            ans[ptrR--] = 1;
            while(ptrR > 0 && ans[ptrR] == 1) ptrR--;
        }
        else
        {
            int num = cmd[i] - '0';
            ans[num] = 0;
            if(ptrL > num) ptrL = num;
            if(ptrR < num) ptrR = num;
        }
    }
    for(int i = 0;i < 10;i++)
        printf("%d", ans[i]);
    return 0;
}
