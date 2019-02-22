#include <cstdio>
#include <map>
using namespace std;
const int maxn = 200000 + 10;
map<int, int> lhs;
map<int, int> rhs;
int T, n, A[maxn];
int last[maxn], nex[maxn];
void init()
{
	lhs.clear();
	rhs.clear();
	for(int i = 0;i < n;i++)
	{
		int j = n-1-i;
		if(!lhs.count(A[i])) last[i] = -1;
		else last[i] = lhs[A[i]];
		if(!rhs.count(A[j])) nex[j] = n;
		else nex[j] = rhs[A[j]];
		lhs[A[i]] = i;
		rhs[A[j]] = j;
	}
}
bool judge(int l, int r)
{
	if(r <= l+1) return true;
	for(int d = 0;l+d <= r-1-d;d++)
	{
		// printf("%d %d\n", last[i], nex[i]);
		if(last[l+d] < l && nex[l+d] >= r)
		return judge(l, l+d) && judge(l+d+1, r);
		if(last[r-1-d] < l && nex[r-1-d] >= r)
		return judge(l, r-1-d) && judge(r-d, r);
	}
	return false;
}
int main()
{
//	      freopen("in.txt", "r", stdin);
//	      freopen("out.txt", "w", stdout);
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for(int i = 0;i < n;i++)
			scanf("%d", &A[i]);
		init();
		if(judge(0, n)) printf("non-");
		printf("boring\n");
	}
	return 0;
}
