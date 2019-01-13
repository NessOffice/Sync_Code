#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
struct request{
	int id, num, t0, tp, dt, coped;
}topic[20 + 2];
struct server{
	bool busy;
	int id, num, last;
	vector<int> prefer;//it stores the request
	bool operator < (const server& b) const {
		if(last == b.last) return id < b.id;
		return last > b.last;
	}
}person[5 + 2], p[5 + 2];
map<int, int> id2request;
map<int, int> done;//key:request
map<int, pair<int, int> > doing;//key:request; value_first:is_working?:second:who is working?
int main()
{
	ios::sync_with_stdio(false);
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n, m, kase = 1;
	while(cin>>n && n)
	{
		doing.clear();
		done.clear();
		for(int i = 0;i < n;i++)
		{
			cin>>topic[i].id>>topic[i].num;
			cin>>topic[i].t0>>topic[i].tp>>topic[i].dt;
			id2request[topic[i].id] = i;
			topic[i].coped = 0;
			doing[i] = make_pair(0, -1);
		}
		cin>>m;
		for(int i = 0;i < m;i++)
		{
			person[i].busy = false;
			person[i].prefer.clear();
			person[i].last = 0;
			cin>>person[i].id>>person[i].num;
			for(int j = 0;j < person[i].num;j++)
			{
				int id;cin>>id;
				int r = id2request[id];
				person[i].prefer.push_back(r);
			}
		}
		int t = 0;
		while(done.size() < n)
		{
			//first, assign the tasks
			for(int i = 0;i < m;i++)//i for person
			{
				if(person[i].busy) continue;
				for(int j = 0;j < person[i].num;j++)//j for topic
				{
					if(person[i].busy) break;
					int r = person[i].prefer[j];
					if(done.count(r) || doing[r].first) continue;
					int t0 = topic[r].t0;
					int dt = topic[r].dt;
					int coped = topic[r].coped;
					if(t < t0 + dt * coped) continue;
					for(int k = 0;k < m;k++)
					{
						p[k].num = person[k].num;
						p[k].busy = person[k].busy;
						p[k].id = person[k].id;
						p[k].last = person[k].last;
						p[k].prefer = person[k].prefer;
					}
					sort(p, p + m);
					for(int k = 0;k < m;k++)
					{
						if(doing[r].first) break;
						int flag = 1;
						for(int g = 0;g < p[k].num;g++)
							if(p[k].prefer[g] == r) flag = 0;
						if(flag) continue;
						if(p[k].busy) continue;
						doing[r].first = topic[r].tp;
						doing[r].second = p[k].id;
						for(int g = 0;g < m;g++)
							if(person[g].id == p[k].id) person[g].busy = true;
					}
				}
			}
			//then, process them
			for(int r = 0;r < n;r++)
			if(doing[r].first)
			{
				doing[r].first--;
				if(doing[r].first == 0)
				{
					topic[r].coped++;
					for(int k = 0;k < m;k++)
					{
						if(person[k].id == doing[r].second)
						{
							person[k].busy = false;
							person[k].last = topic[r].tp;
							break;
						}
					}
				}
				if(topic[r].coped == topic[r].num) done[r] = 1;
			}
			t++;
			/*cout<<"minute "<<t<<endl;
			map<int, pair<int, int> >::iterator it = doing.begin();
			for(;it != doing.end();it++)
			{
				cout<<"topic:"<<(it->first)<<" time:"<<(it->second).first<<" person:"<<(it->second).second<<endl;
			}*/
		}
		cout<<"Scenario "<<kase++;
		cout<<": All requests are serviced within "<<t<<" minutes.\n";
	}
	return 0;
}
