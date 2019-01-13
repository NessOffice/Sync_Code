#include <cstdio>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
typedef long long LL;
const int coeff[3] = {2,3,5};
int main(){
	priority_queue<LL, vector<LL>, greater<LL> > ugly;
	set<LL> numbers;
	ugly.push(1);
	for(int i=1;;i++) 
	{
		LL x = ugly.top();ugly.pop();
		if(i == 1500)
		{
			printf("The 1500'th ugly number is %lld.\n",x);
			break;
		}
		for(int j=0;j<3;j++)
		{
			LL x2 = x*coeff[j];
			if(!numbers.count(x2))
			{
				numbers.insert(x2);
				ugly.push(x2);
			}
		}
	}
	return 0;
}
