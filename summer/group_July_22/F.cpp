#include <cstdio>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 2e4 + 5;
int n, A, a[12], ptr[maxn], mod, id_mod;
void print_ans(int k, int depth)
{
	if(k == 0){printf("%d\n", depth);return;}
	if(a[ptr[k]] > k){
		print_ans(k-a[ptr[k]]+mod, depth+4);
		printf("1 %d\n3 %d %d\n", ptr[k], ptr[k], id_mod);
		printf("2 %d\n3 %d %d\n", id_mod, ptr[k], id_mod);
	}else{
		print_ans(k-a[ptr[k]], depth+2);
		printf("1 %d\n3 %d %d\n", ptr[k], ptr[k], id_mod);
	}
}
void solve()
{
	if(a[id_mod] == A){printf("1\n1 %d\n", id_mod);return;}

	queue<int> q;
	q.push(0);
	while(!q.empty())
	{
		int num = q.front();q.pop();
		for(int i = 1;i <= n;i++)
			if(ptr[(num+a[i])%mod] == 0)
			{
				ptr[(num+a[i])%mod] = i;
				q.push((num+a[i])%mod);
			}
	}
	if(ptr[A] == 0)
		printf("-1\n");
	else
		print_ans(A, 0);
}
int main()
{
	scanf("%d%d", &n, &A);
	for(int i = 1;i <= n;i++)
	{
		scanf("%d", a+i);
		if(a[i] > mod)
			mod = a[i],
			id_mod = i;
	}
	solve();
	return 0;
}
