#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pr;
const int maxn = 1e5+5;
int A[maxn], B[maxn], f[maxn]; // A[i] + B[f[i]]
struct cmp{bool operator()(const pr lhs, const pr rhs){return lhs.second > rhs.second;}};
int main()
{
	priority_queue<pr, vector<pr>, cmp> q;
	int n;
	scanf("%d", &n);
	for(int i = 0;i < n;i++)
		scanf("%d", A+i);
	for(int i = 0;i < n;i++)
	{
		f[i] = 0;
		scanf("%d", B+i);
		q.push(make_pair(i, A[i]+B[0]));
	}
	for(int i = 0;i < n;i++)
	{
		int index, val;
		index = q.top().first;
		val = q.top().second;
		q.pop();
		printf("%d ", val);
		val -= B[f[index]];
		f[index]++;
		if(f[index] < n)
			q.push(make_pair(index, val + B[f[index]]));
	}
	return 0;
}
