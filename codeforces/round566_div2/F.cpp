#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL maxn = 1e5 + 5;
struct Node{LL g, index;}nodes_origin[maxn], nodes[maxn];
// struct Node{LL g, index;}nodes[maxn];
bool cmp(const Node& lhs, const Node& rhs)
{
    return lhs.g < rhs.g || (lhs.g == rhs.g && lhs.index < rhs.index);
}
int main()
{
    LL T;
    scanf("%lld", &T);
    while(T--)
    {
        LL a, b, p, q;
        scanf("%lld%lld%lld%lld", &a, &b, &p, &q);
        LL p2 = p*2, q2 = q*2; // p2 for 2*p
        LL t = sqrt(b - a) + 1; // the length of each sub-region
        for(LL i = 0;i < t;i++)
        {
            nodes_origin[i].g = p2*(a+i) % q2;
            nodes_origin[i].index = i;
        }
        // {
        //     nodes[a + i].g = p2*(a + i) % q2;
        //     nodes[a + i].index = i;
        // }
        sort(nodes_origin, nodes_origin + t, cmp);
        // sort(nodes + a, nodes + a + t, cmp);
        nodes[0] = nodes_origin[0];
        LL cnt = 1;
        for(LL i = 0;i < t;i++)
        {
            if(nodes_origin[i].g == nodes[cnt-1].g) continue;
            nodes[cnt] = nodes_origin[i];
            cnt++;
        }
        LL ans_diff = q2*2, ans_index;
        for(LL i = 0;i < t;i++)
        {
            LL target = (q - p2*t*i) % q2;
            target = (target + q2) % q2;

            LL l = 0, r = cnt-1;
            while(l < r)
            {
                LL mid = (l + r) / 2;
                if(nodes[mid].g >= target)
                    r = mid;
                else
                    l = mid + 1;
            }
            if(abs(nodes[l].g - target) < ans_diff && (nodes[l].index + i*t + a <= b))
            {
                ans_index = a + nodes[l].index + i*t;
                ans_diff = abs(nodes[l].g - target);
            }
            if(l < cnt-1 && abs(nodes[l + 1].g - target) < ans_diff && (nodes[l + 1].index + i*t + a <= b))
            {
                ans_index = a + nodes[l + 1].index + i*t;
                ans_diff = abs(nodes[l + 1].g - target);
            }
            // LL l = 0, r = t - 1;
            // while(l < r - 1)
            // {
            //     LL mid = (l + r) / 2;
            //     if(nodes[mid].g >= target)
            //         r = mid;
            //     else
            //         l = mid + 1;
            // }
            // if(abs(nodes[l].g - target) > abs(nodes[r].g - target))
            //     l = r;
            // if(abs(nodes[l].g - target) < ans_diff && (nodes[l].index + i*t + a <= b))
            // {
            //     ans_index = a + nodes[l].index + i*t;
            //     ans_diff = abs(nodes[l].g - target);
            // }
        }
        printf("%lld\n", ans_index);
    }
    return 0;
}

/*
3
17 86 389 995
0 3 1 3
1 9 7 9

 */