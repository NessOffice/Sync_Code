#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 1e5 + 5;
struct Node
{
    vector<char> word;
    int num_of_vowel;
    char last_vowel;
}nodes[maxn];
char str_temp[10*maxn];
int cnt_first = 0, cnt_second = 0;
int ans_first[maxn][2], ans_second[maxn][2]; // first for first WORD, not first line
int vis[maxn];
bool cmp(const Node& lhs, const Node& rhs)
{
    return (lhs.num_of_vowel < rhs.num_of_vowel
    || (lhs.num_of_vowel == rhs.num_of_vowel && lhs.last_vowel < rhs.last_vowel));
}
void print_word(int index)
{
    for(int i = 0, len = nodes[index].word.size();i < len;i++)
        putchar(nodes[index].word[i]);
}
int main()
{
    memset(vis, 0, sizeof(vis));
    int n;
    scanf("%d", &n);
    for(int i = 0;i < n;i++)
    {
        scanf("%s", str_temp);
        nodes[i].num_of_vowel = 0;
        for(int j = 0, len = strlen(str_temp);j < len;j++)
        {
            char ch = str_temp[j];
            nodes[i].word.push_back(ch);
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            {
                nodes[i].num_of_vowel++;
                nodes[i].last_vowel = ch;
            }
        }
    }
    sort(nodes, nodes + n, cmp);
    for(int i = 0;i < n-1;i++)
    {
        if(vis[i]) continue;
        if(nodes[i+1].num_of_vowel == nodes[i].num_of_vowel) // find the nearest!
        if(nodes[i+1].last_vowel == nodes[i].last_vowel)
        {
            vis[i] = vis[i+1] = 1;
            ans_second[cnt_second][0] = i;
            ans_second[cnt_second][1] = i+1;
            cnt_second++;
        }
    }
    int last = 0;
    for(int i = 0;i < n-1;i++)
    {
        if(vis[i]) continue;
        while(last <= i) last++;
        while(last < n && vis[last]) last++;
        if(last < n && nodes[last].num_of_vowel == nodes[i].num_of_vowel)
        {
            vis[i] = vis[last] = 1;
            ans_first[cnt_first][0] = i;
            ans_first[cnt_first][1] = last;
            cnt_first++;
        }
    }
    int m = (cnt_first >= cnt_second ? cnt_second : (cnt_first + (cnt_second - cnt_first) / 2));
    printf("%d\n", m);
    for(int i = 0;i < min(cnt_first, cnt_second);i++)
    {
        int index_first1 = ans_first[i][0];
        int index_first2 = ans_first[i][1];
        int index_second1 = ans_second[i][0];
        int index_second2 = ans_second[i][1];
        print_word(index_first1);
        putchar(' ');
        print_word(index_second1);
        putchar('\n');
        print_word(index_first2);
        putchar(' ');
        print_word(index_second2);
        putchar('\n');
    }
    for(int i = cnt_first;i+1 < cnt_second;i += 2)
    {
        int index_first1 = ans_second[i][0];
        int index_first2 = ans_second[i][1];
        int index_second1 = ans_second[i+1][0];
        int index_second2 = ans_second[i+1][1];
        print_word(index_first1);
        putchar(' ');
        print_word(index_second1);
        putchar('\n');
        print_word(index_first2);
        putchar(' ');
        print_word(index_second2);
        putchar('\n');
    }
    return 0;
}