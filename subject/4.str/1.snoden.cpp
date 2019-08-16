#include <cstdio>
#include <cstring>
const char *regular[] = {"one", "two", "three", "four", "five", "six",
					"seven", "eight", "nine", "ten", "eleven", "twelve",
					"thirteen", "fourteen", "fifteen", "sixteen",
					"seventeen", "eighteen", "nineteen", "twenty"};
const char *other[] = {"a", "both", "another", "first", "second", "third"};
const int p[] = {1, 2, 1, 1, 2, 3};
const int seq[] = {1, 2, 3, 4, 11, 18, 5, 15, 6,
				   12, 7, 16, 19, 8, 13, 9, 17, 14};
int main()
{
	long long cnt[30], ans = 0;
	memset(cnt, 0, sizeof(cnt));
	char word[20];
	while(~scanf("%s", word))
	{
		for(int i = 0;i < 20;i++)
			if(!strcmp(word, regular[i]))
				cnt[i+1]++;
		for(int i = 0;i < 6;i++)
			if(!strcmp(word, other[i]))
				cnt[p[i]]++;
	}
	for(int i = 0;i < 18;i++)
	{
		int j = seq[i];
		while(cnt[j]--)
			ans = ans * 100 + (j*j%100);
	}
	printf("%lld", ans);
	return 0;
}
