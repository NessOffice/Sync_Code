#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <ctime>
const int maxn = 10000000;
int ran[maxn];
int main()
{
	freopen("random.txt", "w", stdout);
	int n = 1000000;
	srand(time(NULL));
	for(int i = 1;i <= n;i++)
		ran[i] = i;
	for(int i = 1;i <= n;i++)
	{
		int t = rand() % (n - i + 1) + i;
		std::swap(ran[i], ran[t]);
		printf("%d ", t);
		if(i % 20 == 0) printf("\n");
	}
	return 0;
}
