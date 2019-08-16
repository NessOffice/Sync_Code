#include <cstdio>
#include <cstring>
const int maxn = 60;
const int sz_of_stgy = 8;
int stgy[sz_of_stgy][4]; // stgy for strategy
bool SG[maxn][maxn][maxn][maxn];
void calc_SG()
{
	for(int i4 = 0;i4 < maxn-15;i4++) // from inner to outer
	for(int i3 = 0;i3 < maxn-10;i3++)
    for(int i2 = 0;i2 < maxn-5;i2++)
    for(int i1 = 0;i1 < maxn;i1++)
	{
		for(int j = 0;j < sz_of_stgy && SG[i1][i2][i3][i4] == false;j++)
        {
			if(i1 >= stgy[j][0])
			if(i2 >= stgy[j][1])
			if(i3 >= stgy[j][2])
			if(i4 >= stgy[j][3])
				if(SG[i1-stgy[j][0]][i2-stgy[j][1]][i3-stgy[j][2]][i4-stgy[j][3]] == 0)
					SG[i1][i2][i3][i4] = true;
        }
	}
}
void calc_stgy()
{
	stgy[0][0] =  1, stgy[0][1] =  0, stgy[0][2] =  0, stgy[0][3] = 0;

    stgy[1][0] =  0, stgy[1][1] =  2, stgy[1][2] =  0, stgy[1][3] = 0;
    stgy[2][0] = -2, stgy[2][1] =  1, stgy[2][2] =  0, stgy[2][3] = 0;

    stgy[3][0] =  0, stgy[3][1] =  0, stgy[3][2] =  3, stgy[3][3] = 0;
    stgy[4][0] = -1, stgy[4][1] = -1, stgy[4][2] =  1, stgy[4][3] = 0;
	// stgy[4][0] = 999, stgy[4][1] = -1, stgy[4][2] =  1, stgy[4][3] = 0;

	stgy[5][0] =  0, stgy[5][1] =  0, stgy[5][2] =  0, stgy[5][3] = 4;
    stgy[6][0] =  0, stgy[6][1] = -2, stgy[6][2] =  0, stgy[6][3] = 1;
	stgy[7][0] = -1, stgy[7][1] =  0, stgy[7][2] = -1, stgy[7][3] = 1;
	// stgy[7][0] = 999, stgy[7][1] =  0, stgy[7][2] = -1, stgy[7][3] = 1;
}
int main()
{
	calc_stgy();
	calc_SG();
	int n = 10;
	for(int i1 = 0;i1 < n;i1++)
	for(int i2 = 0;i2 < n;i2++)
	for(int i3 = 0;i3 < n;i3++)
	for(int i4 = 0;i4 < 20;i4++)
		if(SG[i1][i2][i3][i4] == false)
			printf("a:%d b:%d c:%d d:%d\n", i1, i2, i3, i4);
			// printf("a:%d b:%d c:%d d:%d, %s\n", i1, i2, i3, i4, SG[i1][i2][i3][i4] ? "N place" : "P place");
	return 0;
}
