#include <cstdio>
#include <algorithm>
using namespace std;
#define MAXN 100010
int num[MAXN];
void quick_sort(int begin, int end)
{
	if(begin >= end) return;
	int base = num[begin], l = begin, r = end;
	while(r > l)
	{
		while(r > l && num[r] >= base) r--;
		while(r > l && num[l] <= base) l++;
		if(r > l) swap(num[l], num[r]);
	}
	swap(num[begin], num[l]);
	quick_sort(begin, l-1);
	quick_sort(l+1, end);
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 0;i < n;i++)
		scanf("%d",&num[i]);
	quick_sort(0, n-1);
	printf("%d", num[0]);
	for(int i = 1;i < n;i++)
		printf(" %d",num[i]);
	printf("\n");
	return 0;
}
