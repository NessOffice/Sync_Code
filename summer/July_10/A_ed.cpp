#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
using namespace std;
#define re register int
const int maxn = 1e6 + 5;
int s1[maxn], s2[maxn];
int jump[maxn], nxt[maxn];
int n, m;
int main()
{
    scanf("%d%d", &n, &m);
    for(re i = 0;i < n;i++)
        scanf("%d", s1 + i);
    for(re i = 0;i < m;i++)
        scanf("%d", s2 + i);
    map<int, int> last;
    for(re i = 0;i < m;i++)
    {
        int jmp = 0;
        if(last.count(s2[i]))
            jmp = i - last[s2[i]];
        last[s2[i]] = i;
        jump[i] = jmp;
    }
    deque<int> pattern;
    for(re i = 0;i < m;i++)
        pattern.push_back(jump[i]);
    map<deque<int>, int> hash_table;
    hash_table[pattern] = 1;
    memset(jump, 0, sizeof(jump));
    memset(nxt, 0, sizeof(nxt));
    last.clear();
    for(re i = 0;i < n;i++)
    {
        int jmp = 0;
        if(last.count(s1[i]))
        {
            jmp = i - last[s1[i]];
            nxt[last[s1[i]]] = i;
        }
        last[s1[i]] = i;
        jump[i] = jmp;
    }
    int cnt = 0;
    deque<int> text;
    for(re i = 0;i < m;i++)
        text.push_back(jump[i]);
    for(re i = m;i < n;i++)
    {
        if(hash_table.count(text)) cnt++;
        if(nxt[i-m]) text[nxt[i-m]-i+m] = 0;
        text.pop_front();
        text.push_back(jump[i]);
    }
    if(hash_table.count(text)) cnt++;
    printf("%d\n", cnt);
    return 0;
}
