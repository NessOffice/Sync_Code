#include <iostream>
#include <string>
#include <sstream> 
#include <ctime>
using namespace std;
int main()
{
	string line;
	while(getline(cin,line))
	{
		int sum=0,x;
		stringstream ss(line);
		while(ss>>x) sum+=x;
		cout<<sum<<endl;
	}
	printf("Time used = %.2f\n",(double)clock()/CLOCKS_PER_SEC); 
	return 0;
}
