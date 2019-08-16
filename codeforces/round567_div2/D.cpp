#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL maxn = 5e5 + 5;
LL queries[maxn], records[maxn], temp_record[maxn], last_query;
LL n, m, q;
int main()
{
	memset(records, 0, sizeof(records));
    scanf("%lld%lld%lld", &n, &m, &q);
    while(n--)
    {
        LL temp;
        scanf("%lld", &temp);
        records[temp]++;
    }
    sort(records, records + m);
    
    return 0;
}
