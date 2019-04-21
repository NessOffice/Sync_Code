#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 2e6;
struct Human{
	int sex; // 0 for man while 1 for woman
	int height;
	int preference; // 0 for preferring lower-height spouse
	int occupied;
}humans[MAXN];
bool cmp(const Human &lhs, const Human &rhs){return lhs.height < rhs.height;}
bool match(int i, int j)
{
	return (humans[i].sex ^ humans[j].sex) && (humans[i].preference ^ humans[j].preference);
}
int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n, m, ans = 0;
		scanf("%d%d", &n, &m);
		for(int i = 1;i <= n + m;i++)
		{
			humans[i].sex = (i <= n ? 0 : 1);
			scanf("%d", &humans[i].height);
			humans[i].occupied = 0;
		}
		for(int i = 1;i <= n + m;i++)
			scanf("%d", &humans[i].preference);

		sort(humans + 1, humans + n + m + 1, cmp);
		int can_match[2] = {1, 1};
		int j, last[2] = {0, 0};
		for(int i = 1;i < n + m && (can_match[0] || can_match[1]);i++)
		{
			if(humans[i].preference == 0) continue;
			if(humans[i].occupied == 1) continue;
			if(can_match[humans[i].sex] == 0) continue; // branch-cutting 1

			// branch-cutting 2, caution there must be last[0] and last[1]!
			for(j = max(i + 1, last[humans[i].sex]);j <= n + m;j++)
				if(match(i, j)) break;
			if(j <= n + m){
				humans[i].occupied = humans[j].occupied = 1;
				last[humans[i].sex] = j + 1;
				ans++;
			}else
				can_match[humans[i].sex] = 0;
		}
		printf("%d\n", ans);
	}
	return 0;
}
