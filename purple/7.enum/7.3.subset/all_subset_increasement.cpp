#include <cstdio>
#include <cstring>
#include <ctime>
//my computer can deal about 0.4 billion commands per sec
//when n equals 16(2^16 = 65536), this program also demands 1 second
void print_subset(int n, int* A, int cur)
{
	for(int i = 0;i < cur;i++)
		printf("%d ", A[i]);
	printf("\n");
	int s = cur ? A[cur-1]+1 : 0;
	for(int i = s;i < n;i++)
	{
		A[cur] = i;
		print_subset(n, A, cur+1);
	}
}
int main()
{
	// freopen("out.txt","w",stdout);
	int n = 16, A[20];
	for(int i = 0;i < 3;i++) A[i] = i;
	print_subset(n, A, 0);
	printf("Time used: %.3lf", (double)clock() / CLOCKS_PER_SEC);
	return 0;
}
