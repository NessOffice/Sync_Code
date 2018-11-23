#include <stdio.h>
#define MAXN 10000 + 2
int num[MAXN];
int temp[MAXN];
void Merge(int begin, int mid, int end)
{
	for(int i = begin;i < end;i++)
	{
		temp[i] = num[i];
	}
	int j = begin, k = mid, i = begin;
	while(j < mid && k < end)
	{
		if(temp[j] < temp[k])
			num[i] = temp[j++];
		else
			num[i] = temp[k++];
		i++;
	}
	while(j < mid){num[i] = temp[j++];i++;}
	while(k < end){num[i] = temp[k++];i++;}
}
void MergeSort(int begin, int end)
{
	if(end == begin + 1) return;
	int mid = (begin + end) / 2;
	MergeSort(begin, mid);
	MergeSort(mid, end);
	Merge(begin, mid, end);
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 0;i < n;i++)
	{
		scanf("%d",&num[i]);
		temp[i] = num[i];
	}
	MergeSort(0, n);
	int first = 0;
	for(int i = n - 1;i >= 0;i--)
	{
		if(first++) printf(" ");
		printf("%d",num[i]);
	}
	return 0;
}
