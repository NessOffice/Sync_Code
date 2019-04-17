#include <cstdio>
#include <stack>
using namespace std;
int main()
{
	stack<int> s;
	int a, b, num = 0;
	char ch;
	while((ch = getchar()) != '@')
		switch(ch)
		{
			case '+':a = s.top();s.pop();b = s.top();s.pop();s.push(a+b);break;
			case '-':a = s.top();s.pop();b = s.top();s.pop();s.push(b-a);break;
			case '*':a = s.top();s.pop();b = s.top();s.pop();s.push(a*b);break;
			case '/':a = s.top();s.pop();b = s.top();s.pop();s.push(b/a);break;
			case '.':s.push(num);num = 0;break;
			default:num = num*10 + ch - '0';break;
		}
	printf("%d", s.top());
	return 0;
}
