#include <cstdio>
#include <set>
using namespace std;
const int maxn = 1000000 + 5;
int ans, n, len, num[maxn];
int main()
{
//	 freopen("in.txt", "r", stdin);
//	 freopen("out.txt", "w", stdout);
	set<int> s;
	scanf("%d", &n);
	while(n--)
	{
		s.clear();
		scanf("%d", &len);
		for(int i = 0;i < len;i++)
			scanf("%d", &num[i]);
		int L, R;
		L = R = ans = 0;
		while(R < len)
		{
			while(R < len && !s.count(num[R])) s.insert(num[R++]);
			if(R-L > ans) ans = R-L;
			s.erase(num[L++]);
		}
		printf("%d\n", ans);
	}
	return 0;
}
