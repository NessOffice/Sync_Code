#include <cstdio>
int main()
{
	// freopen("in.txt", "r", stdin);
	char ch;
	int ok = 1, p = 0;
	while(1)
	{
		ch = getchar();
		if(ch == ')' && p == 0) ok = 0;
		if(ch == ')') p--;
		if(ch == '(') p++;
		if(ch == '@') break;
	}
	if(p) ok = 0;
	printf("%s\n", ok ? "YES" : "NO");
	return 0;
}
