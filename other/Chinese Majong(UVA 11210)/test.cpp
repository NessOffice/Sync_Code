#include <stdio.h>
#include <string.h>
char pieceReceived[14][6],num=0;
int divide[12][6]={{2,2,3,3,3},{2,3,2,3,3},{2,3,3,2,3},{2,3,3,3,2},
				   {3,2,2,3,3},{3,2,3,2,3},{3,2,3,3,2},
				   {3,3,2,2,3},{3,3,2,3,2},
				   {3,3,3,2,2}};
struct piece{
	char content[6];
	int ok;
}pieceResult[36];
int StringCmp(char a[],char b[])
{
	int len1=strlen(a),len2=strlen(b);
	if(len1!=len2) return 0;
	for(int i=0;i<len1;i++)
	{
		if(a[i]!=b[i]) 
			return 0;
	}
	return 1;
}
int Sequence(int i,int num)
{
	if(pieceReceived[i][0]>'9') return 0;
	for(int j=1;j<num;j++)
		if(pieceReceived[i][0]!=pieceReceived[i+j][0]-j) return 0;
	for(int j=1;j<num;j++)	
		if(pieceReceived[i][1]!=pieceReceived[i+j][1]) return 0;
	return 1; 
}
int same(int i,int num)
{
	for(int j=1;j<num;j++)
		if(StringCmp(pieceReceived[i],pieceReceived[i+j])==0) return 0;
	return 1;
}
int Divide1()
{
	int flag=0,flag2;
	for(int j=0;j<=12;j+=3)
	{
		flag2=1;
		for(int i=0;i<=10 && flag2;i+=3)
		{
			if(i==j) i++;
			if(!Sequence(i,3) && !same(i,3)) flag2=0;
		}
		if(flag2)
		{
			printf(" %s",pieceReceived[j]);
			flag=1;
		}
	}
	return flag;
} 
int Divide2()
{
	int flag=0,flag2,k,i;
	for(int j=0;j<10;j++)
	{
		flag2=1;i=0;
		for(int k=0;k<5 && flag2;k++)
		{
			if(!Sequence(i,divide[j][k]) && !same(i,divide[j][k])) flag2=0;
			if(divide[j][k]==2 && Sequence(i,divide[j][k]) && flag2) flag2++;
			if(flag2>2) flag2=0;
			i+=divide[j][k];
		}
		if(flag2)
		{
			i=0;
			for(int k=0;k<5;k++)
			{
				i+=divide[j][k];
				if(divide[j][k]==2 && Sequence(i,divide[j][k]))
				{
					//if(pieceReceived[i][0]!=1)
				}
			}
			flag=1;
		}
	}
	return flag;
}
int main()
{
	for(int i=0;i<9;i++)
	{
		pieceResult[i].content[0]='1'+i;
		pieceResult[i].content[1]='T';
		pieceResult[i].content[2]='\0';
		pieceResult[i+9].content[0]='1'+i;
		pieceResult[i+9].content[1]='S';
		pieceResult[i+9].content[2]='\0';
	}
	int kase=1;
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	while(scanf("%s",pieceReceived[0]) && pieceReceived[0][0]!='0')
	{
		for(int i=1;i<13;i++)
			scanf("%s",pieceReceived[i]);
		printf("Case %d:",kase++);
		if(Divide1()==0 && Divide2()==0)
			printf(" Not Ready");
		printf("\n");
	}
	return 0;
}
