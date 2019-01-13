#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
map<string, int> arrayList;
map<string, int> arraySize;
int str2int(string str)
{
	int len = str.length(), result = 0;
	for(int i = 0;i < len;i++)
	{
		result *= 10;
		result += (str[i] - '0');
	}
	return result;
}
string int2str(int temp)
{
	string str;
	int temp2 = 0;
	while(temp)
	{
		temp2 *= 10;
		int remain = temp % 10;
		temp2 += remain;
		temp /= 10;
	}
	while(temp2)
	{
		int remain = temp2 % 10;
		str += (remain + '0');
		temp2 /= 10;
	}
	return str;
}
int GetIndex(string str)
{
	int index, l, r;
	l = str.find('[');
	r = str.find(']');
	string temp = str.substr(l + 1,r  - l - 1);
	index = str2int(temp);
	return index;
}
bool Interate(string& str, char type)
{
	int l, r, r1;
	l = str.rfind('[');
	r = str.find(']');
	r1 = str.rfind(']');
	while(r != r1)
	{
		string temp = str.substr(l - 1,r + 2 - l);
		if(!arrayList.count(temp)) return false;
		string temp2 = int2str(arrayList[temp]);
		str.replace(l - 1, r + 2 - l, temp2);
		l = str.rfind('[');
		r = str.find(']');
		r1 = str.rfind(']');
	}
	if(type == 'r' && r != -1)
		if(!arrayList.count(str)) return false;
	return true;
}
int main(){
	ios::sync_with_stdio(false);
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	string exp;
	int flag = 0, bug = 0, line = 1;
	while(cin>>exp)
	{
		if(exp[0] == '.')
		{
			if(flag) break;
			else
			{
				cout<<bug<<endl;
				bug = 0;
				line = 1;
				flag = 1;
				arrayList.clear();
				arraySize.clear();
			}
		}
		else
		{
			if(flag) flag = 0;
			if(bug >= 1) continue;
			
			int equ = exp.find('=');
			if(equ == -1)
			{
				int sizes = GetIndex(exp);
				int l = exp.find('[');
				string name = exp.substr(0, l);
				if(sizes < 0) bug = line;
				else arraySize[name] = sizes;
			}
			else
			{
				string left = exp.substr(0, equ);
				string right = exp.substr(equ + 1);
				if(!Interate(left,'l') || !Interate(right,'r'))
					bug = line;
				else
				{
					int r;
					if(right.find('[') == -1)
						r = str2int(right);
					else
						r = arrayList[right];
					int l = left.find('[');
					string name = left.substr(0, l);
					int index = GetIndex(left);
					if(index >= arraySize[name] || index < 0)
						bug = line;
					else arrayList[left] = r;
				}
			}
			line++;
		}
	}
	return 0;
}
