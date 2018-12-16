#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
string line;
typedef long long LL;
map<LL, int>base;//ͳ������Ϊsumw����ƽ��Ӧ���������
int sum;
void dfs(int depth, int s, int e)
{
	if (line[s] == '[')
	{
		int p = 0;
		for (int i = s + 1; i != e; i++)
		{
			if (line[i] == '[')p++;
			if (line[i] == ']')p--;
			if (!p&&line[i] == ',')
			{
				dfs(depth + 1, s + 1, i - 1);//����������ʽ��ֱ���ҵ�����
				dfs(depth + 1, i + 1, e - 1);
			}
		}
	}
	else
	{
		LL w = 0;
		for (int i = s; i <= e; i++)
			w = w * 10 + line[i] - '0';
		++sum, ++base[w << depth];//sumͳ��������������base[w<<depth]ͳ�Ƹ���������Ӧ���������
	}
}
int main()
{
//	freopen("in.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	while (T--)
	{
		cin >> line;
		base.clear();
		sum = 0;
		dfs(0, 0, line.size() - 1);
		int maxn = 0;
		for (map<LL, int>::iterator it = base.begin(); it != base.end(); it++)//����C++ 11���¹ؼ���auto�Զ�ʶ������
			maxn = max(maxn, it->second);
		cout << sum - maxn << endl;
	}
	return 0;
}
