#include <cstdio>
#define MAXN 100010
void swap_int(int num[], int i1, int i2)
{
	int t = num[i1];
	num[i1] = num[i2];
	num[i2] = t;
}
void quick_sort(int num[], int begin, int end)
{
	if(begin >= end-1) return;
	int m = begin, l = begin, r = end-1;
	while(r >= l)
	{
		while(num[r] >= num[m]) r--;
		if(r > m){swap_int(num, m, r);m = r;}
		while(num[l] <= num[m]) l++;
		if(l < m){swap_int(num, m, l);m = l;}
	}
	quick_sort(num, begin, m);
	quick_sort(num, m+1, end);
}
int main()
{
	int n, num[MAXN];
	scanf("%d",&n);
	for(int i = 0;i < n;i++)
		scanf("%d",&num[i]);
	quick_sort(num, 0, n);
	printf("%d", num[0]);
	for(int i = 1;i < n;i++)
		printf(" %d",num[i]);
	printf("\n");
	return 0;
}
