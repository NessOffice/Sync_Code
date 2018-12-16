#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
    int abc, def, ghi;
    for (abc = 123; abc<=329; ++abc)
    {
        bool visit[10] = {false}; //统计0~9是否出现
        //标记abc各位
        visit[abc/100] = visit[abc/10%10] = visit[abc%10] = true;
        //标记def各位
        def = 2*abc;
        visit[def/100] = visit[def/10%10] = visit[def%10] = true;
        //标记ghi各位
        ghi = 3*abc;
        visit[ghi/100] = visit[ghi/10%10] = visit[ghi%10] = true;
        //检查完全性
        bool flag = true;
        for (int i = 1; i<=9; ++i)
            if (visit[i] != true)
            {
                flag = false;
                break;
            }
        if (flag)
            cout << abc << ' ' << def << ' ' << ghi << endl;
    }
    return 0;
}
