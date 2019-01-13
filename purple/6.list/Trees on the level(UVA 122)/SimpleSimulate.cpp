#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
const int maxn = 256 + 4;
set<string> idCache;
int n, flag;
struct NODE{
	int val;
	string id;
	int len;
	bool operator < (const NODE b) const{
		if(len != b.len) return len < b.len;
		for(int i = 0;i < len;i++)
			if(id[i] != b.id[i]) return id[i] < b.id[i];
	}
}nodes[maxn];
int isComplete()
{
	if(nodes[0].len) return 1;
	for(int i = 1;i < n;i++)
	{
		string father = nodes[i].id;
		int len = father.length();
		father.resize(len - 1);
		if(!idCache.count(father)) return 1;
	} 
	return 0;
}
void Process()
{
	if(!flag)
	{
		sort(nodes, nodes + n);
		flag = isComplete();
	}
	if(!flag)
	{
		cout<<nodes[0].val;
		for(int i = 1;i < n;i++)
			cout<<' '<<nodes[i].val;
		cout<<endl;
	}
	else cout<<"not complete\n"; 
}
bool ReadTree()
{
	idCache.clear();
	n = flag = 0;
	string node;
	while(cin>>node)
	{
		int len = node.length(), val = 0, i = 0;
		string id;
		if(node[1] == ')') return true;
		for(i = 1;node[i] != ',';i++)
		{
			val *= 10;
			val += (node[i] - '0');
		}
		id = (len-i-2 ? node.substr(i+1,len-i-2) : "");
		if(idCache.count(id)) flag = 1;
		else idCache.insert(id);
		nodes[n].val = val;
		nodes[n].id = id;
		nodes[n].len = id.length();
		n++;
	}
	return false;
}
int main()
{
	ios::sync_with_stdio(false);
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(ReadTree())
		Process();
	return 0;
}
