#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<algorithm>
using namespace std;
char order[10000];
char a[6][6];
void swap(char &a,char &b)
{
    char c;
    c=a;
    a=b;
    b=c;
}
int main()
{
	freopen("in.txt","r",stdin);
	int kase=0;
	while(true)
	{
		for(int i=0;i<5;i++)
        {
            gets(a[i]);
            if(a[0][0]=='Z')
            return 0;
        }
        if(kase>0)
          cout<<endl;
        int x,y;
        bool f=true;
		for(int i=0;i<5;i++)
		    for(int j=0;j<5;j++)
				if(a[i][j]==' ')
				{
					x=i;
					y=j;
				}
		/*for(int i=0;i<5;i++)
		{
    		   for(int j=0;j<5;j++)
    		      printf("%c",a[i][j]);
			    printf("\n");
		}
		printf("%d %d\n",x,y);*/
		int p=0;
        char now;
        while((now=getchar())!='0')
        order[p++]=now;
        getchar();
		for(int i=0;i<p;i++){
				if(order[i]=='A')
				{
					if(x>0)
					{
						swap(a[x-1][y],a[x][y]);
						x--;
					}
					else
					{
						f=false;
						break;
					}
				}
				if(order[i]=='B')
				{
					if(x<4)
					{
						swap(a[x+1][y],a[x][y]);
						x++;
					}
					else
					{
						f=false;
						break;
					}
				}
				if(order[i]=='L')
				{
					if(y>0)
					{
						swap(a[x][y-1],a[x][y]);
						y--;
					}
					else
					{
						f=false;
						break;
					}
				}
				if(order[i]=='R')
				{
					if(y<4)
					{
						swap(a[x][y],a[x][y+1]);
						y++;
					}
					else
					{
						f=false;
						break;
					}
				}
		}
		printf("Puzzle #%d:\n",++kase);
		if(f)
		{
    		for(int i=0;i<=4;i++)
    		{
    		   for(int j=0;j<=3;j++)
    		      printf("%c ",a[i][j]);
    			printf("%c\n",a[i][4]);
			}
		}
		else
		    printf("This puzzle has no final configuration.\n"); 
	} 
	return 0;
}
