#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char str[30][20];
bool cmp(char s1[], char s2[])
{
	int lenm = min(strlen(s1), strlen(s2));
	for(int i = 0;i < lenm;i++)
	{
		if(s1[i] < s2[i]) return s1 < s2;
		if(s2[i] < s1[i]) return s2 < s1;
	}
	return strlen(s1) < strlen(s2);
}
int main()
{
	//   freopen("in.txt", "r", stdin);
	//   freopen("out.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for(int i = 0;i < n;i++)
		scanf("%s", str[i]);
	std::sort(str, str + n);
	for(int i = 0;i < n;i++)
		printf("%s", str[i]);
	return 0;
}
