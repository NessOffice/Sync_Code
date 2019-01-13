#include <iostream>
#include <queue>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n, num;
	while(cin>>n && n)
	{
		while(1)
		{
			deque<int> in;
			deque<int> out;
			int quit = 0;
			for(int i = 1;i <= n;i++)
			{
				cin>>num;
				if(num == 0){quit = 1;break;}
				out.push_front(num);
			}
			if(quit) break;
			for(int i = 1;i <= n;i++)
			{
				in.push_back(i);
				while(!in.empty() && in.back() == out.back())
				{
					in.pop_back();
					out.pop_back();
				}
			}
			cout<<(out.empty() ? "Yes" : "No")<<endl; 
		}
		cout<<endl;
	}
	return 0;
}
