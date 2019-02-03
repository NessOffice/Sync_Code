#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 9 + 2;
const char Flag[] = "*+- ";
char digits[maxn];
int numbers[maxn], flags[maxn];
int len, impossible;
void operate()
{
	int ans, i2, j, flag = -1, zero;
	i2 = j = zero = 0;
	numbers[0] = digits[0]-'0';
	for(int i = 0;i < len - 1;i++)
	{
		if(flags[i] != 3){
			flag = flags[i];
			ans = digits[i+1]-'0';
			numbers[++i2] = ans;
			zero = !ans;
		}else{
			ans = numbers[i2];
			if(zero) return;
			zero = !ans;
			ans = 10 * ans + digits[i+1] - '0';
			numbers[i2] = ans;
		}
		if(flag == 0 && (i == len - 2 || flags[i+1] != 3))
		{
			flag = -1;
			ans = numbers[i2];
			ans *= numbers[i2-1];
			numbers[--i2] = ans;
		}
	}
	ans = numbers[0];
	for(int i = 1;i <= i2;i++, j++)
	{
		while(flags[j] == 3 || flags[j] == 0) j++;
		flag = flags[j];
		switch(flag)
		{
			case 0:ans *= numbers[i];break;
			case 1:ans += numbers[i];break;
			case 2:ans -= numbers[i];break;
		}
	}
	if(ans == 2000)
	{
		impossible = 0;
		printf("  %c", digits[0]);
		for(int i = 0;i < len - 1;i++)
		{
			if(flags[i] != 3) putchar(Flag[flags[i]]);
			putchar(digits[i+1]);
		}
		printf("=\n");
	}
}
int main()
{
	int kase = 0, max_enum;
	while(scanf("%s", digits))
	{
		if(digits[0] == '=') break;
		impossible = 1;
		len = strchr(digits, '=') - digits;
		printf("Problem %d\n", ++kase);
		max_enum = (1<<(2*(len-1)));
		for(int i = 0;i < max_enum - 1;i++)
		{
			int temp = i;
			for(int j = len - 2;j >= 0;j--)
			{
				flags[j] = temp % 4;
				temp /= 4;
			}
			operate();
		}
		if(impossible)
			printf("  IMPOSSIBLE\n");
	}
	return 0;
}
