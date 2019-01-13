#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 256 + 20;
int flag = 0, n = 0, first = 0;
struct Node{
	int val, var;
	Node *left, *right;
	Node():var(0), left(NULL), right(NULL){}
};
Node* root = new Node();
int CheckTree(Node *u)
{
	if(flag || u == NULL || !(u->var)) return 0;
	return 1 + CheckTree(u->left) + CheckTree(u->right);
}
void DeleteNode(Node *u)
{
	if(u == NULL) return;
	DeleteNode(u->left);
	DeleteNode(u->right);
	delete u;
}
void AddNode(int val, char* s)
{
	int len = strlen(s) - 1;
	Node* u = root;
	for(int i = 0;i < len;i++)
	{
		if(s[i] == 'L'){
			if(u->left == NULL)
				u->left = new Node();
			u = u->left;
		}else{
			if(u->right == NULL)
				u->right = new Node();
			u = u->right;
		}
	}
	if(u->var) flag = 1;
	else u->val = val;
	u->var = 1;
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	char temp[maxn];
	int val;
	while(scanf("%s", temp) != -1)
	{
		if(temp[1] == ')'){
			queue<Node*> q;
			vector<int> out;
			if(CheckTree(root) != n) flag = 1;
			if(flag) printf("not complete\n");
			else
			{
				q.push(root);
				while(!q.empty())
				{
					Node* u = q.front();q.pop();
					out.push_back(u->val);
					if(u->left != NULL) q.push(u->left);
					if(u->right != NULL) q.push(u->right);
				}
				int len = out.size();
				for(int i = 0;i < len;i++)
				{
					if(first++) putchar(' ');
					printf("%d",out[i]);
				}
				printf("\n");
			}
			DeleteNode(root);
			root = new Node();
			flag = n = first = 0;
		}else{
			sscanf(&temp[1], "%d", &val);
			AddNode(val, strchr(temp, ',') + 1);
			n++;
		}
	}
	return 0;
}
