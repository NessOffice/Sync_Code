#include <stdio.h>
#include <math.h>
int main()
{
	int T, Len, N;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &N);
		scanf("%d", &Len);
		int memory = 0, m, m_max = 0, m_min;
		char var[10];
		for(int i = 0;i < N;i++)
		{
			scanf("%s", var);
			switch(var[0])
			{
				case 'B':m_min = m = 1;break;
				case 'W':m_min = m = 2;break;
				case 'D':m_min = m = 4;break;
				case 'Q':m_min = m = 8;break;
			}
			memory += m;
			if(m > m_max) m_max = m;
			if(Len != -1 && Len < m) m_min = Len;
			if(memory % m_min) memory = (memory/m_min+1) * m_min;
		}
		if(Len != -1) m_max = Len;
		if(memory % m_max) memory = (memory/m_max+1) * m_max;
		printf("%d\n", memory);
	}
	return 0;
}
