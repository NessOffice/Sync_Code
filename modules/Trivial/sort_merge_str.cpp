#include <stdio.h>
#include <string.h>
#define MAXS 80 + 5
char str[MAXS][MAXS], temp[MAXS][MAXS];
int cmp(char* s1, char* s2)
{
	int len_1 = strlen(s1), len_2 = strlen(s2), len_min;
	len_min = len_1 < len_2 ? len_1 : len_2;
	int ans = memcmp(s1, s2, len_min);
	if(ans == -1) return 1;
	else if(ans == 0 && len_1 < len_2) return 1;
	return 0;
}
void Merge(int begin, int mid, int end)
{
	for(int i = begin;i < end;i++)
	{
		memcpy(temp[i], str[i], MAXS);
	}
	int j = begin, k = mid, i = begin;
	while(j < mid && k < end)
	{
		if(cmp(temp[j], temp[k]))//memcmp与memcpy运行的差异？ 
			{memcpy(str[i], temp[j], MAXS); j++; i++;}
		else
			{memcpy(str[i], temp[k], MAXS); k++; i++;}
	}
	while(j < mid){memcpy(str[i], temp[j], MAXS); i++; j++;}
	while(k < end){memcpy(str[i], temp[k], MAXS); i++; k++;}
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
    int n = 5;
    for(int i = 0;i < n;i++)
    	scanf("%s", str[i]);
    MergeSort(0, n);
	printf("After sorted:\n");
	for(int i = 0;i < n;i++)
		printf("%s\n", str[i]);
    return 0;
}
