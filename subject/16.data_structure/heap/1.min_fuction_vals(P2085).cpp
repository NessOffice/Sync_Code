#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pr;
const int maxn = 1e4+5;
int A[maxn], B[maxn], C[maxn], x[maxn];
struct cmp{bool operator()(const pr lhs, const pr rhs){return lhs.second > rhs.second;}};
int f(int i){return A[i]*x[i]*x[i] + B[i]*x[i] + C[i];}
int main()
{
	priority_queue<pr, vector<pr>, cmp> q;
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0;i < n;i++)
	{
		scanf("%d%d%d", A+i, B+i, C+i);
		x[i] = 1;
		q.push(make_pair(i, f(i)));
	}
	while(m--)
	{
		printf("%d ", q.top().second);
		int index = q.top().first;
		q.pop();
		x[index]++;
		q.push(make_pair(index, f(index)));
	}
	return 0;
}
