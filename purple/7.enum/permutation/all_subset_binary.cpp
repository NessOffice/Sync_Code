#include <cstdio>
#include <ctime>
//运算量貌似只有 16*65536 ≈ 1000000，但有 printf时花去 0.14s， 没有则只要 0.000s
void print_subset(int n, int bin)
{
	for(int i = 0;i < n;i++)
		if(bin & (1<<i)) printf("%d ", i);
	printf("\n");
}
int main()
{
	// freopen("out.txt","w",stdout);
	int n = 16;
	for(int bin = 0;bin < (1<<n);bin++)
		print_subset(n, bin);
	printf("Time used: %.3lf", (double)clock() / CLOCKS_PER_SEC);
	return 0;
}
