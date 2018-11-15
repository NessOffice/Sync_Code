#include <iostream>
#include <queue> 
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n;
	while(cin>>n && n)
	{
		queue<int> cards;
		int first = 0;
		for(int i = 1;i <= n;i++)
		{
			cards.push(i);
		}
		cout<<"Discarded cards:";
		if(cards.size() > 1) cout<<' ';
		while(cards.size() > 1)
		{
			if(first++) cout<<", ";
			cout<<cards.front();
			cards.pop();
			int temp = cards.front();
			cards.pop();
			cards.push(temp);
		}
		cout<<"\nRemaining card: "<<cards.front()<<endl;
	}
	return 0;
}
