#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 5;
int mark[maxn], nxt[maxn], c[maxn], len;
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
int search_upper(int num)
{
	int l = 0, r = len-1;
	while(l < r)
	{
		int mid = (l+r+1)/2;
		if(c[mid] > num)
			r = mid-1;
		else
			l = mid;
	}
	return l;
}
int special(int num)
{
	if(num == 4) return 3;
	if(num == 9) return 7;
	if(num == 16) return 15;
	return 0;
}
int main()
{
	scanf("%d", &len);
	for(int i = 0;i < len;i++)
		scanf("%d", c+i);
	sort(c, c+len);
	for(int last = 0, i;last < len;last = i+1)
	{
		if(i < last) i = last;
		while(i+1 < len && c[i+1] == c[last])
			i++;
		nxt[i] = i;
	}
	memset(mark, 0, sizeof(mark));
	for(int i = len-1;i >= 0;i--)
	{
		if(mark[i]) continue;
		int bi, l;
		if(bi = special(c[i]))
		{
			l = search_upper(bi);
			l = nxt[l];
			if(mark[l] == 0)
			{
				nxt[l]--;
				mark[i] = mark[l] = 1;
				putchar('a'+special(c[i]));
				continue;
			}
		}
		bi = calc(c[i]);
		l = search_upper(bi);
		l = nxt[l]--;
		mark[i] = mark[l] = 1;
		putchar('a'+(c[i]%26));
	}
	return 0;
}
// 20
// 5 4 3 11 7 1 17 4 14 5 5 22 9 5 9 9 14 11 11 2

// 20
// 7 4 11 11 14 22 14 17 11 3 9 1 5 5 9 5 9 2 5 4