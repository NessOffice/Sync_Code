#include <cstdio>
#include <algorithm>
using namespace std;
char num[25][40];
void swap_str(int i, int j)
{
	char temp[40];
	memcpy(temp, num[i]);
	memcpy(num[i], num[j]);
	memcpy(num[j], temp);
}
bool cmp_str(int i, int j)
{
	while(num[i][k] || num[j][k])
	for(int k = 0;num[i][k] && num[j][k];k++)
	{
		if(num[i][k] < num[j][k]) return true;
		if(num[j][k] < num[i][k]) return false;
	}
	if(num[j][k]) return true;
}
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
		scanf("%s", num[i]);
	quick_sort(0, n-1);
	for(int i = 0;i < n;i++)
		printf("%s", num[i]);
	return 0;
}
