#include <cstdio>
#include <set>
using namespace std;
const int maxn = 200000 + 10;
int T, n, head[maxn], tail[maxn], data[maxn];
struct Member{
	int data, tail;
	Member(int data, int tail):data(data), tail(tail){}
	bool operator < (const Member& rhs) const{return data < rhs.data;}
};
set<Member> s;
int main()
{
//	 freopen("in.txt", "r", stdin);
//	 freopen("out.txt", "w", stdout);
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for(int i = 0;i < n;i++)
			scanf("%d", &data[i]);
		if(n == 1){printf("1\n");continue;}
		tail[0] = head[n-1] = 1;
		for(int i = 1;i < n;i++)
		{
			if(data[i] > data[i-1]) tail[i] = tail[i-1]+1;
			else tail[i] = 1;
		}
		for(int i = n-2;i >= 0;i--)
		{
			if(data[i] < data[i+1]) head[i] = head[i+1]+1;
			else head[i] = 1;
		}
		s.clear();
		s.insert(Member(data[0], tail[0]));
		int ans = 1;
		for(int i = 1;i < n;i++)
		{
			bool keep = true;
			Member m(data[i], tail[i]);
			set<Member>::iterator it = s.lower_bound(m);
			if(it != s.begin())
			{
				Member last = *(--it);
				if(head[i] + last.tail > ans) ans = head[i] + last.tail;
				if(last.tail >= m.tail) keep = false;
			}
			if(keep)
			{
				s.erase(m);//erase in set?
				s.insert(m);
				it = s.find(m);
				it++;
				while(it != s.end() && it->tail <= m.tail) s.erase(it++);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
