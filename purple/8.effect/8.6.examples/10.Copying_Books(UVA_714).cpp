#include <cstdio>
#include <cstring>
const int maxn = 500 + 10;
int m, k, data[maxn], mark[maxn];
bool copy(int limit, bool ok)
{
	int d = k-1, sum = 0;
	for(int i = m-1;i >= 0;i--)
	{
		if(d > i && data[i] <= limit)
		{
			d--, sum = 0;
			if(ok) mark[i] = 1;
		}
		if(sum + data[i] > limit)
		{
			if(d)
			{
				if(data[i] > limit) return false;
				d--, sum = data[i];
				if(ok) mark[i] = 1;
			}
			else return false;
		}
		else sum += data[i];
	}
	return true;
}
void divide(int l, int r)
{
	while(1)//Will it fall in an endless loop?
	{
		int mid = (l+r)/2;
		if(copy(mid, 0) && !copy(mid-1, 0))
		{
			copy(mid, 1);
			for(int i = 0;i < m;i++)
			{
				printf("%d", data[i]);
				if(i < m-1) putchar(' ');
				if(mark[i]) printf("/ ");
			}
			printf("\n");
			return;
		}
		if(copy(mid, 0)) r = mid;
		else l = mid+1;
	}
}
int main()
{
	//   freopen("in.txt", "r", stdin);
	//   freopen("out.txt", "w", stdout);
	int T, total;
	scanf("%d", &T);
	while(T--)
	{
		memset(mark, 0, sizeof(mark));
		total = 0;
		scanf("%d%d", &m, &k);
		for(int i = 0;i < m;i++)
		{
			scanf("%d", &data[i]);
			total += data[i];
		}
		divide(0, total);
	}
	return 0;
}
