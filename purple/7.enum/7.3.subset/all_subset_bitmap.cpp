#include <cstdio>
#include <ctime>
//this method is a bit slower but much easier to think about
void print_subset(int n, int* bitmap, int cur)
{
	if(cur == n)
	{
		for(int i = 0;i < cur;i++)
			if(bitmap[i] != -1) printf("%d ", bitmap[i]);
		printf("\n");
	}
	else
	{
		bitmap[cur] = cur, print_subset(n, bitmap, cur+1);
		bitmap[cur] = -1, print_subset(n, bitmap, cur+1);
	}
	
}
int main()
{
	// freopen("out.txt","w",stdout);
	int n = 16, bitmap[20];
	for(int i = 0;i < n;i++) bitmap[i] = -1;
	print_subset(n, bitmap, 0);
	printf("Time used: %.3lf", (double)clock() / CLOCKS_PER_SEC);
	return 0;
}
