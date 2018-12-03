#include <cstdio>
using namespace std;
const int maxn = 100000 + 5;
int l[maxn], r[maxn];
void link(int L, int R)
{
	l[R] = L, r[L] = R;
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n, m, kase = 1, rev = 0;
	long long sum = 0;
	while(scanf("%d%d", &n, &m) == 2)
	{
		for(int i = 1;i <= n;i++)
		{
			l[i] = i - 1;
			r[i] = i + 1;
		}
		r[n] = 0, l[0] = n, r[0] = 1;
		int cmd, X, Y;
		while(m--)
		{
			scanf("%d", &cmd);
			if(cmd == 4) rev = 1 - rev;
			else
			{
				scanf("%d%d", &X, &Y);
				if(rev && cmd != 3) cmd = 3 - cmd;
				if(cmd == 3 && r[Y] == X){int t = X;X = Y;Y = t;}
				if(cmd == 1 && X == l[Y]) continue;
				if(cmd == 2 && X == r[Y]) continue;
				int LX, LY, RX, RY;
				RX = r[X], LX = l[X];
				RY = r[Y], LY = l[Y];
				if(cmd == 3)
				{
					link(LX, Y);
					link(X, RY);
					if(RX == Y) link(Y, X);
					else
					{
						link(Y, RX);
						link(LY, X);
					}
				}
				if(cmd == 1)
				{
					link(LX, RX);
					link(X, Y);
					link(LY, X);
				}
				if(cmd == 2)
				{
					link(LX, RX);
					link(Y, X);
					link(X, RY);
				}
			}
		}
		int node = 0;
		for(int i = 1;i <= n;i++)
		{
			node = r[node];
			if(i % 2 && (!rev || n % 2)) sum += node;
			else if(i % 2 == 0 && n % 2 == 0 && rev) sum += node;
//			printf("%d ", node);
		}
		printf("Case %d: %lld\n", kase++, sum);
		rev = 0, sum = 0;
	}
	return 0;
}
