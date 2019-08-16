#include <cstdio>
#include <cstring>
#include <cctype>
const int maxn = 4e5+5;
int ch2int(int ch)
{
	if(isdigit(ch)) return ch - '0';
	else return ch - 'a' + 10;
}
char int2ch(int num)
{
	if(num < 10) return num + '0';
	else return (num - 10) + 'a';
}
int main()
{
//	freopen("odious_in.txt", "r", stdin);
//	freopen("odious_out3.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	char hex[maxn];
	int bin[maxn];
	memset(bin, 0, sizeof(bin));
	while(T--)
	{
		scanf("%s", hex);
		int len = strlen(hex);
		for(int i = 0;i < len;i++)
		{
			int val = ch2int(hex[i]);
			bin[4*(len-1-i)+0] = val & 1;val >>= 1;
			bin[4*(len-1-i)+1] = val & 1;val >>= 1;
			bin[4*(len-1-i)+2] = val & 1;val >>= 1;
			bin[4*(len-1-i)+3] = val & 1;val >>= 1;
		}
		bin[4*len+0] = 0;
		bin[4*len+1] = 0;
		bin[4*len+2] = 0;
		bin[4*len+3] = 0;
		bin[0]--;
		for(int i = 0;i < 4*len;i++)
			if(bin[i] < 0){
				bin[i] = 1;
				bin[i+1]--;
			}else
				break;
		if(bin[4*len-1])
			len++;
		int cnt = 0;
		for(int i = 4*len-1;i >= 0;i--)
		{
			bin[i] = bin[i-1];
			if(bin[i]) cnt++;
		}
		bin[0] = 0;
		if((cnt & 1) == 0) bin[0] = 1;
		for(int i = len-1;i >= 0;i--)
		{
			int val = 0;
			val <<= 1;val += bin[4*i+3];
			val <<= 1;val += bin[4*i+2];
			val <<= 1;val += bin[4*i+1];
			val <<= 1;val += bin[4*i+0];
			putchar(int2ch(val));
		}
		putchar('\n');
	}
	return 0;
}
