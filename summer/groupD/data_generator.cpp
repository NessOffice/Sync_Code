#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int calc(int num)
{
	int ans = 0, cnt = 0;
	do{
		if(num & 1)
			cnt++;
		else
		{
			ans += (cnt*cnt);
			cnt = 0;
		}
		num /= 2;
	}while(num);
	ans += (cnt*cnt);
	return ans;
}
int main()
{
	int a[1000], c[2000], len;
	char str[1000];
	scanf("%s", str);
	len = strlen(str);
	for(int i = 0;i < len;i++)
	{
		a[i] = c[i] = (str[i] - 'a') % 26;
		c[len+i] = calc(a[i]);
	}
	len *= 2;
	// random_shuffle(c, c+len);
	printf("%d\n", len);
	for(int i = 0;i < len;i++)
		printf("%d ", c[i]);
	return 0;
}
// helloworld
