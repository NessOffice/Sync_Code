#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
struct Node{
	int weight;
	int id;
	Node* childL;
	Node* childR;
};
priority_queue<int, vector<int>, greater<int> > q;
int main()
{
	int n = 6, fre[10] = {5, 9, 12, 13, 14, 45};
	for(int i = 0;i < n;i++)
		q.push(fre[i]);
	for(int i = 0;i < n;i++)
	{
		
	}
	return 0;
}
