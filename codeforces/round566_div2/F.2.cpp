#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL maxn = 1e5 + 5;
struct Node{LL g, index;}nodes_origin[maxn], nodes[maxn];
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
        sort(nodes_origin, nodes_origin + t, cmp);
        nodes[0] = nodes_origin[0];
        LL cnt = 1;
        for(LL i = 0;i < t;i++)
        {
            if(nodes_origin[i].g == nodes[cnt-1].g) continue;
            nodes[cnt] = nodes_origin[i];
            cnt++;
        }
        LL ans_diff = q2*2, ans_index;
        for(LL i = 0;;i++)
        {
            LL target = (q - p2*t*i) % q2;
            target = (target + q2) % q2;

            if(a + i*t > b) break;
            LL l = 0, r = cnt-1, last_region = 0;
            if(r + i*t + a > b) // caution!
            {
                last_region = 1;
                for(l = 0;l < cnt;l++)
                    if(abs(nodes[l].g - target) < ans_diff && (nodes[l].index + i*t + a <= b))
                    {
                        ans_index = a + nodes[l].index + i*t;
                        ans_diff = abs(nodes[l].g - target);
                    }
            }
            if(last_region) continue;
            while(l < r-1) // g[l] is the biggest one which < target among g[0...cnt]
            {
                LL mid = (l + r) / 2;
                if(nodes[mid].g >= target)
                    r = mid;
                else
                    l = mid;
            }
            if(abs(nodes[l].g - target) < ans_diff && (nodes[l].index + i*t + a <= b))
            {
                ans_index = a + nodes[l].index + i*t;
                ans_diff = abs(nodes[l].g - target);
            }
            if(abs(nodes[r].g - target) < ans_diff && (nodes[r].index + i*t + a <= b))
            {
                ans_index = a + nodes[r].index + i*t;
                ans_diff = abs(nodes[r].g - target);
            }
        }
        printf("%lld\n", ans_index);
    }
    return 0;
}

/*
100

456 997 97367 97231

240 860 89209 76697

311 900 80909 80039

13 680 77447 91397

152 732 66973 96731

173 984 72461 51347

17 854 76207 80789

145 993 75679 69313

436 940 60317 98297 // caution!

376 951 81097 79481

388 947 70537 56081

487 992 67979 73939

139 774 71563 97943

356 946 91097 72889 // caution!

38 776 54049 63901

397 981 57107 93629

229 815 65713 83299

112 744 69557 83903

17 86 389 995
0 3 1 3
1 9 7 9


*/