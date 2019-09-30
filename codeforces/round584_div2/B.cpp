#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL maxn = 1e5+5;
char state_str[200];
bool state[200];
int a[200], b[200];
int main()
{
    int n, cnt = 0;
    scanf("%d", &n);
    scanf("%s", state_str);
    for(int i = 0, len = strlen(state_str);i < len;i++)
        state[i] = (state_str[i] == '1');
    for(int i = 0;i < n;i++)
        scanf("%d%d", &a[i], &b[i]);
    return 0;
}