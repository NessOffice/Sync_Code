#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int f[35000];
int v[70][5], vw[70][5], isMaster[70];
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	memset(v, 0, sizeof(v));
	memset(vw, 0, sizeof(vw));
	memset(isMaster, 0, sizeof(isMaster));
	for(int i = 1;i <= m;i++)
	{
		int temp_v, temp_w, master;
		scanf("%d%d%d", &temp_v, &temp_w, &master);
		if(master){
			if(v[master][2]){
				v[master][3] = v[master][1] + temp_v;
				vw[master][3] = vw[master][1] + temp_v * temp_w;
				v[master][4] = v[master][2] + temp_v;
				vw[master][4] = vw[master][2] + temp_v * temp_w;
			}else{
				v[master][2] = v[master][1] + temp_v;
				vw[master][2] = vw[master][1] + temp_v * temp_w;
			}
		}else{
			isMaster[i] = 1;
			v[i][1] = temp_v;
			vw[i][1] = temp_v * temp_w;
		}
	}
	for(int i = 1;i <= m;i++)
	{
		if(!isMaster[i]) continue;
		for(int j = n;j >= v[i][1];j--)
			for(int k = 1;k <= 4;k++)
				if(j >= v[i][k]) f[j] = max(f[j], f[j-v[i][k]] + vw[i][k]);
	}
	printf("%d\n", f[n]);
	return 0;
}
