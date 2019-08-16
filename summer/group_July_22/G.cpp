#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
LL vec2int(vector<LL> vec)
{
	LL ans = 0, i = 0;
	while(vec[i] == 0) i++;
	for(LL sz = vec.size();i < sz;i++)
	{
		ans *= 10;
		ans += vec[i];
	}
	return ans;
}
vector<LL> int2vec(LL num)
{
	vector<LL> ans;
	do{
		ans.push_back(num % 10);
		num /= 10;
	}while(num);
	reverse(ans.begin(), ans.end());
	return ans;
}
LL product(LL num)
{
	LL ans = 1;
	do{
		ans *= (num % 10);
		num /= 10;
	}while(num);
	return ans;
}
int main()
{
	LL a, b;
	scanf("%lld%lld", &a, &b);
	LL res = b;
	vector<LL> vec_b = int2vec(b);
	for(LL i = 0, sz = vec_b.size();i < sz;i++)
	{
		if(vec_b[i] == 0) continue;
		vector<LL> vec_temp = vec_b;
		vec_temp[i]--;
		fill(vec_temp.begin()+i+1, vec_temp.end(), 9);
		LL num = vec2int(vec_temp);
		if(num >= a && product(num) > product(res)) res = num;
	}
	printf("%lld", res);
	return 0;
}
