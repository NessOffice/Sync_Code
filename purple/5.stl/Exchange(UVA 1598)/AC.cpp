#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
const int maxn = 10000 + 5;
struct ORDER{
	bool active;
	char type;
	int num, price;
}orders[maxn];
map<int, set<int> >buy;
map<int, int> buyNum;
map<int, set<int> >sell;
map<int, int> sellNum;
void deal(char flag)
{
	while(!buy.empty() && !sell.empty())
	{
		if(buy.rbegin()->first < sell.begin()->first) return;
		set<int>& buyers = buy.rbegin()->second;
		set<int>& sellers = sell.begin()->second;
		int index1 = *buyers.begin(), index2 = *sellers.begin();
		int price1 = orders[index1].price, price2 = orders[index2].price;
		int tradeNum = min(orders[index1].num, orders[index2].num);
		orders[index1].num -= tradeNum, orders[index2].num -= tradeNum;
		buyNum[price1] -= tradeNum, sellNum[price2] -= tradeNum;
		cout<<"TRADE "<<tradeNum<<" "<<(flag == 'B' ? price2 : price1)<<endl;
		if(!orders[index1].num){buyers.erase(index1);orders[index1].active = false;}
		if(!orders[index2].num){sellers.erase(index2);orders[index2].active = false;}
		if(buyers.empty()) buy.erase(price1);
		if(sellers.empty()) sell.erase(price2);
	}
}
void Print()
{
	cout<<"QUOTE "; 
	int num = 0, price = 0;
	if(!buy.empty())
	{
		price = buy.rbegin()->first;
		num = buyNum[price];
	}
	cout<<num<<" "<<price<<" - ";
	num = 0, price = 99999;
	if(!sell.empty())
	{
		price = sell.begin()->first;
		num = sellNum[price];
	}
	cout<<num<<" "<<price<<endl;
}
int main()
{
	ios::sync_with_stdio(false);
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n, first = 0;
	while(cin>>n)
	{
		if(first++) cout<<endl;
		buy.clear(), sell.clear();
		buyNum.clear(), sellNum.clear();
		for(int i = 1;i <= n;i++)
		{
			string str;cin>>str;
			char type = str[0];
			if(type == 'C')
			{
				int line;cin>>line;
				if(orders[line].active)
				{
					char type2 = orders[line].type;
					int price = orders[line].price;
					orders[line].active = false;
					if(type2 == 'B' && buy[price].count(line))
					{
						buy[price].erase(line);
						buyNum[price] -= orders[line].num;
						if(buy[price].empty()) buy.erase(price);
					}
					if(type2 == 'S' && sell[price].count(line))
					{
						sell[price].erase(line);
						sellNum[price] -= orders[line].num;
						if(sell[price].empty()) sell.erase(price);
					}
				}
			}
			else
			{
				ORDER newOrder;
				int num, price;cin>>num>>price;
				newOrder.active = true, newOrder.type = type;
				newOrder.num = num, newOrder.price = price;
				orders[i] = newOrder;
				if(type == 'B')
				{
					buy[price].insert(i);
					buyNum[price] += num;
				}
				else
				{
					sell[price].insert(i);
					sellNum[price] += num;
				}
				deal(type);
			}
			Print();
		}
	}
	return 0;
}
