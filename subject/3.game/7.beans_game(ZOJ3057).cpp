#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 301;
bool SG[maxn][maxn][maxn];
void calc_SG(int n) // stgy for strategy
{
	memset(SG, 0, sizeof(SG));
	SG[0][0][0] = 0;
	for(int i1 = 0;i1 < n;i1++)
	for(int i2 = 0;i2 < n;i2++)
	for(int i3 = 0;i3 < n;i3++)
	{
		if(SG[i1][i2][i3]) continue;
		for(int j = i1+1;j < n;j++)
			SG[j][i2][i3] = true;
		for(int j = i2+1;j < n;j++)
			SG[i1][j][i3] = true;
		for(int j = i3+1;j < n;j++)
			SG[i1][i2][j] = true;
		for(int j = min(n-i1, n-i2)-1;j > 0;j--)
			SG[i1+j][i2+j][i3] = true;
		for(int j = min(n-i1, n-i3)-1;j > 0;j--)
			SG[i1+j][i2][i3+j] = true;
		for(int j = min(n-i3, n-i2)-1;j > 0;j--)
			SG[i1][i2+j][i3+j] = true;
	}
}
int main()
{
	calc_SG(maxn);
	int n1, n2, n3;
	while(scanf("%d%d%d", &n1, &n2, &n3) == 3)
		printf("%d\n", SG[n1][n2][n3]);
	return 0;
}
