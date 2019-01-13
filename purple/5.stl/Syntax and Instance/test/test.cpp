#include <cstdio>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <assert.h>
using namespace std;
void fill_random_int(vector<int>& v, int cnt)
{
	v.clear();
	for(int i=0;i<cnt;i++)
		v.push_back(rand()*1.0/RAND_MAX*10);
}
void test_sort(vector<int>& v)
{
	sort(v.begin(), v.end());
	for(int i=0;i<v.size()-1;i++)
		assert(v[i]<=v[i+1]);
}
int main()
{
	vector<int> v;
	srand(time(NULL));
	fill_random_int(v,1000000);
	test_sort(v);
	/*
	for(int i=0;i<1000;i++)
		printf("%d\n",v[i]);
	*/
	return 0;
}
