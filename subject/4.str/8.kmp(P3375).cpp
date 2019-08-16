#include <cstdio>
#include <cstring>
#define re register int
const int maxn = 2e6 + 5;
char s1[maxn], s2[maxn];
int kmp[maxn];
int main()
{
    scanf("%s%s", s1, s2);
	int len2 = strlen(s2), len1 = strlen(s1);
	s2[len2] = '$';
	for(re i = 0;i < len1;i++)
		s2[len2+i+1] = s1[i];
	kmp[0] = 0;
	for(re i = 1;i < len1+len2+1;i++)
	{
		int j = kmp[i-1];
		while(j && s2[i] != s2[j]) j = kmp[j-1];
		if(s2[i] == s2[j]) j++;
		kmp[i] = j;
		if(kmp[i] == len2)
			printf("%d\n", i-2*len2+1);
	}
	for(int i = 0;i < len2;i++)
		printf("%d ", kmp[i]);
    return 0;
}
