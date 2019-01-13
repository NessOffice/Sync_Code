#include <cstdio>
#include <map>
using namespace std;
int x, node;
map<int, int> weigh;
void op()
{
	if(!weigh.count(x)) weigh[x] = 0;
	weigh[x] += node;
}
void ReadNode(int type)
{
	scanf("%d", &node);
	if(node == -1) return;
	if(type){
		x--;
		op();
		ReadNode(1);
		ReadNode(0);
		x++;
	}else{
		x++;
		op();
		ReadNode(1);
		ReadNode(0);
		x--;
	}
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int kase = 0;
	while(scanf("%d", &node) && node != -1)
	{
		x = 0;
		weigh.clear();
		op();
		ReadNode(1);
		ReadNode(0);
		map<int, int>::iterator it = weigh.begin();
		printf("Case %d:\n%d", ++kase, it->second);
		while(++it != weigh.end()) printf(" %d", it->second);
		printf("\n\n");
	}
	return 0;
}
