#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
deque<int> a, ans;
bool judge()
{
	for(int i = a.size()-1;i >= 0;i--)
		if(a[i] != i+1) return false;
	return true;
}
int main()
{
	//   freopen("in.txt", "r", stdin);
	//   freopen("out.txt", "w", stdout);
	int n, temp;
	while(scanf("%d", &n) && n)
	{
		a.clear();
		ans.clear();
		for(int i = 0;i < n;i++)
		{
			scanf("%d", &temp);
			a.push_back(temp);
		}
		while(!judge())
		{
			if(a[0]%n > a[1])
			{
				ans.push_back(1);
				swap(a[0], a[1]);
			}
			else
			{
				ans.push_back(2);
				a.push_front(a[n-1]);
				a.pop_back();
			}
		}
		for(int i = ans.size()-1;i >= 0;i--)
			printf("%d", ans[i]);
		printf("\n");
	}
	return 0;
}
