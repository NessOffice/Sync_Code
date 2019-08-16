#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	int L, N, pos, minv = 0, maxv = 0;
	scanf("%d%d", &L, &N);
	while(N--)
	{
		scanf("%d", &pos);
		minv = max(minv, min(pos, L+1-pos));
		maxv = max(maxv, max(pos, L+1-pos));
	}
	printf("%d %d", minv, maxv);
	return 0;
}
