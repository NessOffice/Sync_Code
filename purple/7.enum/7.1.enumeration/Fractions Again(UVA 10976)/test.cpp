#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	// freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	int k;
	while(~scanf("%d", &k))
	{
		int cnt = 0;
		for(int d = 1;d <= k;d++) if((k*k) % d == 0) cnt++;
		printf("%d\n", cnt);
		for(int d = 1;d <= k;d++)
			if((k*k) % d == 0) printf("1/%d = 1/%d + 1/%d\n", k, (k+d)*k/d, k+d);
	}
	return 0;
}
