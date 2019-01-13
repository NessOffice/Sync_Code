#include <cstdio>
#include <algorithm>
using namespace std;
struct Node{
	int val;
	Node* next;
	Node():val(-1),next(NULL){}
};
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n, m, kase = 1, odd = 1, sum = 0, rev = 0;
	while(scanf("%d%d", &n, &m) == 2)
	{
		Node* head = new Node();
		Node* last = head;
		for(int i = 1;i <= n;i++)
		{
			Node* node = new Node();
			node->val = i;
			last->next = node;
			last = node;
		}
		int cmd, op1, op2;
		while(m--)
		{
			scanf("%d", &cmd);
			if(cmd < 4) scanf("%d%d", &op1, &op2);
			Node *node1, *node2; 
			if(cmd < 4)
			{
				Node *last1, *last2;
				node1 = node2 = head->next;
				last1 = last2 = head;
				while(node1->val != op1)
				{
					last1 = node1;
					node1 = node1->next;
				}
				while(node2->val != op2)
				{
					last2 = node2;
					node2 = node2->next;
				}
				if(cmd == 1 && node1->next != node2)//why?
				{
					last1->next = node1->next;
					last2->next = node1;
					node1->next = node2;
				}
				if(cmd == 2)
				{
					last1->next = node1->next;
					node1->next = node2->next;
					node2->next = node1;
				}
				if(cmd == 3) swap(node1->val, node2->val);
			}
			else
			{
				node1 = node2 = head->next;
				last = NULL;
				while(node1->next)
				{
					node2 = node1->next;
					node1->next = last;
					last = node1;
					node1 = node2;
				}
				node1->next = last;
				head->next = node1;
			}
		}
		last = head->next;
		/*while(last)
		{
			if(first++) putchar(' ');
			printf("%d",last->val);
			last = last->next;
		}
		printf("\n");*/ 
		while(last)
		{
			if(odd % 2) sum += last->val;
			odd = 1 - odd;
			last = last->next;
		}
		printf("Case %d: %d\n", kase++, sum);
		odd = 1, sum = 0;
	}
	return 0;
}
