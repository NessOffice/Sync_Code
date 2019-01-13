#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 256 + 20, root = 0;
int flag = 0, cnt = 1, first = 0;
int val[maxn], var[maxn], left[maxn], right[maxn];
int CheckTree(int u)
{
	if(flag || u == -1 || !var[u]) return 0;
	return 1 + CheckTree(left[u]) + CheckTree(right[u]);
}
void NewNode(int u)
{
	left[u] = right[u] = -1;
	var[u] = 0;
}
void AddNode(int value, char* s)
{
	int len = strlen(s) - 1, u = root;
	for(int i = 0;i < len;i++)
	{
		if(s[i] == 'L'){
			if(left[u] == -1)
			{
				NewNode(cnt);
				left[u] = cnt++;
			}
			u = left[u];
		}else{
			if(right[u] == -1)
			{
				NewNode(cnt);
				right[u] = cnt++;
			}
			u = right[u];
		}
	}
	if(var[u]) flag = 1;
	else val[u] = value;
	var[u] = 1;
}
int main()
{
	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	char temp[maxn];
	int value;
	NewNode(0);
	while(scanf("%s", temp) != -1)
	{
		if(temp[1] == ')'){
			queue<int> q;
			vector<int> out;
			if(CheckTree(root) != cnt) flag = 1;
			if(flag) printf("not complete\n");
			else
			{
				q.push(root);
				while(!q.empty())
				{
					int u = q.front();q.pop();
					out.push_back(val[u]);
					if(left[u] != -1) q.push(left[u]);
					if(right[u] != -1) q.push(right[u]);
				}
				int len = out.size();
				for(int i = 0;i < len;i++)
				{
					if(first++) putchar(' ');
					printf("%d",out[i]);
				}
				printf("\n");
			}
			flag = first = 0;
			cnt = 1;
			NewNode(0);
		}else{
			sscanf(&temp[1], "%d", &value);
			AddNode(value, strchr(temp, ',') + 1);
		}
	}
	return 0;
}
