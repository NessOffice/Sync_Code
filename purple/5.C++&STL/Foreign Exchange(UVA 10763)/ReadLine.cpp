#include <iostream>
#include <string> 
#include <sstream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	string line;
	int i = 0, target = 0;
	while(getline(cin,line))
	{
		i++;
		stringstream ss(line);
		int x = 0, temp;
		while(ss>>temp)
		{
			x++;
		}
		if(x == 1) target++;
		if(target == 9) break;
	}
	cout<<i;
	return 0;
}
