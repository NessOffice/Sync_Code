#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
typedef long long LL;
int main()
{
    int n, M;
    priority_queue<int, vector<int>, greater<int> > q_big;
    priority_queue<int> q_small;
    scanf("%d%d", &n, &M);
    int sum = 0, del = 0;
    for(int i = 0;i < n;i++)
    {
        int t;
        scanf("%d", &t);
        
        while(sum > M - t)
        {
            q_big.push(q_small.top());
            sum -= q_small.top();
            q_small.pop();
            del++;
        }
        while(!q_big.empty() && sum + q_big.top() <= M - t)
        {
            q_small.push(q_big.top());
            sum += q_big.top();
            q_big.pop();
            del--;
        }
        sum += t;
        q_small.push(t);
        printf("%d ", del);
    }
    return 0;
}
