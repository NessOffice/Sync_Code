#include <iostream>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        unsigned long long n, m, m0, ans, cnt;
        cnt = 1;
        ans = 0;
        cin>>n>>m;
        m0 = m;
        while(m0)
        {
            if((n & 1) == 0 && ans + cnt <= m) ans += cnt;
            cnt <<= 1, n >>= 1, m0 >>= 1;
        }
        cout<<ans<<endl;
    }
    return 0;
}