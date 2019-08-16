#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
#define re register int
const int maxn = 2e3 + 5; // caution
int s1[maxn], s2[maxn];
int kmp[maxn];
int jump[maxn], nxt[maxn];
int n, m;
int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 0;i < n;i++)
        scanf("%d", s1 + i);
    for(int i = 0;i < m;i++)
        scanf("%d", s2 + i);
    map<int, int> last;
    for(int i = 0;i < m;i++)
    {
        int jmp = 0;
        if(last.count(s2[i]))
            jmp = i - last[s2[i]];
        last[s2[i]] = i;
        jump[i] = jmp;
    }
    jump[m] = -1;
    last.clear();
    for(int i = 0;i < n;i++)
    {
        int jmp = 0;
        if(last.count(s1[i]))
        {
            jmp = m+1+i - last[s1[i]];
            nxt[last[s1[i]]] = m+1+i;
        }
        last[s1[i]] = m+1+i;
        jump[m+1+i] = jmp;
    }
	kmp[0] = 0;
    int cnt = 0;
	for(re i = 1;i < m+n+1;i++)
	{
        if(i - m > m && nxt[i-m])
                jump[nxt[i-m]] = 0;
		int j = kmp[i-1];
		while(j && jump[i] != jump[j]) j = kmp[j-1];
		if(jump[i] == jump[j]) j++;
		kmp[i] = j;
		if(i > m && kmp[i] == m)
            cnt++;
	}
    printf("%d\n", cnt);
    return 0;
}
