#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 4e5 + 5; // fuuuuuuuuuuuck!
const int maxp = 2750131;
struct Node{int num, used;}nodes[maxn];
bool cmp(const Node& lhs, const Node& rhs){return lhs.num < rhs.num;}
int min_prime_factor[maxp + 5]; // caution!
int primes[maxn], ans[maxn], cnt = 0;
int composite_indexes[maxn];
int n;
bool is_prime(int num)
{
	return min_prime_factor[num] == num;
}
void sift(int maxm)
{
	for(int i = 2;i <= maxm;i++)
        min_prime_factor[i] = i;
	memset(primes, 0, sizeof(primes));
	for(int i = 2;i <= maxm;i++)
	{
		if(is_prime(i)) primes[++cnt] = i;
		for(int j = 1;j <= cnt && i*primes[j] <= maxm;j++)
		{
            int prime_now = primes[j];
            min_prime_factor[i * prime_now] = prime_now;
			if(i % prime_now == 0) break;
		}
	}
}
int find_composite_index(int new_num) // lower_bound
{
	if(composite_indexes[new_num] != -1) // what the fuuuuuuuuuuuuuuck
	{
		composite_indexes[new_num]++;
		return composite_indexes[new_num];
	}
	int l = 0, r = 2*n-1; // [l, r]
	while(l < r)
	{
		int mid = (l + r) / 2;
		if(nodes[mid].num < new_num) l = mid + 1;
		else r = mid;
	}
	return composite_indexes[new_num] = l;
}
int main()
{
	memset(composite_indexes, -1, sizeof(composite_indexes));
    sift(maxp);
    scanf("%d", &n);
    for(int i = 0;i < 2*n;i++)
	{
		scanf("%d", &nodes[i].num);
		nodes[i].used = 0;
	}
	sort(nodes, nodes + 2*n, cmp);
	int last_prime = 2*n-1, index_of_ans = 0; // last is also an INDEX!
	// for composite isn't always monotonous, we can't use last_composite!
	for(int i = 2*n-1;i >= 0;i--)
	{
		if(nodes[i].used) continue;
		if(is_prime(nodes[i].num)){
			while(last_prime >= 0) // robust
			{
				int last_prime_in = last_prime;
				while(nodes[last_prime].used)
					last_prime--;
				while(!is_prime(nodes[last_prime].num))
					last_prime--;
				while(nodes[last_prime].num >= 200000) // caution
					last_prime--;
				while(primes[nodes[last_prime].num] > nodes[i].num)
					last_prime--;
				if(last_prime == last_prime_in) break;
			}
			ans[index_of_ans++] = nodes[last_prime].num;
			nodes[last_prime].used = 1;
		}else{
			int new_num = nodes[i].num / min_prime_factor[nodes[i].num];
			int composite_index = find_composite_index(new_num);
			ans[index_of_ans++] = nodes[i].num;
			nodes[composite_index].used = 1;
		}
	}
	for(int i = 0;i < n;i++)
		printf("%d ", ans[i]);
    return 0;
}
