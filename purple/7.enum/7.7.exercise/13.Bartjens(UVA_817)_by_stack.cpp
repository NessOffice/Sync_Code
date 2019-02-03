#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
const int maxn = 9 + 2;
const char Flag[] = "*+- ";
char digits[maxn];
stack<int> s_flag;
stack<int> s_flag2;
stack<int> s_number;
stack<int> s_cal;
int len, flags[maxn];
bool possible;
void operate()
{
	int ans;
	s_number.push(digits[0]-'0');
	bool zero = false;
	for(int i = 0;i < len - 1;i++)
	{
		if(flags[i] != 3){
			s_flag.push(flags[i]);
			ans = digits[i+1]-'0';
			s_number.push(ans);
			zero = ans ? false : true;
		}else{
			ans = s_number.top();
			if(zero)
			{
				while(!s_number.empty()) s_number.pop();
				while(!s_cal.empty()) s_cal.pop();
				while(!s_flag.empty()) s_flag.pop();
				return;
			}
			zero = ans ? false : true;
			ans = 10 * ans + digits[i+1] - '0';
			s_number.pop();
			s_number.push(ans);
		}
		if(!s_flag.empty() && s_flag.top() == 0)
		if(i == len - 2 || flags[i+1] != 3)
		{
			s_flag.pop();
			ans = s_number.top();s_number.pop();
			int temp = s_number.top();s_number.pop();
			ans *= temp;
			s_number.push(ans);
		}
	}
	while(!s_flag.empty())
	{
		ans = s_flag.top();
		s_flag.pop();
		s_flag2.push(ans);
	}
	while(!s_number.empty())
	{
		ans = s_number.top();
		s_number.pop();
		s_cal.push(ans);
	}
	ans = s_cal.top();s_cal.pop();
	while(!s_cal.empty())
	{
		int flag = s_flag2.top(), temp = s_cal.top();
		s_cal.pop();s_flag2.pop();
		if(flag == 0) ans *= temp;
		else if(flag == 1) ans += temp;
		else ans -= temp;
	}
	if(ans == 2000)
	{
		possible = true;
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
	//  freopen("in.txt", "r", stdin);
	//  freopen("out.txt", "w", stdout);
	int kase = 0, max_enum;
	while(scanf("%s", digits))
	{
		if(digits[0] == '=') break;
		possible = false;
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
		if(!possible)
			printf("  IMPOSSIBLE\n");
	}
	return 0;
}
