#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 10000 + 5;
struct ORDER{
	bool active;
	char type;
	int num, price, line;
	bool operator < (const ORDER b) const{
		if(active != b.active) return active > b.active;
		if(price == b.price) return line > b.line;
		if(type == 'B') return price < b.price;
		else return price > b.price;
	}
}orders[maxn];
void operate(int& num, int& len1, int& len2, int price, vector<ORDER>& op, char flag)
{
	int index = len2 - 1;
	while(index >= 0 && num)
	{
		if(flag == 'B' && price < op[index].price) return;
		if(flag == 'S' && price > op[index].price) return;
		int num2 = op[index].num;
		if(num >= num2)
		{
			num -= num2;
			op[index].active = false;
			len2--;
		}
		else
		{
			num2 = num;
			op[index].num -= num;
			num = 0;
		}
		cout<<"TRADE "<<num2<<" "<<op[index].price<<endl;
		index--;
	}
}
void cancel(int line, int& len, vector<ORDER>& op)
{
	orders[line].active = false;
	for(int j = len - 1;j >= 0;j--)
		if(op[j].line == line)
		{
			op[j].active = false;
			len--;
			sort(op.begin(), op.end());
			return;
		}
}
void Output(int len, vector<ORDER> op, char flag)
{
	int num = 0, price = 0;
	if(flag == 'S') price = 99999;
	if(len) price = op[len - 1].price;
	for(int j = len - 1;j >= 0;j--)
	{
		if(op[j].price != price) break;
		num += op[j].num;
	}
	cout<<num<<" "<<price;
	if(flag == 'B') cout<<" - ";
	else cout<<endl;
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
		vector<ORDER> buys;
		vector<ORDER> sells;
		int len1 = 0, len2 = 0;
		for(int i = 1;i <= n;i++)
		{
			string str;cin>>str;
			char type = str[0];
			if(type == 'C')
			{
				int line;cin>>line;
				if(!orders[line].active) continue;
				char type2 = orders[line].type;
				if(type2 == 'B') cancel(line, len1, buys);
				if(type2 == 'S') cancel(line, len2, sells);
			}
			else
			{
				ORDER newOrder;
				int num, price;
				cin>>num>>price;
				newOrder.active = true, newOrder.type = type;
				newOrder.num = num, newOrder.price = price, newOrder.line = i;
				orders[i] = newOrder;
				if(type == 'B')
				{
					operate(num, len1, len2, price, sells, type);
					if(num) len1++;
					else{newOrder.active = false;orders[i].active = false;}
					newOrder.num = num;
					buys.push_back(newOrder);
					sort(buys.begin(), buys.end());
				}
				else
				{
					operate(num, len2, len1, price, buys, type);
					if(num) len2++;
					else{newOrder.active = false;orders[i].active = false;} 
					newOrder.num = num;
					sells.push_back(newOrder);
					sort(sells.begin(), sells.end());
				}
			}
			cout<<"QUOTE ";
			Output(len1, buys, 'B');
			Output(len2, sells, 'S');
		}
	}
	return 0;
}
