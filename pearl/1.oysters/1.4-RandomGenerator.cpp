#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <ctime>
const int maxn = 10000000;
int ran[maxn];
int main()
{
	freopen("random.txt", "w", stdout);
	int n = 100000;
	srand(time(NULL));
	for(int i = 1;i <= n;i++)
		ran[i] = i;
	for(int i = 1;i <= n;i++)
	{
		int t = rand() % (n - i + 1) + i;
		std::swap(ran[i], ran[t]);
		if(i % 2) printf("%d ", ran[i]);
		if(i % 40 == 0) printf("\n");
	}
	return 0;
}
